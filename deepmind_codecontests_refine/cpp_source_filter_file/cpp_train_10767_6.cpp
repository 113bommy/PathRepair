#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, M = 100 + 7;
const long long MOD = 1e9 + 7;
int n, m, k, t;
long long a[N], _dp[N][M], C[N][M];
int main() {
  scanf("%d%d", &n, &m);
  C[0][0] = 1;
  for (int i = 1; i < N; _dp[i][0] = 0, C[i][0] = 1, i++)
    for (int j = 1; j <= min(i, M - 1); j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD, _dp[i][j] = 0;
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  int l, r;
  for (int i = 1; i <= m; i++) {
    scanf("%d %d %d", &l, &r, &k);
    _dp[l][k] = (_dp[l][k] + 1) % MOD;
    for (int j = 0; j <= k; j++)
      _dp[r + 1][j] = (_dp[r + 1][k] - C[r - l + k - j][k - j] + MOD) % MOD;
  }
  for (int j = 100; j >= 0; j--)
    for (int i = 1; i <= n; i++)
      _dp[i][j] = (_dp[i][j] + _dp[i][j + 1] + _dp[i - 1][j]) % MOD;
  for (int i = 1; i <= n; i++) printf("%lld ", (a[i] + _dp[i][0]) % MOD);
  return 0;
}
