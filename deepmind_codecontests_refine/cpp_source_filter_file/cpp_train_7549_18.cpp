#include <bits/stdc++.h>
using namespace std;
int dp[100001];
int res[100001];
vector<vector<pair<int, int> > > g(1e5 + 2);
int check(int v) {
  if (dp[v]) {
    return dp[v];
  }
  dp[v] = 1;
  for (int i = 0; i < g[v].size(); i++) {
    int nxt = g[v][i].first;
    if (check(nxt) + 1 > dp[v]) {
      dp[v] = dp[nxt] + 1;
      res[v] = max(res[v], g[v][i].second);
    }
  }
  return dp[v];
}
int main() {
  int n, m, v, v1;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> v >> v1;
    g[--v].push_back({--v1, i + 1});
  }
  for (int i = 0; i < n; i++) {
    if (check(i) == n) {
      cout << res[i];
      return 0;
    }
  }
  cout << -1;
  return 0;
}
