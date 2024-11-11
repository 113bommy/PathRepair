#include <bits/stdc++.h>
using namespace std;
bool vis[100005];
vector<int> g[100005];
int color[100005];
int dfs(int u, int c) {
  vis[u] = true;
  if (color[u] != c) return false;
  int ans = true;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (!vis[v]) ans = ans && dfs(v, c);
  }
  return ans;
}
int main() {
  int nnode, nedge, i, j, x, y, root1 = -1, root2 = -1;
  cin >> nnode;
  for (i = 0; i < nnode - 1; i++) {
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (i = 1; i < nnode + 1; i++) cin >> color[i];
  for (i = 1; i <= nnode; i++)
    for (j = 0; j < g[i].size(); j++)
      if (color[i] != color[g[i][j]]) {
        root1 = i;
        root2 = g[i][j];
      }
  if (root1 == -1) {
    cout << "YES \n1";
    return 0;
  }
  vis[root1] = true;
  for (i = 0; i < g[root1].size(); i++) {
    int v = g[root1][i];
    if (!dfs(v, color[v])) break;
  }
  if (i == g[root1].size()) {
    cout << "YES \n" << root1;
    return 0;
  }
  memset(vis, 0, sizeof(vis));
  vis[root2] = true;
  for (i = 0; i < g[root2].size(); i++) {
    int v = g[root2][i];
    if (!dfs(v, color[v])) break;
  }
  if (i == g[root2].size()) {
    cout << "YES \n" << root2;
    return 0;
  }
  cout << "NO";
}
