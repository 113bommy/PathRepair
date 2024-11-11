#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
unordered_set<int> adj[N], G[N];
unordered_map<int, unordered_map<int, int>> mp;
int D[N], idx = -1, odd = 0;
bool vis[N];
void dfs(int u) {
  for (int v : adj[u])
    if (!vis[v]) {
      vis[v] = true;
      G[u].insert(v);
      G[v].insert(u);
      dfs(v);
    }
}
void solve(int u, int p) {
  unordered_set<int> tmp = G[u];
  for (int v : tmp)
    if (v != p) {
      solve(v, u);
    }
  if (((int)G[u].size() % 2 == 1 && D[u] == 0) ||
      ((int)G[u].size() % 2 == 0 && D[u] == 1)) {
    G[u].erase(p);
    G[p].erase(u);
  }
}
int main() {
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i < int(n + 1); i++) {
    cin >> D[i];
    if (D[i] == -1) idx = i;
    odd += (D[i] == 1);
  }
  if (odd % 2 && idx == -1) {
    cout << -1;
  } else {
    if (odd % 2) D[idx] = 1;
    for (int i = 1; i < int(n + 1); i++)
      if (D[i] == -1) D[i] = 0;
    for (int i = 1; i < int(n + 1); i++)
      if (i != idx && D[i] == -1) D[i] = 0;
    for (int i = 0; i < int(m); i++) {
      int u, v;
      cin >> u >> v;
      adj[u].insert(v);
      adj[v].insert(u);
      mp[u][v] = mp[v][u] = i + 1;
    }
    vis[1] = true;
    dfs(1);
    solve(1, 0);
    unordered_set<int> ans;
    for (int i = 1; i < int(n + 1); i++)
      for (int j : G[i]) ans.insert(mp[i][j]);
    cout << ans.size() << '\n';
    for (int i : ans) cout << i << '\n';
  }
  return 0;
}
