#include <bits/stdc++.h>
using namespace std;
const int N = 105, mod = 1e9 + 7;
long long n, m, k;
int f[N], inv[N], dp[N][N * N];
int add(int x, int y) { return (x * 1ll + y) % mod; }
int mul(int x, int y) { return (x * 1ll * y) % mod; }
int pw(int b, long long p) {
  if (!p) return 1;
  int ret = pw(b, p / 2);
  ret = mul(ret, ret);
  if (p & 1) ret = mul(ret, b);
  return ret;
}
int c(int n, int k) { return n < k ? 0 : mul(f[n], mul(inv[k], inv[n - k])); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  f[0] = inv[0] = dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    f[i] = mul(f[i - 1], i);
    inv[i] = pw(f[i], mod - 2);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      int p = pw(c(n, j), 1 + (m - i) / n);
      for (int kk = 0; kk <= k - j; kk++)
        dp[i][j + kk] = add(dp[i][j + kk], mul(p, dp[i - 1][kk]));
    }
  }
  cout << dp[n][k];
}
