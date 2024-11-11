#include<iostream>
using namespace std;
 
int main(){
int n, bill;
 
while(cin>>n,~n){
bill = 1150;
n-=10;
if(n<0)n=0;
if(n>10){bill += 125*10; n -= 10;}
else{bill += 125*n; n = 0;}
if(n>10){bill += 140*10; n -= 10;}
else{bill += 140*n; n = 0;}
bill += 160*n;
 
cout<<4280-bill<<endl;
}
 
return 0;
}