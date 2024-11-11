#include <bits/stdc++.h>
using namespace std;
struct Line {
  int u, v, w;
  Line(int U = 0, int V = 0, int W = 0) { u = U, v = V, w = W; }
};
int n, m, fa[200005], mxs[200005], sz[200005], dfn[200005], cnt, top[200005],
    dep[200005], tr[200005], f[200005];
int tot = 0, fir[200005], nxt[200005], to[200005];
vector<Line> line[200005];
inline void addE(int u, int v) {
  nxt[++tot] = fir[u], fir[u] = tot, to[tot] = v;
}
void dfs(int u, int d) {
  dep[u] = d, sz[u] = 1;
  for (register int i = fir[u]; i; i = nxt[i]) {
    dfs(to[i], d + 1), sz[u] += sz[to[i]];
    if (sz[to[i]] > sz[mxs[u]]) mxs[u] = to[i];
  }
}
void dfs2(int u, int t) {
  dfn[u] = ++cnt, top[u] = t;
  if (mxs[u]) dfs2(mxs[u], t);
  for (register int i = fir[u]; i; i = nxt[i])
    if (to[i] != mxs[u]) dfs2(to[i], to[i]);
}
inline int getlca(int x, int y) {
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    x = fa[top[x]];
  }
  if (dep[x] < dep[y]) swap(x, y);
  return y;
}
inline void Modify(int val, int pos) {
  while (pos <= n) tr[pos] += val, pos += pos & (-pos);
}
inline int Query(int posl, int posr) {
  int res = 0;
  --posl;
  while (posr) res += tr[posr], posr -= posr & (-posr);
  while (posl) res -= tr[posl], posl -= posl & (-posl);
  return res;
}
inline int getans(int x, int y) {
  int res = 0;
  while (top[x] != top[y])
    res += Query(dfn[top[x]], dfn[x]) - f[top[x]] + f[mxs[x]], x = fa[top[x]];
  return Query(dfn[y], dfn[x]) + f[mxs[x]];
}
void dp(int u) {
  for (register int i = fir[u]; i; i = nxt[i]) dp(to[i]), f[u] += f[to[i]];
  Modify(f[u] - f[mxs[u]], dfn[u]);
  for (register int i = 0, s = line[u].size(); i < s; ++i) {
    Line now = line[u][i];
    f[u] =
        max(f[u], getans(now.u, u) + getans(now.v, u) - getans(u, u) + now.w);
  }
}
int main() {
  cin >> n >> m;
  for (register int i = 2; i <= n; ++i) scanf("%d", fa + i), addE(fa[i], i);
  dfs(1, 1), dfs2(1, 1);
  for (int i = 1, u, v, w; i <= m; ++i) {
    scanf("%d%d%d", &u, &v, &w);
    line[getlca(u, v)].push_back(Line(u, v, w));
  }
  dp(1), cout << f[1] << endl;
  return 0;
}
