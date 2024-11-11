#include <iostream>
#include <string>
using namespace std;
int main(){
int a;
int b;
int c;
int d;
int e;
int f;
int g;
int h;
int i;
int j;
g=0;
while(g<3){
cin >>a;
cin >>b;
cin >>c;
cin >>d;
cin >>e;
cin >>f;
if(c>f){f=f+60; e=e-1;}
if(b>e){e=e+60; d=d-1;}
h=d-a;
i=e-b;
j=f-c;
cout <<h<<" "<<i<<" "<<j<<endl;
g=g+1;}