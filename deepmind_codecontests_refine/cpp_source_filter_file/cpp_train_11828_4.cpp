#include <bits/stdc++.h>
using namespace std;
const int N = 250100;
int gi() {
  int w = 0;
  bool q = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') q = 0, c = getchar();
  while (c >= '0' && c <= '9') w = w * 10 + c - '0', c = getchar();
  return q ? w : -w;
}
int mod, m;
int siz[N], inv[N];
struct DT {
  int a[19];
} f[N];
inline int qpow(int x, int y) {
  int ans = 1;
  while (y) {
    if (y & 1) ans = 1LL * ans * x % mod;
    x = 1LL * x * x % mod;
    y >>= 1;
  }
  return ans;
}
int main() {
  int i, s, n = gi(), k = gi(), a, b, y, t[20] = {}, p[20] = {};
  DT *F, *G;
  mod = gi();
  if (n & 1) return printf("%d\n", qpow(k, n)), 0;
  for (i = 0; i < 18; i++) m += n >> i & 1;
  for (i = 0, s = 1; i <= n; i++) {
    inv[i] = i < 2 ? 1 : -1LL * (mod / i) * inv[mod % i] % mod;
    siz[i] = siz[i >> 1] + (i & 1);
    s = 1LL * s * inv[i] % mod;
    if ((i & n) == i) f[i].a[siz[i]] = s;
  }
  for (i = 0; i < 18; i++)
    if (n >> i & 1)
      for (s = n; s; (--s) &= n)
        if (s >> i & 1)
          for (a = 0, F = &f[s ^ (1 << i)], G = &f[s]; a <= m; a++)
            (G->a[a] += F->a[a]) %= mod;
  for (i = 0; i <= n; i++)
    if ((i & n) == i) {
      F = &f[i];
      for (a = 0; a <= m; a++) t[a] = F->a[a], F->a[a] = !a;
      for (y = k; y;) {
        if (y & 1) {
          for (a = 0; a <= m; a++) p[a] = F->a[a], F->a[a] = 0;
          for (a = 0; a <= m; a++)
            if (t[a])
              for (b = 0; a + b <= m; b++)
                F->a[a + b] = (F->a[a + b] + 1LL * t[a] * p[b]) % mod;
        }
        if (y >>= 1) {
          for (a = 0; a <= m; a++) p[a] = t[a], t[a] = 0;
          for (a = 0; a <= m; a++)
            if (p[a])
              for (b = 0; a + b <= m; b++)
                t[a + b] = (t[a + b] + 1LL * p[a] * p[b]) % mod;
        }
      }
    }
  for (i = 0; i < 18; i++)
    if (n >> i & 1)
      for (s = n; s; (--s) &= n)
        if (s >> i & 1)
          for (a = 0, F = &f[s ^ (1 << i)], G = &f[s]; a <= m; a++)
            (G->a[a] -= F->a[a]) %= mod;
  s = f[n].a[m];
  for (i = n; i; i--) s = 1LL * s * i % mod;
  printf("%d\n", (qpow(k, n) - s + mod) % mod);
  return 0;
}
