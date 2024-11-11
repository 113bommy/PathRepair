#include<bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;

signed main() {
  int n, k; cin >> n >> k;
  vector<ll> v(n); rep(i, n) cin >> v[i];

  ll ans = 1e9;
  rep(i, n-k+1) {
    ans = min(ans, v[i+k-1] - v[i] + min(abs(v[i]), abs(v[i+k-1])));
  }
  cout << ans << endl;
}
