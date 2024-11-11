#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int maxc = 1e5;
const int MAXC = 1e5 + 5;
const int mod = 1e9 + 7;
inline void add_mod(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
inline long long pw(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
const int MAXNN = 1.4e5 + 5;
struct Segment_Tree {
  int sum[MAXNN << 1], tag[MAXNN << 1], N;
  inline void build(int n) {
    memset(sum, 0, sizeof(sum));
    memset(tag, 0, sizeof(tag));
    N = 1;
    while (N <= n) N <<= 1;
  }
  inline void update(int l, int r, int k) {
    int x = 1, lx = 0, rx = 0;
    for (l += N - 1, r += N + 1; l ^ r ^ 1; l >>= 1, r >>= 1, x <<= 1) {
      sum[l] = (sum[l] + (long long)lx * k) % mod;
      sum[r] = (sum[r] + (long long)rx * k) % mod;
      if (~l & 1)
        sum[l ^ 1] = (sum[l ^ 1] + (long long)x * k) % mod,
                add_mod(tag[l ^ 1], k), lx += x;
      if (r & 1)
        sum[r ^ 1] = (sum[r ^ 1] + (long long)x * k) % mod,
                add_mod(tag[r ^ 1], k), rx += x;
    }
    for (; l; l >>= 1, r >>= 1)
      sum[l] = (sum[l] + (long long)lx * k) % mod,
      sum[r] = (sum[r] + (long long)rx * k) % mod;
  }
  inline int query(int l, int r) {
    int res = 0, x = 1, lx = 0, rx = 0;
    for (l += N - 1, r += N + 1; l ^ r ^ 1; l >>= 1, r >>= 1, x <<= 1) {
      res = (res + (long long)tag[l] * lx + (long long)tag[r] * rx) % mod;
      if (~l & 1) add_mod(res, sum[l ^ 1]), lx += x;
      if (r & 1) add_mod(res, sum[r ^ 1]), rx += x;
    }
    for (; l; l >>= 1, r >>= 1)
      res = (res + (long long)tag[l] * lx + (long long)tag[r] * rx) % mod;
    return res;
  }
};
struct Edge {
  int next, to;
} e[MAXN << 1];
int head[MAXN], etot = 0;
inline void add(int u, int v) {
  e[++etot] = (Edge){head[u], v};
  head[u] = etot;
}
struct Node {
  int l, r;
};
int n;
Node p[MAXN];
int siz[MAXN], dep[MAXN], son[MAXN];
void dfs_tree(int u, int fa) {
  son[u] = -1;
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if (v == fa) continue;
    dep[v] = dep[u] + 1;
    dfs_tree(v, u);
    siz[u] += siz[v];
    if (son[u] == -1 || siz[son[u]] < siz[v]) son[u] = v;
  }
}
long long a[MAXN];
namespace Part1 {
long long solve(void) {
  static Segment_Tree tree;
  tree.build(maxc);
  long long res = 0;
  for (int i = 1; i <= n; ++i) {
    res =
        res + (long long)dep[i] * a[i] % mod * tree.query(p[i].l, p[i].r) % mod;
    tree.update(p[i].l, p[i].r, a[i]);
  }
  return res;
}
}  // namespace Part1
namespace Part2 {
Segment_Tree tree;
long long res;
void dfs_del(int u, int fa) {
  tree.update(p[u].l, p[u].r, -a[u]);
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if (v == fa) continue;
    dfs_del(v, u);
  }
}
void dfs_calc(int u, int fa, int k) {
  res = (res + (long long)k * a[u] % mod * tree.query(p[u].l, p[u].r)) % mod;
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if (v == fa) continue;
    dfs_calc(v, u, k);
  }
}
void dfs_upd(int u, int fa) {
  tree.update(p[u].l, p[u].r, a[u]);
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if (v == fa) continue;
    dfs_upd(v, u);
  }
}
void dfs_part2(int u, int fa) {
  if (son[u] == -1) {
    tree.update(p[u].l, p[u].r, a[u]);
    return;
  }
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if (v == fa || v == son[u]) continue;
    dfs_part2(v, u);
    dfs_del(v, u);
  }
  dfs_part2(son[u], u);
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if (v == fa || v == son[u]) continue;
    dfs_calc(v, u, dep[u]);
    dfs_upd(v, u);
  }
  res =
      (res + (long long)dep[u] * a[u] % mod * tree.query(p[u].l, p[u].r)) % mod;
  tree.update(p[u].l, p[u].r, a[u]);
}
long long solve(void) {
  tree.build(maxc);
  res = 0;
  dfs_part2(1, 0);
  return res;
}
}  // namespace Part2
inline void rev_array(void) {
  reverse(dep + 1, dep + n + 1);
  reverse(p + 1, p + n + 1);
  reverse(a + 1, a + n + 1);
}
int main(void) {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &p[i].l, &p[i].r);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    add(u, v);
    add(v, u);
  }
  dfs_tree(1, 0);
  for (int i = 1; i <= n; ++i) a[i] = pw(p[i].r - p[i].l + 1, mod - 2);
  long long ans = Part1::solve();
  rev_array();
  ans = (ans + Part1::solve()) % mod;
  rev_array();
  ans = ans - 2 * Part2::solve();
  ans = (ans % mod + mod) % mod;
  for (int i = 1; i <= n; ++i) ans = ans * (p[i].r - p[i].l + 1) % mod;
  printf("%lld", ans);
  return 0;
}
