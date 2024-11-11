#include <bits/stdc++.h>
using namespace std;
const double PI = 4 * atan(1);
const long long INF = 1e18;
const int MX = 100001;
const int maxn = 1e5 + 5;
int n;
vector<int> adj[maxn];
int par[maxn], deg[maxn], depth[maxn];
int visited[maxn];
void merge(int u, int v) { par[v] = u; }
void dfs(int u, int p) {
  for (int v : adj[u]) {
    if (v != p) {
      depth[v] = depth[u] + 1;
      dfs(v, u);
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    par[i] = i;
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    deg[i] = adj[i].size();
  }
  dfs(1, 1);
  int parities[2] = {0, 0};
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 1) {
      parities[depth[i] % 2] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    vector<int> leaves;
    for (int v : adj[i]) {
      if (deg[v] == 1) {
        leaves.push_back(v);
      }
    }
    int numl = leaves.size();
    for (int i = 1; i < numl; i++) {
      merge(leaves[0], leaves[i]);
    }
  }
  int num_nodes = 0;
  for (int i = 1; i <= n; i++) {
    if (!visited[par[i]]) {
      visited[par[i]] = 1;
      num_nodes++;
    }
  }
  int minans;
  if (parities[0] && parities[1])
    minans = 3;
  else
    minans = 1;
  cout << minans << " ";
  cout << num_nodes - 1 << "\n";
}
