#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 1e9 + 7;
double eps = 1e-12;
long long mpow(long long a, long long b) {
  if (a == 0) return 0;
  if (b == 0) return 1;
  long long t1 = mpow(a, b / 2);
  t1 *= t1;
  t1 %= MOD;
  if (b % 2) t1 *= a;
  t1 %= MOD;
  return t1;
}
long long mpow(long long a, long long b, long long p) {
  if (a == 0) return 0;
  if (b == 0) return 1;
  long long t1 = mpow(a, b / 2, p);
  t1 *= t1;
  t1 %= p;
  if (b % 2) t1 *= a;
  t1 %= p;
  return t1;
}
long long modinverse(long long a, long long m) {
  long long m0 = m;
  long long y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long q = a / m;
    long long t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
long long range(long long l, long long r) { return l + mt() % (r - l + 1); }
long long rev(long long v) { return mpow(v, MOD - 2); }
void solve() {
  long long n, k;
  cin >> n >> k;
  k = (1 << k);
  k /= 2;
  long long a[n];
  long long dp[n + 1][2][k + 1];
  for (long long i = 0; i < n + 1; i++)
    for (long long j = 0; j < 2; j++)
      for (long long l = 0; l < k + 1; l++) dp[i][j][l] = 0;
  dp[0][0][0] = 1;
  for (long long i = 0; i < n; i++) {
    long long v = 0;
    for (long long j = 0; j < k; j++) v += dp[i][1][j];
    cin >> a[i];
    if (a[i] == 2) {
      for (long long l = 2; l < k + 1; l++) dp[i + 1][0][l] += dp[i][1][l - 2];
      for (long long l = 0; l < k; l++) dp[i + 1][1][l] += dp[i][0][l];
      dp[i + 1][0][k] += dp[i][0][k];
    } else if (a[i] == 4) {
      for (long long l = 2; l < k + 1; l++) dp[i + 1][0][l] += dp[i][0][l - 2];
      dp[i + 1][0][2] += v;
      dp[i + 1][0][k] += dp[i][0][k];
    } else {
      for (long long l = 2; l < k + 1; l++) dp[i + 1][0][l] += dp[i][1][l - 2];
      for (long long l = 0; l < k; l++) dp[i + 1][1][l] += dp[i][0][l];
      for (long long l = 2; l < k + 1; l++) dp[i + 1][0][l] += dp[i][0][l - 2];
      dp[i + 1][0][2] += v;
      dp[i + 1][0][k] += 2 * dp[i][0][k];
    }
    for (long long j = 0; j < 2; j++)
      for (long long l = 0; l < k + 1; l++) dp[i + 1][j][k] %= MOD;
  }
  cout << dp[n][0][k] << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  for (long long i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
