#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
  	ll n;
    cin>>n;
    ll b=1;
  	while(2*b<=n)b*=2
      cout<<2*b-1<<endl;
}