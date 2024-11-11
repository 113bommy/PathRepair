#include<iostream>
using namespace std; 
 
 
int main()
{
int a,b,c,d;
cin >> a >> b >> c >> d;
if(a+b == c+d){printf("Balanced")}
else{
if(a+b > c+d){printf("Right")}
else{printf("left")};
}