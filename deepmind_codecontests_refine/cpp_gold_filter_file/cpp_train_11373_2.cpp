#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, ans, vis[200010];
bool vs[200010][2];
vector<int> g[200010][2];
string anss;
void dfs1(int u) {
  if (vis[u] == 1) {
    cout << -1 << '\n';
    exit(0);
  }
  if (vis[u] == 2) return;
  vis[u] = 1;
  for (int v : g[u][0]) dfs1(v);
  vis[u] = 2;
  return;
}
void dfs2(int u, int p) {
  if (vs[u][p]) return;
  vs[u][p] = 1;
  for (int v : g[u][p]) dfs2(v, p);
}
int main() {
  cin >> n >> m;
  for (int i = (0); i < (m); i++) {
    cin >> x >> y;
    g[x][0].push_back(y);
    g[y][1].push_back(x);
  }
  for (int i = (1); i < (n + 1); i++)
    if (!vis[i]) dfs1(i);
  for (int i = (1); i < (n + 1); i++) {
    if (!vs[i][0] && !vs[i][1]) {
      ans++;
      anss += 'A';
    } else
      anss += 'E';
    dfs2(i, 0), dfs2(i, 1);
  }
  cout << ans << '\n';
  cout << anss << '\n';
  return 0;
}
