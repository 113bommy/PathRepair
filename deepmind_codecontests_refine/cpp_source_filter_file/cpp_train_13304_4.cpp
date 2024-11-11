#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
  ll l,r;
  cin>>l>>r;
  //ll num=r-l+1;
  ll r=min(r,l+2019);
  ll mi=2018*2017;
  for(ll i=l;i<=r;i++)
  {
    for(ll j=i+1;j<=r;j++)
    {
      mi=min(mi,(i*j)%2019);
    }
  }
  cout<<mi<<endl;
}
