#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
typedef vector<ll> vl;
int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cout << fixed << setprecision(10);
  /*--------------------------------*/
  ll q;cin>>q;
  rep(i,q){
    ll x,y;
    cin>>x>>y;
    if(x>y)swap(x,y);
    ll ans=x-1;
    long double k=sqrt(x*y-0.75)-x+0.5;
    ll lk=k;
    ans+=k+(x*y-1)/(x+k);
    if(a[i]==b[i])cout<<ans<<endl;
    else cout<<ans-1<<endl;
  }
}
