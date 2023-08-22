int S_A = 5;  
int M_A1 = 1; 
int M_A2 = 2; 
int M_B1 = 3; 
int M_B2 = 4; 
int S_B = 6; 

int Ls = A1 ; 
int L =A2;
int M = A3; 
int R = A4; 
int Rs =A5 ;
int D =A0;

void setup() 
{
pinMode(M_B1, OUTPUT);
pinMode(M_B2, OUTPUT);
pinMode(M_A1, OUTPUT);
pinMode(M_A2, OUTPUT);
pinMode(S_B, OUTPUT);
pinMode(S_A, OUTPUT);

pinMode(L, INPUT);
pinMode(M, INPUT);
pinMode(R, INPUT);
pinMode(Rs, INPUT);
pinMode(Ls, INPUT);
pinMode(D, INPUT);
}

void forword(){
analogWrite(S_A, 200); 
analogWrite(S_B, 200);
digitalWrite(M_A1, LOW);
digitalWrite(M_A2, HIGH);
digitalWrite(M_B1, LOW);
digitalWrite(M_B2, HIGH);  
}
void Back(){
analogWrite(S_A, 125); 
analogWrite(S_B, 125);
digitalWrite(M_A1, HIGH);
digitalWrite(M_A2, LOW);
digitalWrite(M_B1, HIGH);
digitalWrite(M_B2, LOW);  
}
void turnLeft(){
analogWrite(S_B, 200);
analogWrite(S_A, 150);
digitalWrite(M_B1, LOW);
digitalWrite(M_B2, HIGH); 
digitalWrite(M_A1, HIGH);
digitalWrite(M_A2, LOW );
}
void turnRight(){
analogWrite(S_A, 200); 
analogWrite(S_B, 150);
digitalWrite(M_A1, LOW);
digitalWrite(M_A2, HIGH);
digitalWrite(M_B1, HIGH);
digitalWrite(M_B2, LOW);
}
void Stop(){
analogWrite(S_A, 0); 
analogWrite(S_B, 0);
}

void loop()
{  
 int pc = 511;
if ((analogRead(L)  < pc  ) && (analogRead(Ls) < pc) && (analogRead(M) >= pc) && (analogRead(R) < pc) && (analogRead(Rs) < pc) )  {forword();};
if ((analogRead(L) < pc ) && (analogRead(Ls) < pc) && (analogRead(D)  >= pc) && (analogRead(R) < pc) && (analogRead(Rs) < pc) )  {forword();};


if ((analogRead(L) > pc ) &&                                                    (analogRead(R) < pc) && (analogRead(Rs) < pc) )  {turnLeft();};
if (                          (analogRead(Ls)  >= pc) &&                          (analogRead(R) < pc) && (analogRead(Rs) < pc) )  {turnLeft();};

if ((analogRead(L) < pc) &&  (analogRead(Ls) < pc)  &&                         (analogRead(R)  >= pc)                          )  {turnRight();};
if ((analogRead(L) < pc) &&  (analogRead(Ls) < pc)  &&                                                 (analogRead(Rs)  >= pc)  )  {turnRight();};

if ((analogRead(L) < pc )&& (analogRead(Ls) < pc) &&  (analogRead(M) < pc ) && (analogRead(D) < pc) && (analogRead(R) < pc)&& (analogRead(Rs) < pc ) )  {Back();};
}  
