#define trigPin 2
#define echoPin 3

#define ledAzul 7
#define ledVermelho 8
#define ledVerde 12

long duracao;
int distancia;

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(ledAzul, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duracao = pulseIn(echoPin, HIGH);

  distancia = duracao * 0.034 / 2;

  Serial.print("Distancia: ");
  Serial.println(distancia);

  // LONGE
  if (distancia > 20) {

    digitalWrite(ledAzul, HIGH);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledVermelho, LOW);

  }

  // MÉDIO
  else if (distancia > 10) {

    digitalWrite(ledAzul, LOW);
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledVermelho, LOW);

  }

  // PERTO
  else {

    digitalWrite(ledAzul, LOW);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledVermelho, HIGH);

  }

  delay(200);
}
