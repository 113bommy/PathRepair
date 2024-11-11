#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
const ll mod = 1000000007;
const ll INF = 1000000099;
vector<ll> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int q;
  cin >> q;
  while (q--) {
    ll n;
    cin >> n;
    vector<pair<ll, ll> > v(n);
    for (ll i = 0; i < (ll)(n); i++) cin >> v[i].first >> v[i].second;
    ll dp[n + 1][3];
    for (ll i = 0; i < (ll)(n + 1); i++)
      for (ll j = 0; j < (ll)(3); j++) {
        dp[i][j] = INF;
      }
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;
    for (int i = 1; i < n + 1; i++) {
      for (ll j = 0; j < (ll)(3); j++) {
        for (ll k = 0; k < (ll)(3); k++) {
          if (i == 1 || v[i - 2].first + j != v[i - 1].first + k) {
            dp[i][k] = min(dp[i][k], dp[i - 1][j] + k * v[i - 1].second);
          }
        }
      }
    }
    cout << min({dp[n][0], dp[n][1], dp[n][2]}) << endl;
  }
}
