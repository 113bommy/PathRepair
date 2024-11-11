#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
main(){
int n,a[1000];
while(1){
cin >>n;
if(n==0) break;
for(int i=0;i<n;i++) cin >>a[i];
int sum=0;
for(int i=0;i<n;i++) sum=sum+a[i];
double m=1.0*sum/n;
double dist=0.0;
for(int i=0;i<n;i++) dist=dist+(m-a[i])*(m-a[i]);
}
printf("%lf\n",sqrt(dist/n));
}