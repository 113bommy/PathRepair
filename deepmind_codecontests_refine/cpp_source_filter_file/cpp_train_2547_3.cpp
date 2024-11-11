#include <bits/stdc++.h>
using namespace std;
template <class t>
inline void read(t& res) {
  char ch;
  while (ch = getchar(), !isdigit(ch))
    ;
  res = ch ^ 48;
  while (ch = getchar(), isdigit(ch)) res = res * 10 + (ch ^ 48);
}
template <class t>
inline void print(t x) {
  if (x > 9) print(x / 10);
  putchar(x % 10 + 48);
}
const int e = 3e5 + 5, z1 = 29, z2 = 31, h1 = 1e9 + 7, h2 = 1e9 + 9;
struct node {
  int s1, s2, len;
  node() {}
  node(int _s1, int _s2, int _len) : s1(_s1), s2(_s2), len(_len) {}
} up[e], down[e];
vector<int> a[e], b[e], g[e];
int n, top[e], son[e], m, f[20][e], dep[e], mx[e];
int p1[e], p2[e], fa[e], dfn[e], id[e << 1], tim, logn[e << 1], c[21][e << 1];
int q1[e], q2[e], inv1, inv2;
char s[e];
inline bool operator==(node a, node b) { return a.s1 == b.s1 && a.s2 == b.s2; }
inline node operator+(node a, node b) {
  return node(((long long)a.s1 * p1[b.len] + b.s1) % h1,
              ((long long)a.s2 * p2[b.len] + b.s2) % h2, a.len + b.len);
}
inline int ksm(int x, int y, int mod) {
  int res = 1;
  while (y) {
    if (y & 1) res = (long long)res * x % mod;
    y >>= 1;
    x = (long long)x * x % mod;
  }
  return res;
}
inline void dfs1(int u, int pa) {
  int i;
  fa[u] = pa;
  dep[u] = dep[pa] + 1;
  mx[u] = dep[u];
  s[u] -= 'a' - 1;
  dfn[u] = ++tim;
  id[tim] = u;
  for (i = 0; i < 18; i++) f[i + 1][u] = f[i][f[i][u]];
  node a = down[pa], b = up[pa];
  down[u] = node(((long long)z1 * a.s1 + s[u]) % h1,
                 ((long long)z2 * a.s2 + s[u]) % h2, a.len + 1);
  up[u] = node((b.s1 + (long long)p1[b.len] * s[u]) % h1,
               (b.s2 + (long long)p2[b.len] * s[u]) % h2, b.len + 1);
  for (auto v : g[u])
    if (v != pa) {
      f[0][v] = u;
      dfs1(v, u);
      if (mx[v] > mx[u]) mx[u] = mx[v], son[u] = v;
      id[++tim] = u;
    }
}
inline void dfs2(int u, int pa, int fi) {
  top[u] = fi;
  if (son[u]) dfs2(son[u], u, fi);
  for (auto v : g[u])
    if (v != pa && v != son[u]) dfs2(v, u, v);
}
inline int cmp(int x, int y) { return dep[x] < dep[y] ? x : y; }
inline void init() {
  int i, j;
  logn[0] = -1;
  for (i = 1; i <= tim; i++) logn[i] = logn[i >> 1] + 1, c[0][i] = id[i];
  for (j = 1; (1 << j) <= tim; j++)
    for (i = 1; i + (1 << j) - 1 <= tim; i++)
      c[j][i] = cmp(c[j - 1][i], c[j - 1][i + (1 << j - 1)]);
}
inline int lca(int l, int r) {
  l = dfn[l];
  r = dfn[r];
  if (l > r) swap(l, r);
  int k = logn[r - l + 1];
  return cmp(c[k][l], c[k][r - (1 << k) + 1]);
}
inline int anc(int x, int k) {
  if (!k) return x;
  int y = logn[k], to;
  x = f[y][x];
  k -= (1 << y);
  to = top[x];
  if (dep[to] <= dep[x] - k)
    return b[to][dep[x] - k - dep[to]];
  else
    return a[to][dep[to] - dep[x] + k];
}
inline int sub1(int x, int y) {
  (x -= y) < 0 && (x += h1);
  return x;
}
inline int sub2(int x, int y) {
  (x -= y) < 0 && (x += h2);
  return x;
}
inline node query_up(int x, int y) {
  node a = up[x], b = up[y];
  return node((long long)sub1(a.s1, b.s1) * q1[b.len] % h1,
              (long long)sub2(a.s2, b.s2) * q2[b.len] % h2, a.len - b.len);
}
inline node query_down(int x, int y) {
  node a = up[y], b = up[x];
  return node(sub1(a.s1, (long long)b.s1 * p1[a.len - b.len] % h1),
              sub2(a.s2, (long long)b.s2 * p2[a.len - b.len] % h2),
              a.len - b.len);
}
inline node calc(int x, int y, int z, int len) {
  int d1 = dep[x] - dep[z] + 1, d2 = dep[x] + dep[y] - 2 * dep[z] + 1;
  if (len <= d1) {
    int u = anc(x, len - 1);
    return query_up(x, fa[u]);
  } else {
    int u = anc(y, d2 - len);
    return query_up(x, fa[z]) + query_down(z, u);
  }
}
inline int query(int x, int y, int u, int v) {
  int z = lca(x, y), w = lca(u, v), res = 0, l = 1,
      r = min(dep[x] + dep[y] - 2 * dep[z], dep[u] + dep[v] - 2 * dep[w]) + 1;
  while (l <= r) {
    int mid = l + r >> 1;
    if (calc(x, y, z, mid) == calc(u, v, w, mid))
      res = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  return res;
}
int main() {
  read(n);
  int i, x, y, u, v, j;
  scanf("%s", s + 1);
  for (i = 1; i < n; i++) {
    read(x);
    read(y);
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }
  inv1 = ksm(z1, h1 - 2, h1);
  inv2 = ksm(z2, h2 - 2, h2);
  p1[0] = p2[0] = q1[0] = q2[0] = 1;
  for (i = 1; i <= n; i++) {
    p1[i] = (long long)p1[i - 1] * z1 % h1;
    p2[i] = (long long)p2[i - 1] * z2 % h2;
    q1[i] = (long long)q1[i - 1] * inv1 % h1;
    q2[i] = (long long)q2[i - 1] * inv2 % h2;
  }
  dfs1(1, 0);
  dfs2(1, 0, 1);
  init();
  for (i = 1; i <= n; i++)
    if (top[i] == i) {
      int x = i;
      for (j = 0; j <= mx[i] - dep[i]; j++) a[i].emplace_back(x), x = fa[x];
      x = i;
      while (x) b[i].emplace_back(x), x = son[x];
    }
  read(m);
  while (m--) {
    read(x);
    read(y);
    read(u);
    read(v);
    print(query(x, y, u, v));
    putchar('\n');
  }
  return 0;
}
