#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
ll n,m;
cin>>n>>m;
ll x=0,y=0,a,j=n*(-1)+1;
for(int i=0;i<n;i++){
cin>>a;
x+=a*j;
j+=2;
}
x%=1000000007;
j=m*(-1)+1;
for(int i=0;i<m;i++){
cin>>a;
y+=a*j;
j+=2;
}
y%=1000000007;
cout<<x*y%1000000007;
}