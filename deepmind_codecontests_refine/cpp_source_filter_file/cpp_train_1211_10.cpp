#include <bits/stdc++.h>
using std::swap;
const long long mod = 1000000007;
int n;
int G[105][105], m[105][105];
int w[105], a[105], _a[105], b[105];
long long ans[105];
long long PowerMod(long long a, int n, long long c = 1) {
  for (; n; n >>= 1, a = a * a % mod)
    if (n & 1) c = c * a % mod;
  return c;
}
int get_value(int x) {
  int i, j, k, det = 1, n = ::n;
  long long coe;
  for (i = 1; i <= n; ++i) {
    for (j = 1; j <= n; ++j) m[i][j] = (G[i][j] ? mod - x : mod - 1);
    m[i][i] = 0;
    for (j = 1; j <= n; ++j)
      i == j ? 0 : (m[i][i] = (m[i][i] + mod - m[i][j]) % mod);
  }
  for (--n, i = 1; i <= n; ++i) {
    for (j = i; j <= n; ++j)
      if (m[j][i]) break;
    if (j > n) return 0;
    if (i != j)
      for (det = mod - det, k = 1; k <= n; ++k) swap(m[i][k], m[j][k]);
    det = (long long)det * m[i][i] % mod;
    coe = PowerMod(m[i][i], mod - 2);
    for (j = 1; j <= n; ++j) m[i][j] = m[i][j] * coe % mod;
    for (k = 1; k <= n; ++k) {
      if (i == k) continue;
      coe = mod - m[k][i];
      for (j = 1; j <= n; ++j) m[k][j] = (m[k][j] + coe * m[i][j]) % mod;
    }
  }
  return det;
}
void divide(int c) {
  int i;
  memcpy(_a, a, n + 1 << 2);
  for (i = n - 1; i >= 0; --i) {
    b[i] = _a[i + 1], _a[i] = (_a[i] + (long long)c * b[i]) % mod;
  }
}
int main() {
  int i, j, u, v;
  long long s;
  scanf("%d", &n);
  for (i = 1; i < n; ++i) scanf("%d%d", &u, &v), G[u][v] = G[v][u] = 1;
  for (i = 0; i < n; ++i) w[i] = get_value(i);
  a[1] = 1;
  for (i = 2; i <= n; ++i)
    for (j = i; j; --j)
      a[j] = (a[j - 1] + (long long)(mod - a[j]) * (i - 1)) % mod;
  for (i = 0; i < n; ++i) {
    divide(i);
    s = 0;
    for (j = n - 1; j >= 0; --j) s = (s * i + b[j]) % mod;
    s = PowerMod(s, mod - 2, w[i]);
    for (j = 0; j < n; ++j) ans[j] = (ans[j] + b[j] * s) % mod;
  }
  for (i = 0; i < n; ++i) printf("%d%c", ans[i], i == n - 1 ? 10 : 32);
  return 0;
}
