#include <bits/stdc++.h>
using namespace std;
const int N = 17, S = 1 << N, p = 1e9 + 7, inv2 = (p + 1) >> 1;
inline void A(int &x, int y) {
  x += y;
  if (x >= p) x -= p;
}
struct Dx {
  int f[S];
  int &operator[](int x) { return f[x]; }
} a, d, fib;
inline Dx operator*(Dx a, Dx b) {
  for (int i = 0; i < S; ++i) a[i] = 1ll * a[i] * b[i] % p;
  return a;
}
inline void fwt(Dx &a, int ty) {
  for (int d = 1; d < S; d <<= 1)
    for (int m = d << 1, i = 0; i < S; i += m)
      for (int j = 0; j < d; ++j) {
        int x = a[i + j], y = a[i + j + d];
        if (ty == 0)
          A(a[i + j], y);
        else
          a[i + j] = (x + y) % p, a[i + j + d] = (x - y + p) % p;
      }
}
inline void ufwt(Dx &a, int ty) {
  for (int d = 1; d < S; d <<= 1)
    for (int m = d << 1, i = 0; i < S; i += m)
      for (int j = 0; j < d; ++j) {
        int x = a[i + j], y = a[i + j + d];
        if (ty == 0)
          A(a[i + j], p - y);
        else
          a[i + j] = 1ll * (x + y) * inv2 % p,
                a[i + j + d] = 1ll * (x - y + p) * inv2 % p;
      }
}
inline Dx operator&(Dx a, Dx b) {
  fwt(a, 0);
  fwt(b, 0);
  a = a * b;
  ufwt(a, 0);
  return a;
}
inline Dx operator^(Dx a, Dx b) {
  fwt(a, 1);
  fwt(b, 1);
  a = a * b;
  ufwt(a, 1);
  return a;
}
int bc[S], f[S][N + 1], g[S][N + 1], tmp[N + 1];
inline Dx UCO(Dx a, Dx b) {
  for (int i = 0; i < S; ++i) bc[i] = bc[i >> 1] + (i & 1);
  for (int i = 0; i < S; ++i) f[i][bc[i]] = a[i], g[i][bc[i]] = b[i];
  for (int d = 1; d < S; d <<= 1)
    for (int m = d << 1, i = 0; i < S; i += m)
      for (int j = 0; j < d; ++j)
        for (int k = 0; k <= N; ++k)
          A(f[i + j + d][k], f[i + j][k]), A(g[i + j + d][k], g[i + j][k]);
  for (int i = 0; i < S; ++i) {
    memset(tmp, 0, sizeof tmp);
    for (int k1 = 0; k1 <= N; ++k1)
      for (int k2 = 0; k1 + k2 <= N; ++k2)
        A(tmp[k1 + k2], 1ll * f[i][k1] * g[i][k2] % p);
    memcpy(f[i], tmp, sizeof tmp);
  }
  for (int d = 1; d < S; d <<= 1)
    for (int m = d << 1, i = 0; i < S; i += m)
      for (int j = 0; j < d; ++j)
        for (int k = 0; k <= N; ++k) A(f[i + j + d][k], p - f[i + j][k]);
  Dx ans;
  for (int i = 0; i < S; ++i) ans[i] = f[i][bc[i]];
  return ans;
}
int n;
int main() {
  scanf("%d", &n);
  for (int i = 1, x; i <= n; ++i) scanf("%d", &x), ++a[x];
  fib[0] = 0;
  fib[1] = 1;
  for (int i = 2; i < S; ++i) A(fib[i], fib[i - 1] + fib[i - 2]);
  d = (UCO(a, a) * fib) & (a * fib) & ((a ^ a) * fib);
  int ans = 0;
  for (int i = 1; i < S; i <<= 1) A(ans, d[i]);
  printf("%d", ans);
  return 0;
}
