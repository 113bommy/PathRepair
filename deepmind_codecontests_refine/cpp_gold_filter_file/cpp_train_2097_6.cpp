#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000 * 1000 * 1000 + 7;
long long mod(long long n) { return (n % MOD + MOD) % MOD; }
const long long N = 107;
long long dp[N][N];
long long res[N][N];
long long tmp[N][N];
void mult(long long a[N][N], long long b[N][N]) {
  for (long long i = 0; i < N; ++i)
    for (long long j = 0; j < N; ++j) tmp[i][j] = 0;
  for (long long i = 0; i < N; ++i) {
    for (long long j = 0; j < N; ++j) {
      for (long long k = 0; k < N; ++k) {
        tmp[i][j] += a[i][k] * b[k][j];
        tmp[i][j] %= MOD;
      }
    }
  }
  for (long long i = 0; i < N; ++i)
    for (long long j = 0; j < N; ++j) a[i][j] = tmp[i][j];
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(20);
  long long n, m;
  cin >> n >> m;
  for (long long i = 0; i < N; ++i) {
    res[i][i] = 1;
  }
  for (long long i = 0; i < N; ++i) {
    if (i + 1 < N) {
      dp[i][i + 1] = 1;
    }
  }
  dp[0][0] = 1;
  dp[m - 1][0] = 1;
  for (long long p = 0; (1ll << p) <= n; ++p) {
    if ((n >> p) & 1) {
      mult(res, dp);
    }
    mult(dp, dp);
  }
  cout << res[0][0] << '\n';
}
