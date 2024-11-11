#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  bool f = 0;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = 1;
  for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
  if (f) x = -x;
}
template <typename F>
inline void write(F x, char ed = '\n') {
  static short st[30];
  short tp = 0;
  if (x < 0) putchar('-'), x = -x;
  do st[++tp] = x % 10, x /= 10;
  while (x);
  while (tp) putchar('0' | st[tp--]);
  putchar(ed);
}
template <typename T>
inline void Mx(T &x, T y) {
  x < y && (x = y);
}
template <typename T>
inline void Mn(T &x, T y) {
  x > y && (x = y);
}
const int N = 1005000;
int h[N], ne[N], to[N], dfn[N], dep[N], pos[N], tot, len, q, n;
inline void add(int x, int y) { ne[++tot] = h[x], to[h[x] = tot] = y; }
namespace Azusa {
int siz[N], Top[N], son[N], id[N], f[N], cnt;
void dfs1(int x, int fa) {
  dep[x] = dep[f[x] = fa] + (siz[x] = 1);
  for (int i = h[x]; i; i = ne[i]) {
    int y = to[i];
    if (y == fa) continue;
    dfs1(y, x), siz[x] += siz[y];
    if (siz[y] > siz[son[x]]) son[x] = y;
  }
}
void dfs2(int x, int topf) {
  Top[x] = topf, id[dfn[x] = ++cnt] = x;
  if (son[x]) dfs2(son[x], topf);
  for (int i = h[x], y; i; i = ne[i])
    if ((y = to[i]) != f[x] && y != son[x]) dfs2(y, y);
}
int Lca(int x, int y) {
  while (Top[x] != Top[y]) {
    if (dep[Top[x]] < dep[Top[y]]) swap(x, y);
    x = f[Top[x]];
  }
  return dep[x] < dep[y] ? x : y;
}
int getto(int x, int z) {
  int t = 0;
  while (Top[x] != Top[z]) t = Top[x], x = f[t];
  return x == z ? t : son[z];
}
bool in(int x, int y) {
  return dfn[x] <= dfn[y] && dfn[y] <= dfn[x] + siz[x] - 1;
}
}  // namespace Azusa
using Azusa::getto;
using Azusa::Lca;
namespace jzp {
int st[20][N], lg[N];
void main() {
  lg[0] = -1;
  for (int i = 1; i <= len; ++i) st[0][i] = pos[i], lg[i] = lg[i >> 1] + 1;
  for (int i = 1; i <= 19; ++i)
    for (int j = 1; j + (1 << i) - 1 <= len; ++j)
      st[i][j] = Lca(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
}
int query(int l, int r) {
  int t = lg[r - l + 1];
  return Lca(st[t][l], st[t][r - (1 << t) + 1]);
}
}  // namespace jzp
namespace SegmentTree {
int mx[N << 2];
void build(int p, int l, int r) {
  if (l == r) return mx[p] = Azusa::id[l], void();
  int mid = (l + r) >> 1;
  build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
  mx[p] = max(mx[p << 1], mx[p << 1 | 1]);
}
int query(int p, int l, int r, int L, int R) {
  if (L <= l && r <= R) return mx[p];
  int mid = (l + r) >> 1, mmx = 0;
  if (L <= mid) Mx(mmx, query(p << 1, l, mid, L, R));
  if (R > mid) Mx(mmx, query(p << 1 | 1, mid + 1, r, L, R));
  return mmx;
}
void change(int p, int l, int r, int x, int t) {
  if (l == r) return mx[p] = t, void();
  int mid = (l + r) >> 1;
  x <= mid ? change(p << 1, l, mid, x, t)
           : change(p << 1 | 1, mid + 1, r, x, t);
  mx[p] = t;
}
}  // namespace SegmentTree
using SegmentTree::query;
namespace Bit {
int d[N];
void Add(int x, int c) {
  for (; x <= len; x += x & -x) d[x] += c;
}
int Sum(int x) {
  int res = 0;
  for (; x; x -= x & -x) res += d[x];
  return res;
}
}  // namespace Bit
namespace LCT {
int s[N][2], siz[N], col[N], f[N];
inline bool chk(int x) { return s[f[x]][1] == x; }
inline bool nrt(int x) { return s[f[x]][chk(x)] == x; }
inline void rotate(int x) {
  int y = f[x], z = f[y], k = chk(x), w = s[x][!k];
  if (nrt(y)) s[z][chk(y)] = x;
  f[x] = z;
  if (w) f[w] = y;
  s[y][k] = w;
  s[x][!k] = y, f[y] = x;
}
inline void spread(int x) {
  if (col[x]) col[s[x][0]] = col[s[x][1]] = col[x];
}
inline void pus(int x) {
  if (nrt(x)) pus(f[x]);
  spread(x);
}
inline void splay(int x) {
  pus(x);
  for (int y; nrt(x); rotate(x))
    if (nrt(y = f[x])) rotate(chk(y) ^ chk(x) ? x : y);
}
inline void access(int x, int t) {
  Bit::Add(t, dep[x]);
  int y;
  for (y = 0; x; x = f[y = x]) {
    splay(x), s[x][1] = y;
    if (col[x]) Bit::Add(col[x], -(dep[x] - dep[f[x]]));
  }
  splay(y), col[y] = t;
}
}  // namespace LCT
int Query(int l, int r) {
  int t = jzp::query(l, r);
  return Bit::Sum(r) - Bit::Sum(l - 1) - dep[t] + 1;
}
int Dis(int x, int y) { return dep[x] + dep[y] - 2 * dep[Lca(x, y)]; }
int ans[N];
char op[N];
int X[N], inv[N], m;
int main() {
  read(n), read(m);
  for (int i = 1, x, y; i < n; ++i) read(x), read(y), add(x, y), add(y, x);
  Azusa::dfs1(1, 0), Azusa::dfs2(1, 1);
  for (int i = 1; i <= n; ++i) LCT::f[i] = Azusa::f[i], pos[i] = inv[i] = i;
  len = n;
  int t = 0;
  for (int i = 1; i <= m; ++i) {
    char o[9];
    int x;
    scanf("%s", o), read(x);
    op[++t] = o[0], X[t] = x;
    if (o[0] == 'u') pos[++len] = X[i];
    if (o[0] == 'c') op[++t] = o[0], read(X[t]);
  }
  m = t, jzp::main(), SegmentTree::build(1, 1, n);
  int rt = n, nw = n;
  for (int i = 1; i <= n; ++i) LCT::access(i, i);
  for (int i = 1; i <= m; ++i) {
    if (op[i] == 'u') {
      LCT::access(rt = X[i], ++nw), inv[nw] = rt;
      SegmentTree::change(1, 1, n, dfn[X[i]], nw), ans[i] = -1;
    } else {
      if (X[i] == rt) {
        ans[i] = n;
        continue;
      }
      int t;
      if (Azusa::in(X[i], rt)) {
        int sn = getto(rt, X[i]);
        t = query(1, 1, n, 1, dfn[sn] - 1);
        if (dfn[sn] + Azusa::siz[sn] <= n)
          Mx(t, query(1, 1, n, dfn[sn] + Azusa::siz[sn], n));
      } else
        t = query(1, 1, n, dfn[X[i]], dfn[X[i]] + Azusa::siz[X[i]] - 1);
      ans[i] = n - (Query(t, nw) - Dis(X[i], inv[t]) - 1);
    }
  }
  for (int i = 1; i <= m; ++i)
    if (op[i] == 'c')
      write(ans[i] < ans[i + 1] ? X[i] : X[i + 1]), ++i;
    else if (op[i] == 'w')
      write(ans[i]);
  return 0;
}
