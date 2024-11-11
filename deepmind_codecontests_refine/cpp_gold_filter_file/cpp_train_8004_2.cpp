#include <iostream>
using namespace std;
int main(){
int n;
int m;
cin >>n;
cin >>m;
int a[n];
a[0]=0;
int b;
int c;
b=0;
while(b<n-1){
cin >>c;
a[b+1]=a[b]+c;
b=b+1;}
int e;
e=0;
int d;
d=0;
b=0;
while(b<m){
cin >>c;
if(c>0){e=(e+a[d+c]-a[d])%100000;}
else{e=(e+a[d]-a[d+c])%100000;}
d=d+c;
b=b+1;}
cout <<e<<endl;}