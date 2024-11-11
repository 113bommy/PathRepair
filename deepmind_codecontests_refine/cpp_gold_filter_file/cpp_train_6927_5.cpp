#include <bits/stdc++.h>
using namespace std;
int const N = 5555;
int n, m, col, ans, t;
int dis[2][N], c[N], mn[N], sc[N];
vector<int> g[2][N], to;
bool vis[N], snc[N];
queue<int> q;
void tpl(int v) {
  vis[v] = 1;
  for (int u : g[1][v])
    if (!vis[u]) tpl(u);
  to.push_back(v);
}
void rdfs(int v) {
  vis[v] = 1;
  c[v] = col;
  t++;
  for (int u : g[0][v])
    if (!vis[u]) rdfs(u);
}
void bfs(int v, int b) {
  q.push(v);
  dis[b][v] = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : g[b][v])
      if (!vis[u]) vis[u] = 1, dis[b][u] = dis[b][v] + 1, q.push(u);
  }
}
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  memset(mn, 127, sizeof(mn));
  int INF = mn[0];
  cin >> n >> m;
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    g[1][u].push_back(v);
    g[0][v].push_back(u);
  }
  for (int v = 0; v < n; v++)
    if (!vis[v]) tpl(v);
  reverse(to.begin(), to.end());
  memset(vis, 0, sizeof(vis));
  for (int v : to) {
    if (vis[v]) continue;
    t = 0;
    rdfs(v);
    sc[col] = t;
    col++;
  }
  memset(vis, 0, sizeof(vis));
  for (int v = 0; v < n; v++)
    for (int u : g[1][v])
      if (c[u] != c[v] && sc[c[v]] > 1) snc[c[v]] = 1;
  for (int v = 0; v < n; v++) {
    if (snc[c[v]]) continue;
    memset(vis, 0, sizeof(vis));
    memset(dis, 63, sizeof(dis));
    bfs(v, 1);
    memset(vis, 0, sizeof(vis));
    bfs(v, 0);
    for (int u = 0; u < n; u++)
      if (u != v) mn[c[v]] = min(mn[c[v]], dis[0][u] + dis[1][u]);
  }
  for (int i = 0; i < col; i++)
    if (!snc[i] && sc[i] > 1) ans += 998 * mn[i] + 1;
  cout << ans + n;
}
