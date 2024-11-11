#include <bits/stdc++.h>
using namespace std;
vector<int> adj[30005];
bool vis[30005];
void dfs(int curr) {
  if (vis[curr]) return;
  vis[curr] = true;
  for (int i = 0; i < adj[curr].size(); i++) dfs(adj[curr][i]);
  cout << curr << " ";
}
int main() {
  int n, m, u, v;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
  }
  memset(vis, false, sizeof vis);
  for (int i = 1; i < n + 1; i++)
    if (!vis[i]) dfs(i);
  cout << endl;
  return 0;
}
