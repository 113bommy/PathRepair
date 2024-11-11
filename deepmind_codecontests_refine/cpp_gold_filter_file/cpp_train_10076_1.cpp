#include<iostream>
#include<algorithm>
using namespace std;
int main(){
long long int n,a,b,c,d,i;
cin>>n;
c = 9999999999;
d=0;
for(i=0;i<n;i++){
cin>>a;
c = min(a,c);
if(c==a)d++;}
cout<<d<<endl;}