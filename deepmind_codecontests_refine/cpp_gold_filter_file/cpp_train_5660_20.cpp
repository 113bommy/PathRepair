#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 200;
long long c[N][N], dp[N][N * N + N], g[N][N];
long long modp(long long a, long long b) {
  if (b == 0) return 1;
  long long u = modp(a, b / 2);
  u = (u * u) % mod;
  if (b & 1) return (a * u) % mod;
  return u;
}
int32_t main() {
  long long n, m, o;
  cin >> n >> m >> o;
  for (long long i = 0; i < N; i++) c[i][0] = dp[i][0] = 1;
  for (long long i = 1; i < N; i++)
    for (long long j = 1; j <= i; j++)
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
  for (long long i = 1; i <= n; i++)
    for (long long j = 0; j <= n; j++) g[i][j] = modp(c[n][j], (m + n - i) / n);
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= n * i; j++)
      for (long long k = max(j - n, 0LL); k <= j; k++) {
        dp[i][j] = (dp[i][j] + dp[i - 1][k] * g[i][j - k]) % mod;
      }
  cout << dp[n][o] << "\n";
}
