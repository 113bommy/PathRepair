#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


ll H, W;

ll calc(ll a, ll b, ll c){
  ll mi = min(a, b); mi = min(mi, c);
  ll ma = max(a, b); ma = max(ma, c);
  return ma - mi;
}

ll divi(ll h, ll w){
  ll ans = (ll)1e9;
  if(h >= 3){
    ans = min(ans, (h%3?w:0));
  }
  
  ll a = (w / 3) * h;
  ll b = (w - (a / h)) * (h / 2);
  
  ans = min(ans, calc(a, b, h * w - a - b));
  
  a += h;
  b = (w - (a / h)) * (h / 2);
  ans = min(ans, calc(a, b, h * w - a - b));
  return ans;
}

int main(){
  cin >> H >> W;
  ll ans = 1e9;
  ans = min(ans, divi(H, W));
  ans = min(ans, divi(W, H));
  cout << ans<< endl;
}
