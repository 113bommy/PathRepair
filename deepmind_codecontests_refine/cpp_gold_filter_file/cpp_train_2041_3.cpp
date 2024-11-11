#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 1;
const int inf = 0x3f3f3f3f;
int n, m;
struct Edge {
  int u, v, w, id;
  Edge(int pu = 0, int pv = 0, int pw = 0, int pid = 0) {
    u = pu;
    v = pv;
    w = pw;
    id = pid;
  }
  int nb(int i) { return u + v - i; }
  bool operator<(Edge b) const {
    if (w > b.w)
      return 1;
    else
      return w == b.w && id < b.id;
  }
};
struct comp1 {
  bool operator()(const Edge a, const Edge b) { return a.w > b.w; }
};
Edge e[maxn];
int sfa[maxn];
set<Edge> mst;
set<Edge> nmst;
set<Edge>::iterator ite;
vector<Edge> g[maxn];
int findset(int a) {
  if (!sfa[a])
    return a;
  else
    return sfa[a] = findset(sfa[a]);
}
int unionset(int a, int b) {
  a = findset(a);
  b = findset(b);
  sfa[b] = a;
  return a;
}
priority_queue<Edge, vector<Edge>, comp1> pq;
void kruskal() {
  for (int i = 1; i <= m; i++) pq.push(e[i]);
  memset(sfa, 0, sizeof sfa);
  while (pq.size()) {
    Edge te = pq.top();
    pq.pop();
    if (findset(te.u) != findset(te.v)) {
      unionset(te.u, te.v);
      mst.insert(te);
      g[te.u].push_back(te);
      g[te.v].push_back(te);
    } else
      nmst.insert(te);
  }
}
int dep[maxn];
int son[maxn];
int top[maxn];
int sz[maxn];
int efather[maxn];
int echild[maxn];
int w[maxn];
int nw, nseq;
int seq[maxn];
bool vis[maxn];
void dfs1(int u) {
  vis[u] = true;
  sz[u] = 1;
  for (int i = 0; i < g[u].size(); i++) {
    Edge &te = g[u][i];
    int v = te.nb(u);
    if (vis[v]) continue;
    dep[v] = dep[u] + 1;
    efather[v] = te.id;
    echild[te.id] = v;
    dfs1(v);
    sz[u] += sz[v];
    if (sz[v] > sz[son[u]]) son[u] = v;
  }
}
void dfs1() {
  memset(son, 0, sizeof son);
  memset(vis, 0, sizeof vis);
  dep[1] = 1;
  efather[1] = 0;
  sz[0] = 0;
  dfs1(1);
}
void dfs2(int u) {
  if (son[u]) {
    w[son[u]] = nw;
    seq[nw++] = son[u];
    top[son[u]] = top[u];
    dfs2(son[u]);
  }
  for (int i = 0; i < g[u].size(); i++) {
    Edge &te = g[u][i];
    int v = te.nb(u);
    if (efather[u] == te.id || v == son[u]) continue;
    w[v] = nw;
    seq[nw++] = v;
    top[v] = v;
    dfs2(v);
  }
}
void dfs2() {
  nw = 1;
  top[1] = 1;
  w[1] = 0;
  seq[0] = 1;
  dfs2(1);
}
int v1flag[(1 << 19) - 2];
int v1[(1 << 19) - 2];
int v2[(1 << 19) - 2];
void buildv2(int l, int r, int i) {
  if (l == r) {
    v2[i] = e[efather[seq[l]]].w;
    return;
  }
  int mid = (l + r) / 2;
  int li = 2 * i + 1, ri = 2 * i + 2;
  buildv2(l, mid, li);
  buildv2(mid + 1, r, ri);
  v2[i] = max(v2[li], v2[ri]);
}
void build() {
  memset(v1flag, 0x3f, sizeof v1flag);
  memset(v1, 0x3f, sizeof v1);
  buildv2(1, nw - 1, 0);
}
void pushdownv1(int i) {
  if (v1flag[i] != inf) {
    int li = 2 * i + 1, ri = 2 * i + 2;
    v1flag[li] = v1[li] = v1flag[ri] = v1[ri] = v1flag[i];
    v1flag[i] = inf;
  }
}
void stsetv1(int l, int r, int i, int a, int b, int key) {
  if (a <= l && b >= r) {
    v1flag[i] = key;
    v1[i] = key;
    return;
  }
  int mid = (l + r) / 2;
  int li = 2 * i + 1, ri = 2 * i + 2;
  pushdownv1(i);
  if (a <= mid) stsetv1(l, mid, li, a, b, key);
  if (b > mid) stsetv1(mid + 1, r, ri, a, b, key);
  v1[i] = min(v1[li], v1[ri]);
}
int stqueryv1(int l, int r, int i, int p) {
  if (l == r && l == p) {
    return v1[i];
  }
  int mid = (l + r) / 2;
  int li = 2 * i + 1, ri = 2 * i + 2;
  pushdownv1(i);
  if (p <= mid)
    return stqueryv1(l, mid, li, p);
  else
    return stqueryv1(mid + 1, r, ri, p);
}
int stqueryv2(int l, int r, int i, int a, int b) {
  if (a <= l && b >= r) return v2[i];
  int mid = (l + r) / 2;
  int li = 2 * i + 1, ri = 2 * i + 2;
  int res = -1;
  if (a <= mid) res = max(res, stqueryv2(l, mid, li, a, b));
  if (b > mid) res = max(res, stqueryv2(mid + 1, r, ri, a, b));
  return res;
}
void setv1(int u, int v, int key) {
  while (top[u] != top[v]) {
    if (dep[top[u]] > dep[top[v]]) {
      stsetv1(1, nw - 1, 0, w[top[u]], w[u], key);
      u = e[efather[top[u]]].nb(top[u]);
    } else {
      stsetv1(1, nw - 1, 0, w[top[v]], w[v], key);
      v = e[efather[top[v]]].nb(top[v]);
    }
  }
  if (dep[u] == dep[v]) return;
  if (dep[u] < dep[v]) {
    stsetv1(1, nw - 1, 0, w[u] + 1, w[v], key);
  } else {
    stsetv1(1, nw - 1, 0, w[v] + 1, w[u], key);
  }
}
int queryv2(int u, int v) {
  int res = -1;
  while (top[u] != top[v]) {
    if (dep[top[u]] > dep[top[v]]) {
      res = max(res, stqueryv2(1, nw - 1, 0, w[top[u]], w[u]));
      u = e[efather[top[u]]].nb(top[u]);
    } else {
      res = max(res, stqueryv2(1, nw - 1, 0, w[top[v]], w[v]));
      v = e[efather[top[v]]].nb(top[v]);
    }
  }
  if (dep[u] == dep[v]) return res;
  if (dep[u] < dep[v])
    res = max(res, stqueryv2(1, nw - 1, 0, w[u] + 1, w[v]));
  else
    res = max(res, stqueryv2(1, nw - 1, 0, w[v] + 1, w[u]));
  return res;
}
int res[maxn];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    e[i].id = i;
  }
  kruskal();
  dfs1();
  dfs2();
  build();
  memset(res, 0x3f, sizeof res);
  for (ite = nmst.begin(); ite != nmst.end(); ite++) {
    res[ite->id] = queryv2(ite->u, ite->v) - 1;
    setv1(ite->u, ite->v, ite->w - 1);
  }
  for (ite = mst.begin(); ite != mst.end(); ite++) {
    res[ite->id] = stqueryv1(1, nw - 1, 0, w[echild[ite->id]]);
  }
  for (int i = 1; i <= m; i++) printf("%d ", res[i] == inf ? -1 : res[i]);
  puts("");
}
