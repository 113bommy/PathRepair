#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e3 + 10;
const long long mod = 998244353;
const long long base = 500;
long long dp[maxn][maxn][4];
long long f[maxn];
long long gt[maxn];
long long gtv[maxn];
long long mu(long long a, long long n) {
  if (n == 0) return 1;
  if (n == 1) return a;
  long long t = mu(a, n / 2);
  if (n % 2 == 0) return (t * t) % mod;
  return ((t * t) % mod * a) % mod;
}
void setup() {
  gt[0] = 1;
  for (int i = 1; i < maxn; i++) {
    gt[i] = (gt[i - 1] * i) % mod;
  }
  gtv[maxn - 1] = mu(gt[maxn - 1], mod - 2);
  for (int i = maxn - 2; i >= 0; i--) {
    gtv[i] = (gtv[i + 1] * (i + 1)) % mod;
  }
}
long long nck(long long n, long long k) {
  if (n < k) return 0;
  return ((gt[n] * gtv[k]) % mod * gtv[n - k]) % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (fopen("t.inp", "r")) {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
  }
  setup();
  long long n, k;
  cin >> n >> k;
  dp[0][0][0] = 1;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int t = 0; t < 4; t++) {
        dp[i + 1][j][(t % 2) * 2] =
            (dp[i + 1][j][(t % 2) * 2] + dp[i][j][t]) % mod;
        if ((t & (1ll << 1)) == 0 && i != 0)
          dp[i + 1][j + 1][(t % 2) * 2] =
              (dp[i + 1][j + 1][(t % 2) * 2] + dp[i][j][t]) % mod;
        dp[i + 1][j + 1][(t % 2) * 2 + 1] =
            (dp[i + 1][j + 1][(t % 2) * 2 + 1] + dp[i][j][t]) % mod;
      }
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int k = 0; k <= 3; k += 2) {
      f[i] = (f[i] + dp[n][i][k] * gt[n - i]) % mod;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i + 1; j <= n; j++) {
      f[i] = ((f[i] - f[j] * nck(j, i)) % mod + mod) % mod;
    }
  }
  cout << f[k];
}
