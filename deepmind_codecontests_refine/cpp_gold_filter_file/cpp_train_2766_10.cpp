#include <bits/stdc++.h>
const int _G = 3, mod = 998244353, Maxn = 135000, inv2 = 499122177;
inline int read() {
  register int X = 0;
  register char ch = 0;
  while (ch < 48 || ch > 57) ch = getchar();
  while (ch >= 48 && ch <= 57) X = X * 10 + (ch ^ 48), ch = getchar();
  return X;
}
inline void print(int *f, int len) {
  for (int i = 0; i < len; i++) printf("%d ", f[i]);
  puts("");
}
long long powM(long long a, long long t = mod - 2) {
  long long ans = 1;
  while (t) {
    if (t & 1) ans = ans * a % mod;
    a = a * a % mod;
    t >>= 1;
  }
  return ans;
}
const int invG = powM(_G);
int tr[Maxn << 1], tf;
void tpre(int n) {
  if (tf == n) return;
  tf = n;
  for (int i = 0; i < n; i++)
    tr[i] = (tr[i >> 1] >> 1) | ((i & 1) ? n >> 1 : 0);
}
void NTT(int *g, bool op, int n) {
  static unsigned long long f[Maxn << 1], w[Maxn] = {1};
  tpre(n);
  for (int i = 0; i < n; i++) f[i] = (((long long)mod << 5) + g[tr[i]]) % mod;
  for (int l = 1; l < n; l <<= 1) {
    unsigned long long tG = powM(op ? _G : invG, (mod - 1) / (l + l));
    for (int i = 1; i < l; i++) w[i] = w[i - 1] * tG % mod;
    for (int k = 0; k < n; k += l + l)
      for (int p = 0; p < l; p++) {
        int tt = w[p] * f[k | l | p] % mod;
        f[k | l | p] = f[k | p] + mod - tt;
        f[k | p] += tt;
      }
    if (l == (1 << 10))
      for (int i = 0; i < n; i++) f[i] %= mod;
  }
  if (!op) {
    unsigned long long invn = powM(n);
    for (int i = 0; i < n; ++i) g[i] = f[i] % mod * invn % mod;
  } else
    for (int i = 0; i < n; ++i) g[i] = f[i] % mod;
}
void px(int *f, int *g, int n) {
  for (int i = 0; i < n; ++i) f[i] = 1ll * f[i] * g[i] % mod;
}
int _g1[Maxn << 1];
void times(int *f, int *g, int len, int lim) {
  int n = 1;
  for (n; n < len + len; n <<= 1)
    ;
  memcpy(_g1, g, sizeof(int) * (n));
  for (int i = len; i < n; i++) _g1[i] = 0;
  NTT(f, 1, n);
  NTT(_g1, 1, n);
  px(f, _g1, n);
  NTT(f, 0, n);
  for (int i = lim; i < n; ++i) f[i] = 0;
  memset(_g1, 0, sizeof(int) * (n));
}
int _w2[Maxn << 1], _r2[Maxn << 1];
void invp(int *f, int m) {
  int n;
  for (n = 1; n < m; n <<= 1)
    ;
  _w2[0] = powM(f[0]);
  for (int len = 2; len <= n; len <<= 1) {
    for (int i = 0; i < (len >> 1); i++) _r2[i] = (_w2[i] << 1) % mod;
    memcpy(_g1, f, sizeof(int) * (len));
    NTT(_w2, 1, len << 1);
    px(_w2, _w2, len << 1);
    NTT(_g1, 1, len << 1);
    px(_w2, _g1, len << 1);
    NTT(_w2, 0, len << 1);
    memset(_w2 + len, 0, sizeof(int) * (len));
    for (int i = 0; i < len; i++) _w2[i] = (_r2[i] - _w2[i] + mod) % mod;
  }
  memcpy(f, _w2, sizeof(int) * (m));
  memset(_g1, 0, sizeof(int) * (n + n));
  memset(_w2, 0, sizeof(int) * (n + n));
  memset(_r2, 0, sizeof(int) * (n + n));
}
void dao(int *f, int m) {
  for (int i = 1; i < m; i++) f[i - 1] = 1ll * f[i] * i % mod;
  f[m - 1] = 0;
}
int inv[Maxn];
void Init(int lim) {
  inv[1] = 1;
  for (int i = 2; i <= lim; i++)
    inv[i] = 1ll * inv[mod % i] * (mod - mod / i) % mod;
}
void jifen(int *f, int m) {
  for (int i = m; i; i--) f[i] = 1ll * f[i - 1] * inv[i] % mod;
  f[0] = 0;
}
int _s3[Maxn << 2];
void lnp(int *f, int m) {
  memcpy(_s3, f, sizeof(int) * (m));
  invp(_s3, m);
  dao(f, m);
  times(f, _s3, m, m);
  jifen(f, m - 1);
  memset(_s3, 0, sizeof(int) * (m));
}
int _xp[Maxn << 1], _xp2[Maxn << 1];
void exp(int *f, int m) {
  int n = 1;
  for (; n < m; n <<= 1)
    ;
  _xp2[0] = 1;
  for (int len = 2; len <= n; len <<= 1) {
    memcpy(_xp, _xp2, sizeof(int) * (len >> 1));
    lnp(_xp, len);
    for (int i = 0; i < len; i++) _xp[i] = (f[i] - _xp[i] + mod) % mod;
    _xp[0] = (_xp[0] + 1) % mod;
    times(_xp2, _xp, len, len);
  }
  memcpy(f, _xp2, sizeof(int) * (m));
  memset(_xp, 0, sizeof(int) * (n + n));
  memset(_xp2, 0, sizeof(int) * (n + n));
}
void powp(int *f, int k, int n, int p) {
  static int g[Maxn] = {1};
  for (int m = 0; m < n - 1; m++) {
    g[m + 1] = 0;
    for (int i = 1; i < k; i++)
      g[m + 1] = (g[m + 1] +
                  (1ll * p * i - m + i - 1) % mod * f[i] % mod * g[m - i + 1]) %
                 mod;
    g[m + 1] = (long long)(g[m + 1] + mod) * inv[m + 1] % mod;
  }
  memcpy(f, g, sizeof(int) * (n));
}
int n, k, t, F1[Maxn << 1], F2[Maxn << 1];
int main() {
  scanf("%d%d", &n, &k);
  t = n < k ? n + 1 : k + 1;
  Init(t + 1);
  F1[0] = F2[0] = 1;
  F1[1] = F2[1] = 6;
  F1[2] = F2[2] = 1;
  powp(F1, 3, t, mod - inv2);
  powp(F2, 3, t, inv2);
  F2[0]++;
  F2[1]++;
  for (int i = 0; i < t; i++) F2[i] = 1ll * F2[i] * inv2 % mod;
  lnp(F2, t);
  for (int i = 0; i < t; i++) F2[i] = 1ll * F2[i] * (n + 1) % mod;
  exp(F2, t);
  times(F1, F2, t, t);
  for (int i = 1; i < t; i++) printf("%d ", F1[i]);
  for (int i = 0; i <= k - t; i++) printf("0 ");
  return 0;
}
