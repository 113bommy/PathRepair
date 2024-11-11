#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
set<int> adj[N];
bool visited[N];
int disc[N], low[N], freq[N], id[N], cntr, ans;
vector<pair<int, int> > bridge;
vector<int> B[N];
void dfs_bridge(int u, int prev) {
  visited[u] = true;
  disc[u] = ++cntr, low[u] = disc[u];
  for (auto v : adj[u]) {
    if (v == prev) continue;
    if (!visited[v]) {
      dfs_bridge(v, u);
      if (low[v] > disc[u]) bridge.push_back({u, v});
    }
    low[u] = min(low[u], low[v]);
  }
}
void dfs_id(int u) {
  visited[u] = 1;
  id[u] = cntr;
  freq[cntr]++;
  for (auto v : adj[u])
    if (!visited[v]) dfs_id(v);
}
bool ok;
void dfs_ans(int u) {
  if (freq[u] != 1) ok = 0;
  visited[u] = 1;
  for (auto v : B[u])
    if (!visited[v]) dfs_ans(v);
}
int main() {
  int n, m, u, v;
  cin >> n >> m;
  while (m--) {
    cin >> u >> v;
    adj[u].insert(v);
    adj[v].insert(u);
  }
  for (int i = 1; i <= n; i++)
    if (!visited[i]) dfs_bridge(i, 0);
  for (auto v : bridge) {
    adj[v.first].erase(v.second);
    adj[v.second].erase(v.first);
  }
  cntr = 0;
  for (int i = 1; i <= n; i++) visited[i] = 0;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      cntr++;
      dfs_id(i);
    }
  }
  for (auto v : bridge) {
    int a = id[v.first], b = id[v.second];
    B[a].push_back(b);
    B[b].push_back(a);
  }
  for (int i = 1; i <= cntr; i++) visited[i] = 0;
  for (int i = 1; i <= cntr; i++) {
    if (!visited[i]) {
      ok = 1;
      dfs_ans(i);
      if (ok == 1) ans++;
    }
  }
  cout << ans;
}
