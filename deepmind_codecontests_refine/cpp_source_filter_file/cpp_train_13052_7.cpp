#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long double eps = 1e-7;
const int inf = 1000000010;
const long long INF = 10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 1010, LOG = 20;
long long n, m, k, u, v, x, y, t, a, b;
long long dp[MAXN][MAXN];
long long C[MAXN][MAXN], F[MAXN];
long long res[MAXN];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  dp[0][0] = dp[1][0] = 1;
  for (int i = 2; i <= n; i++) {
    dp[i][0] = 1;
    for (int j = 1; 2 * j <= i; j++)
      dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % mod;
  }
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= i; j++)
      res[i] = (res[i] + dp[n][j] * dp[n][i - j]) % mod;
  for (int i = 0; i <= n; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
  }
  F[0] = 1;
  for (int i = 1; i <= n; i++) F[i] = F[i - 1] * i % mod;
  for (int i = 0; i <= n; i++) res[i] = res[i] * F[n - i] % mod;
  for (int i = n; i; i--) {
    for (int j = i + 1; j <= n; j++) res[i] = (res[i] - C[j][i] * res[j]) % mod;
  }
  if (res[k] < 0) res[k] += mod;
  cout << res[k] << '\n';
  return 0;
}
