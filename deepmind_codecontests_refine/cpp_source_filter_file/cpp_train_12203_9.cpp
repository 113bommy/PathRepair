#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  bool f = 0;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar()) f = (ch == '-');
  for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch ^ 48);
  return f ? -x : x;
}
const int maxn = 1e5 + 7;
const int mod = 998244353;
inline int qpow(int d, int z, int a = 1) {
  for (; z; z >>= 1, d = 1ll * d * d % mod)
    if (z & 1) a = 1ll * a * d % mod;
  return a;
}
const int inv100 = qpow(100, mod - 2);
int n, ans;
int x[maxn], v[maxn], p[2][maxn];
inline int getspd(int i, int x, int y) {
  if (x == 0 && y == 1) return -1;
  if (x == 0 && y == 0) return v[i + 1] - v[i];
  if (x == 1 && y == 0) return v[i + 1] + v[i];
  if (x == 1 && y == 1) return v[i] - v[i + 1];
}
struct mar {
  int a[2][2];
  mar() { memset(a, 0, sizeof(a)); }
  mar(int w, int x, int y, int z) {
    a[0][0] = w;
    a[0][1] = x;
    a[1][0] = y;
    a[1][1] = z;
  }
  inline mar friend operator*(mar a, mar b) {
    mar ret;
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j)
        ret.a[i][j] =
            (1ll * a.a[i][0] * b.a[0][j] + 1ll * a.a[i][1] * b.a[1][j]) % mod;
    return ret;
  }
} M[maxn], sum[maxn * 4];
struct state {
  int p, i, j, S, V, T;
  inline bool friend operator<(state a, state b) {
    return 1ll * a.S * b.V < 1ll * a.V * b.S;
  }
} st[maxn * 4];
int id;
void build(int k, int L, int R) {
  if (L == R) return sum[k] = M[R], void();
  int mid = (L + R) >> 1;
  build(k << 1, L, mid);
  build(k << 1 | 1, mid + 1, R);
  sum[k] = sum[k << 1] * sum[k << 1 | 1];
}
void mdf(int k, int L, int R, int p) {
  if (L == R) return sum[k] = M[R], void();
  int mid = (L + R) >> 1;
  if (p <= mid)
    mdf(k << 1, L, mid, p);
  else
    mdf(k << 1 | 1, mid + 1, R, p);
  sum[k] = sum[k << 1] * sum[k << 1 | 1];
}
int main() {
  n = read();
  if (n == 1) return puts("0"), 0;
  for (int i = 1; i <= n; ++i)
    x[i] = read(), v[i] = read(), p[1][i] = 1ll * inv100 * read() % mod,
    p[0][i] = mod + 1 - p[1][i];
  for (int i = 1; i < n; ++i)
    for (int l = 0; l < 2; ++l)
      for (int r = 0; r < 2; ++r)
        if (getspd(i, l, r) > 0) {
          st[++id].p = i;
          st[id].i = l;
          st[id].j = r;
          st[id].S = x[i + 1] - x[i];
          st[id].V = getspd(i, l, r);
          st[id].T = 1ll * st[id].S * qpow(st[id].V, mod - 2) % mod;
        }
  for (int i = 1; i < n; ++i)
    M[i] = mar(p[0][i + 1], p[0][i + 1], p[1][i + 1], p[1][i + 1]);
  sort(st + 1, st + 1 + id);
  build(1, 1, n - 1);
  for (int i = 1; i <= id; ++i) {
    int ps = st[i].p;
    mar m1 = M[ps], m2 = mar(0, 0, 0, 0);
    m2.a[st[i].i][st[i].j] = p[st[i].j][ps + 1];
    M[ps] = m2;
    mdf(1, 1, n - 1, ps);
    mar m3 = mar(p[0][1], p[1][1], 0, 0);
    m3 = m3 * sum[1];
    ans = (ans + 1ll * st[i].T * (m3.a[0][0] + m3.a[0][1])) % mod;
    m1.a[st[i].i][st[i].j] = 0;
    M[ps] = m1;
    mdf(1, 1, n - 1, ps);
  }
  printf("%d\n", ans);
  return 0;
}
