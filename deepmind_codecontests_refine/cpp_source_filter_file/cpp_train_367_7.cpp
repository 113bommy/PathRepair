#include <bits/stdc++.h>
using namespace std;
const int N = 1009;
int f[N][12][N / 2], n, d, mod;
int inv[N], fac[N];
inline void Plus(int &x, int y) { x = (x + y >= mod ? x + y - mod : x + y); }
inline int mins(int &x, int y) { return (x - y < 0 ? x - y + mod : x - y); }
void Init() {
  inv[0] = inv[1] = fac[1] = 1;
  for (int i = 2; i < N; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  for (int i = 2; i < N; i++)
    inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
  for (int i = 2; i < N; i++) inv[i] = 1ll * inv[i - 1] * inv[i] % mod;
}
inline int C(int n, int m) {
  if (m > n) return 0;
  int res = 1;
  for (int i = n - m + 1; i <= n; i++) res = 1ll * res * i % mod;
  return 1ll * res * inv[m] % mod;
}
int main() {
  scanf("%d%d%d", &n, &d, &mod);
  if (n <= 2) return puts("1"), 0;
  Init();
  for (int i = 0; i <= n / 2; i++) f[1][0][i] = 1;
  f[1][d - 1][0] = 1;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= min(d, i - 1); j++)
      for (int k = 1; k <= n; k++) {
        f[i][j][k] = f[i][j][k - 1];
        for (int t = 1; t * k <= i && t <= j; t++)
          Plus(f[i][j][k], 1ll * f[i - t * k][j - t][k - 1] *
                               C(f[k][d - 1][k - 1] + t - 1, t) % mod);
      }
  if (n & 1)
    printf("%d", f[n][d][n / 2]);
  else
    printf("%d", mins(f[n][d][n / 2], C(f[n / 2][d - 1][n / 2 - 1], 2)));
  return 0;
}
