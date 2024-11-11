#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,d;
  cin>>n>>d;
  while(n--)
  {
    ll x,y,c=0;
    cin>>x>>y;
    if(sqrt((x*x)+(y*y))>=d)
      c++;
  }
  cout<<c;
}