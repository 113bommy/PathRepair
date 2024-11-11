#include <bits/stdc++.h>
using namespace std;
const int N = 55, mod = 998244353;
long long qpow(long long n, long long k) {
  long long res = 1;
  while (k) {
    if (k & 1) res = res * n % mod;
    n = n * n % mod;
    k >>= 1;
  }
  return res;
}
void add(long long &x, long long y) {
  x += y;
  if (x >= mod) x -= mod;
}
int a[N], w[N];
long long f[55][55][111], g[55][55][111], inv[3000];
int main() {
  for (int i = 0; i < 3000; i++) inv[i] = qpow(i, mod - 2);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  long long sum = 0, x = 0, y = 0;
  for (int i = 1; i <= n; i++)
    cin >> w[i], sum += w[i], x += a[i] * w[i], y += (1 - a[i]) * w[i];
  for (int i = m; i >= 0; i--) {
    for (int j = m; j >= 0; j--)
      if (j <= y) {
        if (i + j > m) continue;
        for (int k = 0; k <= 100; k++) {
          if (i + j == m)
            f[i][j][k] = k;
          else {
            f[i][j][k] = (f[i][j][k] +
                          k * inv[x + i + y - j] % mod * f[i + 1][j][k + 1]) %
                         mod;
            f[i][j][k] = (f[i][j][k] + (x + i - k) * inv[x + i + y - j] % mod *
                                           f[i + 1][j][k]) %
                         mod;
            f[i][j][k] = (f[i][j][k] +
                          (y - j) * inv[x + i + y - j] % mod * f[i][j + 1][k]) %
                         mod;
          }
        }
        for (int k = 0; k <= 100; k++) {
          if (i + j == m)
            g[i][j][k] = k;
          else {
            if (k)
              g[i][j][k] = (g[i][j][k] +
                            k * inv[x + i + y - j] % mod * g[i][j + 1][k - 1]) %
                           mod;
            g[i][j][k] = (g[i][j][k] +
                          (x + i) * inv[x + i + y - j] % mod * g[i + 1][j][k]) %
                         mod;
            g[i][j][k] = (g[i][j][k] + (y - j - k) * inv[x + i + y - j] % mod *
                                           g[i][j + 1][k]) %
                         mod;
          }
        }
      }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i])
      cout << f[0][0][w[i]] << endl;
    else
      cout << g[0][0][w[i]] << endl;
  }
}
