#include <bits/stdc++.h>
using namespace std;
int p[2][252], f[252][252], C[252], mod = 1e9 + 7, inv[252];
int qp(int a, int x) {
  int i = 1;
  for (; x; x >>= 1, a = 1ll * a * a % mod)
    if (x & 1) i = 1ll * i * a % mod;
  return i;
}
int main() {
  int n, m, i, j, k, a;
  scanf("%d%d", &n, &m);
  for (inv[1] = 1, i = 2; i <= n; i++)
    inv[i] = mod - 1ll * mod / i * inv[mod % i] % mod;
  for (i = C[0] = p[0][0] = p[1][0] = 1; i <= n; i++) {
    C[i] = 1ll * C[i - 1] * (n - i + 1) % mod * inv[i] % mod;
    p[0][i] = 1ll * p[0][i - 1] * m % mod;
    p[1][i] = 1ll * p[1][i - 1] * (m - 1) % mod;
  }
  for (i = k = 0, j = 1; i <= n; i++, j *= -1) {
    a = 1ll * p[0][n - i] * p[1][i] % mod - p[1][n];
    if (a < 0) a += mod;
    if (a >= mod) a -= mod;
    k += 1ll * j * C[i] * qp(a, n) % mod;
    if (k < 0) k += mod;
    if (k >= mod) k -= mod;
  }
  printf("%d", k);
  return 0;
}
