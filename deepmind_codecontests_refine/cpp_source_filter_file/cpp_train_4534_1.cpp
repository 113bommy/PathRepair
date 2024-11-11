#include <bits/stdc++.h>
using namespace std;
int ans[100000];
bool visited[100000];
queue<int> q;
bool bfs(vector<int> edges[]) {
  while (!q.empty()) {
    int source = q.front();
    q.pop();
    if (visited[source]) continue;
    visited[source] = true;
    for (int i = 0; i < edges[source].size(); i++) {
      int k = ans[edges[source][i]];
      if (k == -1)
        ans[edges[source][i]] = 1 - ans[source];
      else if (k != (1 - ans[source]))
        return false;
      q.push(edges[source][i]);
    }
  }
  return true;
}
int main() {
  int n, m;
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> m;
  vector<int> edges[n + 1];
  int i;
  for (i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  for (i = 1; i <= n; i++)
    ans[i] = -1, visited[i] = false, edges[i].resize(edges[i].size());
  for (i = 1; i <= n; i++) {
    if (visited[i]) continue;
    q.push(i);
    ans[i] = 0;
    bool isthere = bfs(edges);
    if (!isthere) {
      cout << i;
      return 0;
    }
  }
  int inf = 0, ins = 0;
  for (i = 1; i <= n; i++) ans[i] == 0 ? inf++ : ins++;
  cout << inf << '\n';
  for (i = 1; i <= n; i++)
    if (ans[i] == 0) cout << i << ' ';
  cout << '\n' << ins << '\n';
  for (i = 1; i <= n; i++) {
    if (ans[i]) cout << i << ' ';
  }
}
