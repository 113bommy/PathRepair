#include <bits/stdc++.h>
using namespace std;
const int lim = 100000;
const long long INF = 1ll << 60;
struct Line {
  long long k, b;
  long long get(long long x) { return k * x + b; }
};
struct Node {
  Line x;
  int l, r;
} a[100500 * 20];
int rt[100500], tn;
Line wfc;
void add(int l, int r, int &u) {
  if (!u) {
    a[u = ++tn].x = wfc;
    return;
  }
  int mid = (l + r) >> 1;
  if (a[u].x.get(mid) < wfc.get(mid)) swap(a[u].x, wfc);
  if (l == r) return;
  if (wfc.get(l) > a[u].x.get(l)) add(l, mid, a[u].l);
  if (wfc.get(r) > a[u].x.get(r)) add(mid + 1, r, a[u].r);
}
long long ret;
int to;
void qry(int l, int r, int u) {
  if (!u) return;
  ret = min(ret, a[u].x.get(to));
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (to <= mid)
    qry(l, mid, a[u].l);
  else
    qry(mid + 1, r, a[u].r);
}
int merge(int l, int r, int u, int v) {
  if (!u || !v) return u | v;
  int mid = (l + r) >> 1;
  if (a[u].x.get(mid) < a[v].x.get(mid)) swap(a[u].x, a[v].x);
  if (l < r) {
    a[u].l = merge(l, mid, a[u].l, a[v].l);
    a[u].r = merge(mid + 1, r, a[u].r, a[v].r);
    wfc = a[v].x;
    add(l, r, u);
  }
  return u;
}
vector<int> g[100500];
int va[100500], vb[100500];
long long ans[100500];
void dfs(int u, int fa) {
  for (int i = 0, v; i < g[u].size(); i++)
    if ((v = g[u][i]) != fa) {
      dfs(v, u);
      rt[u] = merge(-lim, lim, rt[u], rt[v]);
    }
  if (!(g[u].size() == 1 && fa)) {
    to = va[u];
    ret = INF;
    qry(-lim, lim, rt[u]);
    ans[u] = ret;
  }
  wfc = (Line){vb[u], ans[u]};
  add(-lim, lim, rt[u]);
}
int n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &va[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &vb[i]);
  for (int i = 1, u, v; i < n; i++) {
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
  return 0;
}
