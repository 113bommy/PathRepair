#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long c[101][101];
int cnt[101];
long long dp[101][10005];
long long q0[101], q1[101];
long long qpow(long long a, long long n) {
  if (n == 0) return 1;
  if (n == 1) return a;
  long long r = qpow(a, n >> 1) % MOD;
  r = (r * r) % MOD;
  if (n & 1) r = (r * a) % MOD;
  return r;
}
int main() {
  memset(c, 0, sizeof(c));
  c[0][0] = 1;
  for (int i = 1; i <= 100; ++i) {
    c[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
    }
  }
  long long n, m, k, m_n, mn;
  cin >> n >> m >> k;
  m_n = m / n;
  mn = m % n;
  for (int i = 0; i <= n; ++i) {
    q0[i] = qpow(c[n][i], m_n);
    q1[i] = qpow(c[n][i], m_n + 1);
  }
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    long long* qw = (i < mn ? q1 : q0);
    for (int j = 0; j <= k; ++j) {
      if (dp[i][j] == 0) continue;
      for (int q = 0; j + q <= k && q <= n; ++q) {
        dp[i + 1][j + q] += dp[i][j] * qw[q] % MOD;
        if (dp[i + 1][j + 1] >= MOD) dp[i + 1][j + q] -= MOD;
      }
    }
  }
  cout << dp[n][k] << endl;
  return 0;
}
