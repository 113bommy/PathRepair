#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
const char df = '\n';
void solve() {
  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = i - 1; j >= 0; j--) {
      for (int k = n - 1; k >= 0; k--) {
        dp[i][k + 1] += dp[j][k];
      }
      if (s[i - 1] == s[j - 1]) break;
    }
  }
  for (int i = 0; i <= n; i++)
    ;
  vector<ll> ar(n + 1);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      ar[j] += dp[i][j];
    }
  }
  ll c = 0;
  ll ct = 0;
  for (ll i = n; i >= 0; i--) {
    ;
    if (ct + ar[i] >= k) {
      cout << c + (n - i) * (k - ct) << df;
      return;
    }
    ct += ar[i];
    c += (n - i) * ar[i];
  }
  cout << -1 << df;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt = 1;
  while (tt--) solve();
  return 0;
}
