#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
ll n,i,j,k,s;
cin>>n;
s=0;
vector<ll> a(n+1),b(n+1);
for(i=1;i<=n;i++){
    cin>>j;
    b[i]=j+b[i-1];
}
ll d=2e9+1;
for(i=1;i<=n-1;i++){
    d=min(d,abs(b[n]-2*b[i]));
}
cout<<d;

}