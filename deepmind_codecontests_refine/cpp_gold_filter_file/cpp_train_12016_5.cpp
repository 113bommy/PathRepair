#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int maxn = 1e5 + 5;
const int logn = 21;
int n, k, ans = 1;
vector<int> g[maxn];
class Node {
 public:
  int mn, cnt, tag;
  Node() {}
  Node(int _mn, int _cnt, int _tag) : mn(_mn), cnt(_cnt), tag(_tag) {}
  Node operator+(const Node &b) const {
    if (mn == b.mn) return Node(mn, cnt + b.cnt, 0);
    if (mn < b.mn) return Node(mn, cnt, 0);
    return Node(b.mn, b.cnt, 0);
  }
};
class SegmentTree {
 private:
  int siz;
  Node dat[maxn << 2];
  void pushDown(int x) {
    if (dat[x].tag) {
      dat[x << 1].tag += dat[x].tag;
      dat[x << 1 | 1].tag += dat[x].tag;
      dat[x << 1].mn += dat[x].tag;
      dat[x << 1 | 1].mn += dat[x].tag;
      dat[x].tag = 0;
      return;
    }
  }
  void build(int x, int l, int r) {
    if (l == r) {
      if (l < n)
        dat[x] = Node(0, 1, 0);
      else
        dat[x] = Node(INF, 0, 0);
      return;
    }
    int md = l + r >> 1;
    build(x << 1, l, md);
    build(x << 1 | 1, md + 1, r);
    dat[x] = dat[x << 1] + dat[x << 1 | 1];
    return;
  }

 public:
  int size() { return siz; }
  void init(int n) {
    for (siz = 1; siz < n; siz <<= 1)
      ;
    build(1, 0, siz - 1);
    return;
  }
  void update(int x, int l, int r, int s, int t, int k) {
    if (s > t) return;
    if (l >= s && r <= t) {
      dat[x].mn += k;
      dat[x].tag += k;
      return;
    }
    int md = l + r >> 1;
    pushDown(x);
    if (s <= md) update(x << 1, l, md, s, t, k);
    if (t > md) update(x << 1 | 1, md + 1, r, s, t, k);
    dat[x] = dat[x << 1] + dat[x << 1 | 1];
    return;
  }
  Node query(int x, int l, int r, int s, int t) {
    if (s > t) return Node(INF, 0, -1);
    if (l >= s && r <= t) return dat[x];
    int md = l + r >> 1;
    pushDown(x);
    Node ret;
    if (s > md)
      ret = query(x << 1 | 1, md + 1, r, s, t);
    else if (t <= md)
      ret = query(x << 1, l, md, s, t);
    else
      ret = query(x << 1, l, md, s, t) + query(x << 1 | 1, md + 1, r, s, t);
    dat[x] = dat[x << 1] + dat[x << 1 | 1];
    return ret;
  }
} seg;
namespace HLD {
int lnk, dfn;
int dep[maxn], sz[maxn], hson[maxn], bel[maxn], head[maxn], len[maxn],
    pos[maxn];
int par[maxn][logn];
void dfs(int u, int p) {
  sz[u] = 1;
  par[u][0] = p;
  if (~p) dep[u] = dep[p] + 1;
  for (int i = (0); i < (g[u].size()); ++i) {
    int v = g[u][i];
    if (v == p) continue;
    dfs(v, u);
    sz[u] += sz[v];
    if (!~hson[u] || sz[v] > sz[hson[u]]) hson[u] = v;
  }
  return;
}
void hld(int u, int p) {
  pos[u] = dfn++;
  bel[u] = lnk;
  if (!len[lnk]) head[lnk] = u;
  ++len[lnk];
  if (~hson[u]) hld(hson[u], u);
  for (int i = (0); i < (g[u].size()); ++i) {
    int v = g[u][i];
    if (v == p || v == hson[u]) continue;
    ++lnk;
    hld(v, u);
  }
  return;
}
void precalc() {
  dfn = 0;
  memset(hson, -1, sizeof(hson));
  dfs(0, -1);
  for (int i = (1); i < (logn); ++i) {
    for (int u = (0); u < (n); ++u) {
      if (~par[u][i - 1])
        par[u][i] = par[par[u][i - 1]][i - 1];
      else
        par[u][i] = -1;
    }
  }
  dfn = lnk = 0;
  hld(0, -1);
  seg.init(n);
  return;
}
void climb(int u, int r, int del, int &ret) {
  for (; bel[u] != bel[r]; u = par[head[bel[u]]][0]) {
    if (!~del) seg.update(1, 0, seg.size() - 1, pos[head[bel[u]]], pos[u], del);
    Node res = seg.query(1, 0, seg.size() - 1, pos[head[bel[u]]], pos[u]);
    if (!res.mn) ret += del * res.cnt;
    if (~del) seg.update(1, 0, seg.size() - 1, pos[head[bel[u]]], pos[u], del);
  }
  if (!~del) seg.update(1, 0, seg.size() - 1, pos[r] + 1, pos[u], del);
  Node res = seg.query(1, 0, seg.size() - 1, pos[r] + 1, pos[u]);
  if (!res.mn) ret += del * res.cnt;
  if (~del) seg.update(1, 0, seg.size() - 1, pos[r] + 1, pos[u], del);
  return;
}
int lca(int u, int v) {
  if (dep[v] > dep[u]) swap(u, v);
  for (int i = logn - 1; i >= 0; --i) {
    if (~par[u][i] && dep[par[u][i]] >= dep[v]) {
      u = par[u][i];
    }
  }
  if (u == v) return u;
  for (int i = logn - 1; i >= 0; --i) {
    if (par[u][i] != par[v][i]) {
      u = par[u][i];
      v = par[v][i];
    }
  }
  return par[u][0];
}
void update(int u, int v, int del, int &ret) {
  int r = lca(u, v);
  climb(u, r, del, ret);
  climb(v, r, del, ret);
  return;
}
}  // namespace HLD
int main() {
  scanf("%d%d", &n, &k);
  for (int i = (1); i < (n); ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  HLD::precalc();
  int res = 0;
  for (int i = 0, j = 0; i + 1 < n; ++i) {
    while (j + 1 < n && res < k) {
      HLD::update(j + 1, j, 1, res);
      ++j;
      if (res >= k) break;
    }
    if (res < k)
      ans = max(ans, j - i + 1);
    else
      ans = max(ans, j - i);
    HLD::update(i + 1, i, -1, res);
  }
  printf("%d\n", ans);
  return 0;
}
