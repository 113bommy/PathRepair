#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
ll n,k;
cin>>n>>k;
ll a[n];
for(ll  i=0;i<n;i++)
cin>>a[i];
for(ll i=k;i<n;i++)
{
if(a[i]>a[i-k])
cout<<"Yes"<<endl;
else
cout<<"No"<<endl;
}
return 0;
}