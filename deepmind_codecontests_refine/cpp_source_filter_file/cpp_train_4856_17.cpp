#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool upmin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
inline bool upmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
const long double eps = 1e-11;
const long double pi = acos(-1);
const int oo = 1 << 30;
const long long loo = 1ll << 62;
const int mods = 1e9 + 7;
const int MX = 1 << 18;
const int MAXN = MX + 5;
const int INF = 0x3f3f3f3f;
inline int read() {
  int f = 1, x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
int a[1000005], b[MAXN], c[18][MAXN], d[18][MAXN], e[MAXN], g[MAXN], f[MAXN],
    cnt[MAXN], m = 18;
int upd(int x, int y) { return x + y >= mods ? x + y - mods : x + y; }
int quick_pow(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = 1ll * ret * x % mods;
    x = 1ll * x * x % mods;
  }
  return ret;
}
void fwtOr(int *A, int Lim, int opt) {
  for (int l = 2; l <= Lim; l <<= 1)
    for (int j = 0, i = l >> 1; j < Lim; j += l)
      for (int k = j; k < j + i; k++)
        A[k + i] = upd(A[k + i], opt == 1 ? A[k] : mods - A[k]);
}
void fwtAnd(int *A, int Lim, int opt) {
  for (int l = 2; l <= Lim; l <<= 1)
    for (int j = 0, i = l >> 1; j < Lim; j += l)
      for (int k = j; k < j + i; k++)
        A[k] = upd(A[k], opt == 1 ? A[k + i] : mods - A[k + i]);
}
void fwtXor(int *A, int Lim, int opt) {
  for (int l = 2; l <= Lim; l <<= 1)
    for (int j = 0, i = l >> 1; j < Lim; j += l)
      for (int k = j; k < j + i; k++) {
        int x = A[k], y = A[k + i];
        A[k] = upd(x, y), A[k + i] = upd(x, mods - y);
      }
  if (opt != 1) {
    int invLim = quick_pow(Lim, mods - 2);
    for (int i = 0; i < Lim; i++) A[i] = 1ll * A[i] * invLim % mods;
  }
}
signed main() {
  int n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  cnt[1] = f[1] = 1;
  for (int i = 2; i <= MX; i++)
    cnt[i] = cnt[i >> 1] + (i & 1), f[i] = upd(f[i - 1], f[i - 2]);
  for (int i = 1; i <= n; i++) b[a[i]]++;
  fwtXor(b, MX, 1);
  for (int i = 0; i < MX; i++) b[i] = 1ll * b[i] * b[i] % mods;
  fwtXor(b, MX, -1);
  for (int i = 0; i < MX; i++) b[i] = 1ll * f[i] * b[i] % mods;
  for (int i = 1; i <= n; i++) c[cnt[a[i]]][a[i]]++;
  for (int i = 0; i < m; i++) fwtOr(c[i], MX, 1);
  for (int i = 0; i < MX; i++)
    for (int j = 0; j < m; j++)
      for (int k = 0; k <= j; k++)
        d[j][i] = upd(d[j][i], 1ll * c[k][i] * c[j - k][i] % mods);
  for (int i = 0; i < m; i++) fwtOr(d[i], MX, -1);
  for (int i = 0; i < MX; i++) e[i] = 1ll * f[i] * d[cnt[i]][i] % mods;
  for (int i = 1; i <= n; i++) g[a[i]] = upd(g[a[i]], f[a[i]]);
  fwtAnd(g, MX, 1), fwtAnd(b, MX, 1), fwtAnd(e, MX, 1);
  for (int i = 0; i < MX; i++) e[i] = 1ll * e[i] * b[i] % mods * g[i] % mods;
  fwtAnd(e, MX, -1);
  int ans = 0;
  for (int i = 0; i < m; i++) ans = upd(ans, e[1 << i]);
  printf("%d\n", ans);
  return 0;
}
