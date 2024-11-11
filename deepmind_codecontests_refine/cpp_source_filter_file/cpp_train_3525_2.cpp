#include<iostream>
using namespace std;
using ll=long long;
ll n,a[2000],b[2000],ans,x,y;
int i;
int main(){
cin>>n;
while(i<n)cin>>a[i]>>b[i],++i;

x=y=1;i=0;
while(i<n){
ll r=max((x+a[i]-1)/a[i],y+b[i]-1)/b[i]));
x=a[i]*r,y=b[i]*r;
}ans=x+y;
cout<<ans<<endl;
return 0;
}