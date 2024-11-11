#include<bits/stdc++.h>
#define ll long long int 
using namespace std;
int main()
{
  ll n;
  cin>>n;
  ll a[n],b[n];
  for(ll i=0;i<n;i++)
  {
    cin>>a[i]>>b[i];
  }
  sort(a,a+n);
  sort(b,b+n);
  if(n%2==0)
  {
    cout<<(b[n/2-1]+b[n/2])/2-(a[n/2-1]-a[n/2])/2+1<<endl
  }
  else
  {
    cout<<b[n/2]-a[n/2]+1<<endl;
  }
  return 0;
}
