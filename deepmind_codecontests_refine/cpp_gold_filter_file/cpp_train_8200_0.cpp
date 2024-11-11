#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
  ll n;
  cin>>n;
  
  
  set<ll>s;
  for(ll i=0,a;i<n;i++)cin>>a,s.insert(a);
  
  cout<<(s.size()==n?"YES":"NO");
  
  
 
  
  
  
  
}
