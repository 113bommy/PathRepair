#include <bits/stdc++.h>
using namespace std;
void dfs(int &max_index, int &max_dis, int s, int n, vector<vector<int>> &adj) {
  vector<bool> visited(n, false);
  vector<int> d(n);
  visited[s] = true;
  d[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : adj[v]) {
      if (!visited[u]) {
        visited[u] = true;
        q.push(u);
        d[u] = d[v] + 1;
        if (d[u] > max_dis) {
          max_dis = d[u];
          max_index = u;
        }
      }
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int max_index = -1, max_dis = -1;
  dfs(max_index, max_dis, 0, n, adj);
  int ans = -1, y = max_index;
  max_index = -1;
  dfs(max_index, ans, y, n, adj);
  cout << ans;
}
