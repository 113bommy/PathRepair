#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9 + 10, N = 2e5 + 10, mod = 1e9 + 7, LG = 20;
long long n, m, x, f[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  f[0] = 1;
  for (int i = 1; i < N; i++) f[i] = (f[i - 1] * i) % mod;
  cin >> n >> m >> x;
  x--;
  if (n > m) return cout << 0, 0;
  long long dp[m + 1][n + 1][n + 1];
  memset(dp, 0, sizeof(dp));
  if (x) dp[0][0][0] = 1;
  dp[0][1][0] = dp[0][1][1] = 1;
  for (int i = 1; i < m; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= j; k++) {
        if (i != x) dp[i][j][k] = dp[i - 1][j][k];
        if (j) dp[i][j][k] += dp[i - 1][j - 1][k];
        if (k and i != x) dp[i][j][k] += dp[i - 1][j][k - 1];
        if (j and k) dp[i][j][k] += dp[i - 1][j - 1][k - 1];
        dp[i][j][k] %= mod;
      }
    }
  }
  cout << ((dp[m - 1][n][n] * f[n]) % mod);
}
