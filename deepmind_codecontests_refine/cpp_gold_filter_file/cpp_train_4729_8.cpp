#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 55;
int inv[N], fac[N], f[N][N][3];
int C(int n, int m) {
  if (n < m) return 0;
  return fac[n] * 1ll * inv[m] % mod * inv[n - m] % mod;
}
void _add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
int main() {
  inv[0] = inv[1] = fac[0] = fac[1] = 1;
  for (int i = 2; i <= 50; i++) fac[i] = fac[i - 1] * 1ll * i % mod;
  for (int i = 2; i <= 50; i++)
    inv[i] = (mod - mod / i) * 1ll * inv[mod % i] % mod;
  for (int i = 2; i <= 50; i++) inv[i] = inv[i - 1] * 1ll * inv[i] % mod;
  f[1][0][1] = 1;
  int n, K;
  scanf("%d %d", &n, &K);
  for (int i = 2; i <= n; i++) {
    for (int x = i - 2, y = 1; x; x--, y++) {
      for (int n1 = 0; n1 <= x / 2; n1++) {
        for (int n2 = 0; n2 <= 2; n2++) {
          for (int m1 = 0; m1 <= y / 2; m1++) {
            for (int m2 = 0; m2 <= 2; m2++) {
              int n3 = n1 + n2 - 1, m3 = m1 + m2 - 1;
              int s0 = n3 + m3, s2 = max(n1 + m1, max(n1 + m3, n3 + m1)) + 1;
              _add(f[i][s0][s2 - s0 + 1], f[x][n1][n2] * 1ll * f[y][m1][m2] %
                                              mod * C(i - 2, x - 1) % mod * x %
                                              mod * y % mod);
            }
          }
        }
      }
    }
    for (int n1 = 0; n1 <= (i - 1) / 2; n1++) {
      for (int n2 = 0; n2 <= 2; n2++) {
        int n3 = n1 + n2 - 1;
        int s0 = n3, s2 = n1 + 1;
        _add(f[i][s0][s2 - s0 + 1], f[i - 1][n1][n2] * 1ll * (i - 1) % mod);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= n / 2; i++) {
    for (int j = 0; j <= 2; j++) {
      if (max(i, i + j - 1) == K) _add(ans, f[n][i][j]);
    }
  }
  cout << ans;
  return 0;
}
