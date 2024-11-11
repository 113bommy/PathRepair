#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll q;cin>>q;
  for(ll i=0;i<q;i++){
    ll x,y;
    cin>>x>>y;
    if(x>y)swap(x,y);
    long double k=sqrt(x*y-0.75)-x+0.5;
    cout<<(ll)(x-1+k+(x*y-1)/(x+k))-(x!=y)<<endl;
  }
}
