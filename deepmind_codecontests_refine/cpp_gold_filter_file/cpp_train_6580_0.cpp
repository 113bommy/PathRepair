#include <bits/stdc++.h>
using namespace std;
int n, m;
int a, b;
int hot[200005];
int vis[200005];
int vis2[200005];
vector<int> tot[2];
vector<vector<int>> gra(200005);
void dfs(int u) {
  vis[u] = 1;
  for (auto v : gra[u]) {
    if (v == b && u != a) hot[u] = 1;
    if (!vis[v] && v != b) dfs(v);
    if (hot[v] && u != a) hot[u] = 1;
  }
}
void dfs2(int u) {
  vis2[u] = 1;
  if (u == b || u == a) return;
  hot[u] = 1;
  for (auto v : gra[u]) {
    if (!vis2[v]) dfs2(v);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    cin >> a >> b;
    a--;
    b--;
    for (int i = 0; i < n; i++) gra[i].clear(), vis[i] = hot[i] = vis2[i] = 0;
    for (int i = 0; i < 2; i++) tot[i].clear();
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      gra[x].push_back(y);
      gra[y].push_back(x);
    }
    dfs(a);
    for (int i = 0; i < n; i++)
      if (hot[i] && !vis2[i]) dfs2(i);
    long long left = 0, right = 0;
    for (int i = 0; i < n; i++)
      if (!vis[i] && i != a && i != b) right++;
    for (int i = 0; i < n; i++)
      if (vis[i] && !hot[i] && i != a && i != b) left++;
    long long ans = left * right;
    cout << ans << endl;
  }
}
