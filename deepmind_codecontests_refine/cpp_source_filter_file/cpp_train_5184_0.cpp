#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(auto& i : a) cin >> i;
  ll ans = 1;
  vector<ll> cnt(3);
  for(auto& A : a){
    ll cnt = 0;
    for(auto& i : cnt) if(i == A) cnt++;
    ans *= cnt;
    ans %= MOD;
    for(auto& i : cnt) if(i == A){
      i++;
      break;
    }
  }
  cout << ans << endl;
}