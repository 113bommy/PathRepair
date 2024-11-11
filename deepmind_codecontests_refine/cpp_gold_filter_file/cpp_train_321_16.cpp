#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1009];
bool visited[1009], vis[1009], has[1009];
int common = -1;
void init() {
  common = -1;
  for (int i = 0; i < 1009; i++) {
    visited[i] = false;
    vis[i] = false;
    has[i] = false;
    adj[i].clear();
  }
}
void DFS(int node) {
  if (common != -1) return;
  if (visited[node]) {
    common = node;
    return;
  }
  vis[node] = true;
  for (int i = 0; i < adj[node].size(); i++) {
    if (!vis[adj[node][i]]) DFS(adj[node][i]);
  }
}
int main() {
  int test;
  cin >> test;
  while (test--) {
    init();
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    int k1;
    cin >> k1;
    for (int i = 0; i < k1; i++) {
      int x;
      cin >> x;
      visited[x] = true;
    }
    int k2, node;
    cin >> k2;
    for (int i = 0; i < k2; i++) {
      cin >> node;
      has[node] = true;
    }
    cout << "B " << node << "\n";
    int res;
    cin >> res;
    if (visited[res]) {
      cout << "C " << res << "\n";
      cout.flush();
      continue;
    }
    DFS(res);
    cout << "A " << common << "\n";
    cin >> res;
    if (has[res])
      cout << "C " << common << "\n";
    else
      cout << "C -1\n";
    cout.flush();
  }
}
