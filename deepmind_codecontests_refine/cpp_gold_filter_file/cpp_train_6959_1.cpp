#include<bits/stdc++.h>   
using namespace std;
long long n,a,b,i,j,ans,m;
int main() {
cin>>n;
for(i=1;i*i<=n;i++)
{
if(n%i!=0) 
{continue;}
a=i;
b=n/i;
m=max(a,b);
j=0;
while(m!=0){
m=m/10; j++;} 
m=j;}
cout<<m;
return 0;
}  	
