#include <bits/stdc++.h>
#pragma GCC optimize("O3")
const long long llinf = LLONG_MAX;
const int inf = INT_MAX;
const int nmax = 2e5 + 5;
const int mod = 1e9 + 7;
using namespace std;
int a, b, k, t, i, j, dp[101][nmax], s[nmax];
long long ans;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cerr.tie(0);
  cout.tie(0);
  cin >> a >> b >> k >> t;
  dp[0][0] = 1;
  for (i = 1; i <= t; i++) {
    for (j = 0; j < nmax; j++)
      s[j] = ((j > 0 ? s[j - 1] : 0) + dp[i - 1][j]) % mod;
    for (j = 0; j < nmax; j++)
      dp[i][j] =
          (s[j] - (j - 2 * k - 1 >= 0 ? s[j - 2 * k - 1] : 0) + mod) % mod;
  }
  for (i = 0; i < nmax; i++) s[i] = ((i > 0 ? s[i - 1] : 0) + dp[t][i]) % mod;
  for (i = 0; i <= 2 * k * t; i++)
    ans = (ans +
           1LL * dp[t][i] * (i - 1 + a - b >= 0 ? s[i - 1 + a - b] : 0) % mod) %
          mod;
  cout << ans << endl;
  return 0;
}
