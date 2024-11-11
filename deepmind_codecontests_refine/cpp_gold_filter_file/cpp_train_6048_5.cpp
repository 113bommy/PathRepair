#include <bits/stdc++.h>
using namespace std;
int n, m, pr[300010];
long long d[300010], p[300010];
struct edge {
  int v, w;
};
vector<edge> g[300010];
void dfs(int x, int f) {
  if (x == n) pr[x] = n + 1;
  for (int i = 0, v, w; i < g[x].size(); i++) {
    v = g[x][i].v;
    w = g[x][i].w;
    if (v == f) continue;
    dfs(v, x);
    if (pr[v]) pr[x] = v, p[x] = p[v] + w;
  }
}
bool fl;
int dfs2(int x, int f) {
  int s = 1;
  for (int i = 0, v, w; i < g[x].size(); i++) {
    v = g[x][i].v;
    w = g[x][i].w;
    if (v == f || pr[v]) continue;
    s += dfs2(v, x);
    d[x] = w;
  }
  fl |= (s > 2);
  return s;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, u, v, w; i < n; i++) {
    scanf("%d%d%d", &u, &v, &w);
    g[u].push_back((edge){v, w});
    g[v].push_back((edge){u, w});
  }
  dfs(1, 0);
  long long mx = -1e16, ans = 0, nxt = 0;
  for (int i = 1; i <= n; i = pr[i]) {
    dfs2(i, 0);
    ans = max(ans, p[i] + d[i] + mx + p[1]);
    if (nxt && (d[i] || d[nxt]))
      ans = max(ans, p[i] + d[i] + d[nxt] - p[nxt] + p[1]);
    if (nxt) mx = max(mx, d[nxt] - p[nxt]);
    nxt = i;
  }
  for (int i = 0, x; i < m; i++) {
    scanf("%d", &x);
    if (fl)
      printf("%lld\n", p[1]);
    else
      printf("%lld\n", min(p[1], ans + x));
  }
  return 0;
}
