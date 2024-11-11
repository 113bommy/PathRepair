#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100005];
int visited[100005];
int dfs(int s, int p) {
  visited[s] = 1;
  int t = 1;
  for (typeof((adj[s]).begin()) it = (adj[s]).begin(); it != (adj[s]).end();
       it++) {
    if (!visited[*it])
      t = t & dfs(*it, s);
    else if (*it != p)
      return 0;
  }
  return t;
}
int main() {
  int u, v, i, j, k, V, E;
  cin >> V >> E;
  for (i = 0; i < E; i++) {
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (i = 0; i < V; i++) visited[i] = 0;
  int count = 0;
  for (i = 0; i < V; i++)
    if (!visited[i]) count += dfs(i, -1);
  cout << count << endl;
  return 0;
}
