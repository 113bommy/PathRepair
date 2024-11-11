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
long long sum[19][N], ans[N];
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
  int i, s, n = gi(), k = gi(), a, b, y, t[20] = {}, p[20] = {}, f[20] = {};
  long long *R;
  mod = gi();
  if (n & 1) return printf("%d\n", qpow(k, n)), 0;
  for (i = 0; i < 18; i++) m += n >> i & 1;
  for (i = 0, s = 1; i <= n; i++) {
    inv[i] = i < 2 ? 1 : -1LL * (mod / i) * inv[mod % i] % mod;
    siz[i] = siz[i >> 1] + (i & 1);
    s = 1LL * s * inv[i] % mod;
    if ((i & n) == i) sum[siz[i]][i] = s;
  }
  for (a = 0; a <= m; a++) {
    R = sum[a];
    for (i = 0; i < 18; i++)
      if (n >> i & 1)
        for (s = n; s; (--s) &= n)
          if (s >> i & 1) R[s] += R[s ^ (1 << i)];
  }
  for (i = 0; i <= n; i++)
    if ((i & n) == i) {
      for (a = 0; a <= m; a++) t[a] = sum[a][i] % mod, f[i] = i == 1;
      for (y = k; y;) {
        if (y & 1) {
          for (a = 0; a <= m; a++) p[a] = f[a], f[a] = 0;
          for (a = 0; a <= m; a++)
            if (t[a])
              for (b = 0; a + b <= m; b++)
                f[a + b] = (f[a + b] + 1LL * t[a] * p[b]) % mod;
        }
        if (y >>= 1) {
          for (a = 0; a <= m; a++) p[a] = t[a], t[a] = 0;
          for (a = 0; a <= m; a++)
            if (p[a])
              for (b = 0; a + b <= m; b++)
                t[a + b] = (t[a + b] + 1LL * p[a] * p[b]) % mod;
        }
      }
      ans[i] = f[m];
    }
  for (i = 0; i < 18; i++)
    if (n >> i & 1)
      for (s = n; s; (--s) &= n)
        if (s >> i & 1) ans[s] -= ans[s ^ (1 << i)];
  s = ans[n] % mod;
  for (i = n; i; i--) s = 1LL * s * i % mod;
  printf("%d\n", ((qpow(k, n) - s) % mod + mod) % mod);
  return 0;
}
