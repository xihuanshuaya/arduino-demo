/*
   sr-04 demo
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
const int ledPin = 13;
const int echoPin = 3;
const int triggerPin = 2;
const int maxTime=100000; //micorseconds


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(ledPin, OUTPUT); 
  pinMode(echoPin,INPUT);
  pinMode(triggerPin,OUTPUT); 
  Serial.begin(9600);  
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(ledPin, LOW);   // turn the LED on (HIGH is the voltage level)
  
  digitalWrite(triggerPin,LOW);  
  delayMicroseconds(50);
  digitalWrite(triggerPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin,LOW);
  digitalWrite(ledPin, HIGH);
  delayMicroseconds(10);
  Serial.println("trigger the sr04");
  unsigned long time = pulseIn(echoPin,HIGH);
  if(time == 0 ){
    Serial.println("no signal received");
  }
  
  if(time > maxTime){
    Serial.println("out of range.");
  }
  int speedMPS =340; //m/sp
  int speedMMPerMS = 340;
  float speedMMPerUS = 0.34;
//  int usSpeed
  Serial.println(time);
  
  float distence = (time * speedMMPerUS ) / 2; //mm
  Serial.print(distence/10); //cm
  Serial.println("cm.");
    
  delay(2000);               // wait for a second
}
