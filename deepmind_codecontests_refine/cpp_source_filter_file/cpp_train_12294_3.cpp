#include <bits/stdc++.h>
using namespace std;
const int RLEN = 1 << 20 | 1;
inline char gc() {
  static char ibuf[RLEN], *ib, *ob;
  (ib == ob) && (ob = (ib = ibuf) + fread(ibuf, 1, RLEN, stdin));
  return (ib == ob) ? EOF : *ib++;
}
inline int read() {
  char ch = gc();
  int res = 0;
  bool f = 1;
  while (!isdigit(ch)) f ^= ch == '-', ch = gc();
  while (isdigit(ch)) res = (res + (res << 2) << 1) + (ch ^ 48), ch = gc();
  return f ? res : -res;
}
inline long long readl() {
  char ch = gc();
  long long res = 0;
  bool f = 1;
  while (!isdigit(ch)) f ^= ch == '-', ch = gc();
  while (isdigit(ch)) res = (res + (res << 2) << 1) + (ch ^ 48), ch = gc();
  return f ? res : -res;
}
template <class tp>
inline void chemx(tp &a, tp b) {
  a < b ? a = b : 0;
}
template <class tp>
inline void chemn(tp &a, tp b) {
  a > b ? a = b : 0;
}
const int mod = 998244353, G = 3;
inline int add(int a, int b) { return (a += b) >= mod ? (a - mod) : a; }
inline int dec(int a, int b) {
  a -= b;
  return a + (a >> 31 & mod);
}
inline int mul(int a, int b) {
  static long long r;
  r = 1ll * a * b;
  return (r >= mod) ? (r % mod) : r;
}
inline void Add(int &a, int b) { (a += b) >= mod ? (a -= mod) : 0; }
inline void Dec(int &a, int b) { a -= b, a += a >> 31 & mod; }
inline void Mul(int &a, int b) {
  static long long r;
  r = 1ll * a * b, a = (r >= mod) ? (r % mod) : r;
}
inline int ksm(int a, int b, int res = 1) {
  for (; b; b >>= 1, Mul(a, a)) (b & 1) && (Mul(res, a), 1);
  return res;
}
inline int Inv(int x) { return ksm(x, mod - 2); }
inline int fix(int x) { return (x < 0) ? (x + mod) : x; }
const int C = 19;
int *w[C + 1], rev[(1 << (C + 1)) | 1];
inline void init_rev(int lim) {
  for (int i = 0; i < lim; i++)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (lim >> 1));
}
inline void init_w() {
  for (int i = 1; i <= C; i++) w[i] = new int[1 << (i - 1)];
  int wn = ksm(G, (mod - 1) / (1 << C));
  w[C][0] = 1;
  for (int i = 1, l = (1 << (C - 1)); i < l; i++)
    w[C][i] = mul(w[C][i - 1], wn);
  for (int i = C - 1; i; i--)
    for (int j = 0, l = (1 << (i - 1)); j < l; j++) w[i][j] = w[i + 1][j << 1];
}
inline void ntt(int *f, int lim, int kd) {
  for (int i = 0; i < lim; i++)
    if (i > rev[i]) swap(f[i], f[rev[i]]);
  for (int mid = 1, l = 1, a0, a1; mid < lim; mid <<= 1, l++)
    for (int i = 0; i < lim; i += mid << 1)
      for (int j = 0; j < mid; j++)
        a0 = f[i + j], a1 = mul(f[i + j + mid], w[l][j]),
        f[i + j] = add(a0, a1), f[i + j + mid] = dec(a0, a1);
  if (kd == -1) {
    reverse(f + 1, f + lim);
    for (int i = 0, iv = Inv(lim); i < lim; i++) Mul(f[i], iv);
  }
}
inline vector<int> operator+(vector<int> a, vector<int> b) {
  a.resize(max(a.size(), b.size()));
  for (int i = 0; i < b.size(); i++) Add(a[i], b[i]);
  return a;
}
inline vector<int> operator*(vector<int> a, vector<int> b) {
  int deg = a.size() + b.size() - 1, lim = 1;
  if (deg <= 32) {
    vector<int> c(deg, 0);
    for (int i = 0; i < a.size(); i++)
      for (int j = 0; j < b.size(); j++) Add(c[i + j], mul(a[i], b[j]));
    return c;
  }
  while (lim < deg) lim <<= 1;
  init_rev(lim);
  a.resize(lim), b.resize(lim);
  ntt(&a[0], lim, 1), ntt(&b[0], lim, 1);
  for (int i = 0; i < lim; i++) Mul(a[i], b[i]);
  ntt(&a[0], lim, -1);
  a.resize(deg);
  return a;
}
const int N = 100005;
vector<int> e[N];
int siz[N], son[N], fa[N], n;
void dfs1(int u) {
  siz[u] = 1;
  for (int &v : e[u]) {
    if (v == fa[u]) continue;
    fa[v] = u, dfs1(v), siz[u] += siz[v];
    if (siz[v] > siz[son[u]]) son[u] = v;
  }
}
vector<int> f[N], tr[N];
int m;
void build(int l, int r, vector<int> &s1, vector<int> &s2) {
  if (l == r) {
    s1 = s2 = tr[l];
    return;
  }
  int mid = (l + r) >> 1;
  vector<int> fl, fr, gl, gr;
  build(l, mid, fl, gl), build(mid + 1, r, fr, gr);
  s1 = fl * fr, s2 = fl * gr + fr;
}
vector<int> dfs2(int u) {
  for (int v = u; v; v = son[v]) {
    for (int &x : e[v]) {
      if (x == fa[v] || x == son[v]) continue;
      f[v] = dfs2(x);
    }
    if (f[v].size() < 1) f[v].push_back(0);
    f[v][0]++, f[v].push_back(0);
    for (int i = f[v].size() - 1; i; i--) f[v][i] = f[v][i - 1];
    f[v][0] = 0;
  }
  m = 0;
  for (int v = u; v; v = son[v]) tr[++m] = f[v];
  vector<int> s1, s2;
  build(1, m, s1, s2);
  return s2;
}
int iv[N];
inline void init_inv() {
  iv[0] = 1, iv[1] = 1;
  for (int i = 2; i < N; i++) iv[i] = mul(mod - mod / i, iv[mod % i]);
}
int main() {
  init_w(), init_inv();
  n = read();
  int x = readl() % mod;
  for (int i = 1; i < n; i++) {
    int u = read(), v = read();
    e[u].push_back(v), e[v].push_back(u);
  }
  dfs1(1);
  vector<int> ret = dfs2(1);
  int res = 0;
  for (int mt = 1, i = 1; i < ret.size(); Mul(mt, mul(add(x, i), iv[i])), i++)
    Add(res, mul(ret[i], mt));
  cout << res;
}
