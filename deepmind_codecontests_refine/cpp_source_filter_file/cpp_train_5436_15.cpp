#include <bits/stdc++.h>
using namespace std;
long long dp[11][1001][1001];
long long fac[1001], inv[1001];
long long fun(long long i, long long l1, long long r1, long long l2,
              long long r2, long long m) {
  long long ans = 0;
  if (dp[i][l1][r2] != -1) return dp[i][l1][r2];
  long long &res = dp[i][l1][r2];
  if (i == m) return res = 1;
  for (long long j = l1; j <= r1; j++) {
    ans = ans % 1000000007 +
          ((r2 - j + 1) * fun(i + 1, j, r1, 1, r2, m)) % 1000000007;
    if (ans >= 1000000007) ans -= 1000000007;
  }
  return ans;
}
long long mod_inv(long long x, long long y) {
  if (x == 1) return y;
  long long z = 1000000007 / x + 1;
  return mod_inv((x * z) % 1000000007, (y * z) % 1000000007);
}
long long mul(long long a, long long b) { return (a * b) % 1000000007; }
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(dp, -1, sizeof(dp));
  long long t = 1;
  fac[0] = 1;
  for (long long i = 1; i <= 1000; i++) {
    fac[i] = (fac[i - 1] * i) % 1000000007;
  }
  inv[0] = 1;
  for (long long i = 1; i <= 1000; i++) {
    inv[i] = mod_inv(fac[i], 1) % 1000000007;
  }
  while (t--) {
    long long n, m;
    cin >> n >> m;
    long long ans = mul(fac[n + 2 * m - 1], mul(inv[n - 1], inv[2 * m]));
    ans = ans % 1000000007;
    cout << ans;
  }
}
