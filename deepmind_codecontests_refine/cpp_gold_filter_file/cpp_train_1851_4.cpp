#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,d,c=0;
  cin>>n>>d;
  while(n--)
  {
    ll x,y;
    cin>>x>>y;
    if(sqrt((x*x)+(y*y))<=d)
      c++;
  }
  cout<<c;
}