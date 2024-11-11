#include <bits/stdc++.h>
using namespace std;
long long anc[500100][20], head[500100], cnt, n, rt, dfn[500100], dep[500100],
    lim, stk[500100], val[500100], fl[500100], fr[500100], f[500100], tp, tot;
struct node {
  long long to, next;
} edge[500100];
void ae(long long u, long long v) {
  edge[cnt].next = head[u], edge[cnt].to = v, head[u] = cnt++;
}
vector<long long> v[500100];
void dfs_dep(long long x) {
  dfn[x] = ++tot, v[dep[x]].push_back(x), lim = max(lim, dep[x]);
  for (long long i = head[x]; i != -1; i = edge[i].next)
    dep[edge[i].to] = dep[x] + 1, dfs_dep(edge[i].to);
}
long long lca(long long x, long long y) {
  if (dep[x] > dep[y]) swap(x, y);
  for (long long i = 19; i >= 0; i--)
    if (dep[x] <= dep[y] - (1 << i)) y = anc[y][i];
  if (x == y) return x;
  for (long long i = 19; i >= 0; i--)
    if (anc[x][i] != anc[y][i]) x = anc[x][i], y = anc[y][i];
  return anc[x][0];
}
bool cmp(long long x, long long y) { return dfn[x] < dfn[y]; }
signed main() {
  scanf("%lld", &n), memset(head, -1, sizeof(head));
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &anc[i][0]);
    if (!anc[i][0])
      rt = i;
    else
      ae(anc[i][0], i);
  }
  for (long long j = 1; j < 19; j++)
    for (long long i = 1; i <= n; i++) anc[i][j] = anc[anc[i][j - 1]][j - 1];
  dfs_dep(rt);
  for (long long i = 0; i <= lim; i++) {
    long long sz = v[i].size();
    if (sz == 1) {
      f[v[i][0]] = f[anc[v[i][0]][0]] + dep[v[i][0]];
      continue;
    }
    sort(v[i].begin(), v[i].end(), cmp);
    tp = 0, stk[0] = 0;
    for (long long j = 1; j < sz; j++) {
      long long LCA = dep[lca(v[i][j - 1], v[i][j])] + 1;
      while (tp && val[tp] >= dep[LCA]) tp--;
      fl[v[i][j]] = fl[v[i][stk[tp]]] + (j - stk[tp]) * LCA;
      stk[++tp] = j, val[tp] = LCA;
    }
    tp = 0, stk[0] = sz - 1;
    for (long long j = sz - 2; j >= 0; j--) {
      long long LCA = dep[lca(v[i][j + 1], v[i][j])] + 1;
      while (tp && val[tp] >= LCA) tp--;
      fr[v[i][j]] = fr[v[i][stk[tp]]] + (stk[tp] - j) * LCA;
      stk[++tp] = j, val[tp] = LCA;
    }
    for (long long j = 0; j < sz; j++)
      f[v[i][j]] =
          f[anc[v[i][j]][0]] + fl[v[i][j]] + fr[v[i][j]] + dep[v[i][j]];
  }
  for (long long i = 1; i <= n; i++) printf("%lld ", f[i]);
  return 0;
}
