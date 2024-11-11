#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll maxn = 1e6 + 6, inf = 1e18 + 1;
ll n, m, m2, md, a[100], dp[75][75][75], tmp[75], DP[75];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> md;
  m2 = m / 2;
  for (ll i = 1; i < md; i++) tmp[i] = -inf;
  for (ll h = 1; h <= n; h++) {
    for (ll i = 0; i <= m; i++) {
      for (ll j = 0; j <= m; j++) {
        for (ll k = 0; k <= md; k++) {
          dp[i][j][k] = -inf;
        }
      }
    }
    dp[0][0][0] = 0;
    for (ll i = 1; i <= m; i++) {
      cin >> a[i];
      for (ll j = 1; j <= min(i, m2); j++) {
        for (ll k = 0; k < md; k++)
          dp[i][j][k] =
              max(dp[i - 1][j][k],
                  a[i] + dp[i - 1][j - 1][(k - a[i] + (md * 1000)) % md]);
        dp[i][0][0] = 0;
      }
    }
    for (ll i = 0; i < md; i++) {
      a[i] = 0;
      for (ll j = 0; j <= m2; j++) a[i] = max(a[i], dp[m][j][i]);
    }
    if (a[0] < 0) a[0] = 0;
    for (ll i = 0; i < md; i++) {
      ll x = tmp[i];
      for (ll j = 0; j < md; j++)
        x = max(x, a[j] + tmp[((i - j + md * 1000) % md)]);
      DP[i] = x;
    }
    for (ll i = 0; i < md; i++) tmp[i] = DP[i];
  }
  cout << tmp[0] << endl;
}
