#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int M = 3005;
const int inf = 1e9 + 9;
array<int, 3> ship[M];
array<int, 2> base[M];
vector<int> g[M];
int s, b, k, h, n, m, match[M], dist[M], d[N][N], vis[M];
bool dfs(int u) {
  if (vis[u]) return false;
  vis[u] = 1;
  for (int v : g[u]) {
    if (match[v] == 0 || dfs(match[v])) {
      match[v] = u;
      return true;
    }
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      d[i][j] = inf;
    }
    d[i][i] = 0;
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    if (u == v) continue;
    d[u][v] = d[v][u] = 1;
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  cin >> s >> b >> k >> h;
  for (int i = 1; i <= s; i++) {
    cin >> ship[i][0] >> ship[i][1] >> ship[i][2];
  }
  for (int i = 1; i <= b; i++) {
    cin >> base[i][0] >> base[i][1];
  }
  for (int i = 1; i <= s; i++) {
    for (int j = 1; j <= b; j++) {
      int x = ship[i][0];
      int y = base[j][0];
      if (d[x][y] <= ship[i][2] && base[i][1] <= ship[i][1]) {
        g[i].push_back(s + j);
        g[s + j].push_back(i);
      }
    }
  }
  int matching = 0;
  memset(match, 0, sizeof(match));
  for (int i = 1; i <= s; i++) {
    memset(vis, 0, sizeof(vis));
    if (dfs(i)) matching++;
  }
  cout << min(matching * 1LL * k, s * 1LL * h) << '\n';
  return 0;
}
