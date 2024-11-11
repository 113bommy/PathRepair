#include<bits/stdc++.h>
#define ll long long
using namesapce std;
int main(){
  ll n,l,c=0;
  cin>>n>>l;
  while(n--){
	ll x,y;
    cin>>x>>y;
    if(l*l==x*x+y*y)c++;
  }
  cout<<c;
  return 0;
}
