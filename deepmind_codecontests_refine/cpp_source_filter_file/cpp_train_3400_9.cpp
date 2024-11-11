#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
long long fsp(long long x, int y) {
  long long ans = 1;
  while (y) {
    if (y & 1) ans = ans * x % P;
    x = x * x % P, y >>= 1;
  }
  return ans;
}
const int N = 1e6 + 5;
int n, m, A, B, len, r[N];
long long Inv, a[N], b[N], f[N], g[N], inv[N], fac[N];
void NTT(long long *d, int f) {
  for (int i = 1; i < n; i++)
    if (i < r[i]) swap(d[i], d[r[i]]);
  for (int i = 1; i < n; i <<= 1) {
    int wn = fsp(3, (P - 1) / (i << 1));
    if (f) wn = fsp(wn, P - 2);
    for (int j = 0; j < n; j += i << 1) {
      long long w = 1;
      for (int k = 0; k < i; k++, w = w * wn % P) {
        int x = d[j + k], y = d[i + j + k] * w % P;
        d[j + k] = (x + y) % P, d[i + j + k] = (x - y + P) % P;
      }
    }
  }
  if (f)
    for (int i = 0; i < n; i++) d[i] = d[i] * Inv % P;
}
void mul(long long *f, long long *g, int m, int ty) {
  for (len = 0; (1 << len) <= m * 2; ++len)
    ;
  n = 1 << len, Inv = fsp(n, P - 2);
  for (int i = m + 1; i < n; i++) a[i] = b[i] = 0;
  for (int i = 0; i <= m; i++) a[i] = f[i], b[i] = g[i];
  for (int i = 1; i < n; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (len - 1));
  if (ty) reverse(b, b + m + 1);
  NTT(a, 0), NTT(b, 0);
  for (int i = 0; i < n; i++) a[i] = a[i] * b[i] % P;
  NTT(a, 1);
  if (ty) {
    reverse(a, a + m + 1);
    for (int i = 0; i <= m; i++) f[i] = a[i];
  } else
    for (int i = 0; i <= m * 2; i++) f[i] = a[i];
}
void get(int m) {
  for (int i = 0; i <= m; i++) g[i] = fsp(m, i) * inv[i] % P;
  for (int i = 0; i <= m; i++) f[i] = f[i] * fac[i] % P;
  mul(g, f, m, 1);
  for (int i = 0; i <= m; i++) g[i] = g[i] * inv[i] % P;
  for (int i = 0; i <= m; i++) f[i] = f[i] * inv[i] % P;
}
void solve(int m) {
  if (m <= 1) {
    f[m] = 1;
    return;
  }
  int mid = m >> 1;
  solve(mid), get(mid), mul(f, g, mid, 0);
  if (m & 1)
    for (int i = m; i; i--) f[i] = (f[i] * (m - 1) + f[i - 1]) % P;
}
long long C(int n, int m) { return fac[n] * inv[m] % P * inv[n - m] % P; }
int main() {
  scanf("%d%d%d", &m, &A, &B), inv[0] = fac[0] = 1;
  for (int i = 1; i <= m; i++) {
    fac[i] = fac[i - 1] * i % P;
    inv[i] = fsp(fac[i], P - 2);
  }
  solve(m - 1);
  printf("%lld\n", f[A + B - 2] * C(A + B - 2, A - 1));
  return 0;
}
