#include <bits/stdc++.h>
using namespace std;
void dfs(long int node, const vector<vector<long int>> &adjG,
         vector<bool> &visited, const vector<long int> &bribe,
         long int &minBride) {
  visited[node] = true;
  minBride = min(minBride, bribe[node]);
  for (const auto &n : adjG[node]) {
    if (!visited[n]) dfs(n, adjG, visited, bribe, minBride);
  }
}
int main() {
  long int n, m, u, v;
  cin >> n >> m;
  vector<long int> bribe(n);
  for (auto &e : bribe) cin >> e;
  vector<vector<long int>> adjG(n);
  while (m--) {
    cin >> u >> v;
    adjG[--u].push_back(--v);
    adjG[v].push_back(u);
  }
  vector<bool> visited(n, false);
  long long int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      long int minC = 1e9 + 1;
      dfs(i, adjG, visited, bribe, minC);
      ans += minC;
    }
  }
  cout << ans;
  return 0;
}
