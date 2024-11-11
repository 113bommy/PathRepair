#include <bits/stdc++.h>
using namespace std;
const int mxn = 5e5 + 5;
vector<pair<int, int> > g[mxn];
int n, m, root;
int bg[mxn], ed[mxn], cur;
int dep[mxn];
int pari[mxn];
int ord[mxn];
pair<int, int> edge[mxn];
inline void dfs(int x, int par, int Pa, int deep) {
  Pa %= 2;
  bg[x] = ++cur;
  dep[x] = deep;
  pari[x] = Pa;
  ord[cur] = x;
  for (int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i].first;
    if (y != par) dfs(y, x, Pa + g[x][i].second, deep + 1);
  }
  ed[x] = cur;
}
struct Segt {
  int val1[mxn << 2], val2[mxn << 2];
  int lazy[mxn << 2];
  int le[mxn << 2], ri[mxn << 2];
  inline void init() {
    memset(val1, -1, sizeof(val1));
    memset(val2, -1, sizeof(val2));
    memset(lazy, 0, sizeof(lazy));
  }
  inline void pushdown(int x) {
    if (lazy[x]) {
      lazy[x] = 0;
      swap(val1[x << 1], val2[x << 1]);
      swap(val1[x << 1 | 1], val2[x << 1 | 1]);
      lazy[x << 1] ^= 1;
      lazy[x << 1 | 1] ^= 1;
    }
  }
  inline void pushup(int x) {
    pushdown(x);
    val1[x] = -1, val2[x] = -1;
    if (val1[x << 1] != -1) val1[x] = max(val1[x], val1[x << 1]);
    if (val2[x << 1] != -1) val2[x] = max(val2[x], val2[x << 1]);
    if (val1[x << 1 | 1] != -1) val1[x] = max(val1[x], val1[x << 1 | 1]);
    if (val2[x << 1 | 1] != -1) val2[x] = max(val2[x], val2[x << 1 | 1]);
  }
  inline void build(int x, int l, int r) {
    le[x] = l, ri[x] = r;
    if (l == r) {
      if (pari[ord[l]])
        val2[x] = dep[ord[l]];
      else
        val1[x] = dep[ord[l]];
      return;
    }
    int md = l + r >> 1;
    build(x << 1, l, md);
    build(x << 1 | 1, md + 1, r);
    pushup(x);
  }
  inline void upd(int x, int l, int r, int a, int b) {
    if (r < a or b < l) return;
    pushdown(x);
    if (a <= l and r <= b) {
      swap(val1[x], val2[x]);
      lazy[x] = 1;
      pushdown(x);
      return;
    }
    int md = l + r >> 1;
    upd(x << 1, l, md, a, b);
    upd(x << 1 | 1, md + 1, r, a, b);
    pushup(x);
  }
  inline int ask() { return val1[1]; }
} seg;
int dist[mxn];
inline void getd(int x, int par = -1, int dis = 0) {
  dist[x] = dis;
  for (int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i].first;
    if (y != par) getd(y, x, dis + 1);
  }
}
int root1, root2;
int tans[mxn];
int asks[mxn];
inline void solve() {
  scanf("%d", &n);
  for (int i = 1, u, v, t; i < n; ++i) {
    scanf("%d%d%d", &u, &v, &t);
    g[u].push_back(make_pair(v, t));
    g[v].push_back(make_pair(u, t));
    edge[i] = make_pair(u, v);
  }
  for (int i = 1; i <= n; ++i) {
    if (g[i].size() == 1) {
      root = i;
      break;
    }
  }
  memset(dist, 0, sizeof(dist));
  int mw = root;
  getd(root, -1, 0);
  for (int i = 1; i <= n; ++i)
    if (dist[i] > dist[mw]) mw = i;
  root1 = mw;
  memset(dist, 0, sizeof(dist));
  mw = root1;
  getd(root1, -1, 0);
  for (int i = 1; i <= n; ++i)
    if (dist[i] >= dist[mw]) mw = i;
  root2 = mw;
  scanf("%d", &m);
  dfs(root1, -1, 0, 0);
  seg.init();
  seg.build(1, 1, n);
  for (int i = 1; i <= m; ++i) {
    int x;
    scanf("%d", &x);
    asks[i] = x;
    int u = edge[x].first, v = edge[x].second;
    if (dep[u] > dep[v]) swap(u, v);
    seg.upd(1, 1, n, bg[v], ed[v]);
    tans[i] = seg.ask();
  }
  cur = 0;
  memset(bg, 0, sizeof(bg));
  memset(ed, 0, sizeof(ed));
  memset(dep, 0, sizeof(dep));
  memset(pari, 0, sizeof(pari));
  memset(ord, 0, sizeof(ord));
  dfs(root2, -1, 0, 0);
  seg.init();
  seg.build(1, 1, n);
  for (int i = 1; i <= m; ++i) {
    int x = asks[i];
    int u = edge[x].first, v = edge[x].second;
    if (dep[u] > dep[v]) swap(u, v);
    seg.upd(1, 1, n, bg[v], ed[v]);
    printf("%d\n", max(seg.ask(), tans[i]));
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int T = 1;
  for (; T--;) solve();
}
