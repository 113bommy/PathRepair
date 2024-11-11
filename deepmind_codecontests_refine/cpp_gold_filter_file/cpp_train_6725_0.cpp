#include <bits/stdc++.h>
using namespace std;
const long long maxn = 5e1 + 10;
const long long base = 3e18;
const long long mod = 1e9 + 7;
const long double eps = 1e-10;
long long dp[maxn][maxn][maxn];
long long f[maxn][maxn];
long long h[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (fopen("t.inp", "r")) {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
  }
  long long n;
  cin >> n;
  long long p = 0;
  for (int i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    if (i == 1) p = x;
    h[i] = h[i - 1] + x;
  }
  dp[0][0][0] = 1;
  for (long long i = 0; i <= n; i++) {
    for (long long k = 0; k <= n; k++) {
      for (long long j = 0; j <= n; j++) {
        if (k) {
          if (i >= 2) {
            dp[i][j][k] =
                (dp[i][j][k] + dp[i - 2][j][k - 1] * ((i * (i - 1)) / 2)) % mod;
          }
          if (i && j) {
            dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - 1][k - 1] * i * j) % mod;
          }
          if (i && k >= 2) {
            dp[i][j][k] =
                (dp[i][j][k] + dp[i - 1][j + 1][k - 2] * (k - 1) * i) % mod;
          }
          if (j >= 2) {
            dp[i][j][k] =
                (dp[i][j][k] + dp[i][j - 2][k - 1] * ((j * (j - 1)) / 2)) % mod;
          }
          if (j >= 1 && k >= 2) {
            dp[i][j][k] = (dp[i][j][k] + dp[i][j][k - 2] * (j) * (k - 1)) % mod;
          }
          if (k >= 3) {
            dp[i][j][k] =
                (dp[i][j][k] + dp[i][j + 2][k - 3] * ((k - 1) * (k - 2) / 2)) %
                mod;
          }
        } else {
          if (j >= 2) {
            dp[i][j][k] = (dp[i][j][k] + dp[i][j - 2][k] * (j - 1)) % mod;
          }
          if (i && j) {
            dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - 1][k] * i) % mod;
          }
        }
      }
    }
  }
  f[n + 1][n] = 1;
  for (long long l = n; l >= 2; l--) {
    for (long long r = l; r <= n; r++) {
      long long cnt2 = h[r] - h[l - 1] - 2 * (r - l + 1);
      long long cnt1 = r - l + 1 - cnt2;
      for (long long len = 0; len <= 2 * cnt2 + cnt1 && len + r <= n; len++) {
        f[l][r] = (f[l][r] + f[r + 1][r + len] * dp[len][cnt1][cnt2]) % mod;
      }
    }
  }
  if (p + 1 > n) {
    cout << 0;
    return 0;
  }
  cout << f[2][p + 1];
}
