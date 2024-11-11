#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main (){
ll n,a[100009],b[100009],c[100009];
cin>>n;
for(int i=0;i<n;i++)cin>>a[i]>>b[i]>>c[i];
for(int i=1;i<n;i++)
a[i]=max(b[i-1]+a[i],c[i-1]+a[i]),
b[i]=max(c[i-1]+b[i],a[i-1]+b[i]),
c[i]=max(b[i-1]+c[i],a[i-1]+c[i]);
 
cout<<max(max(a[n-1],b[n-1]),c[n-1])<<endl;
 
}