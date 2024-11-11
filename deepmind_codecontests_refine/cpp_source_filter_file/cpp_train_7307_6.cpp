#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<vector<int>> edges;
vector<int> a;
vector<vector<int>> dp;
void dfs(int u, int p) {
  for (int v : edges[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
  for (int dep = 0; dep < n; dep++) {
    if (dep == 0) {
      dp[u][dep] = a[u];
      for (int v : edges[u]) {
        if (v == p) continue;
        dp[u][dep] += dp[v][k - 1];
      }
    } else {
      for (int to : edges[u]) {
        if (to == p) continue;
        int res = dp[to][dep - 1];
        for (int v : edges[u]) {
          if (v == p or v == to) continue;
          res += dp[v][max(dep - 1, k - dep - 1)];
        }
        dp[u][dep] = max(dp[u][dep], res);
      }
    }
  }
  for (int dep = n - 1; dep > 0; dep--) {
    dp[u][dep - 1] = max(dp[u][dep - 1], dp[u][dep]);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  ++k;
  a.resize(n);
  edges.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    edges[x].push_back(y);
    edges[y].push_back(x);
  }
  dp = vector<vector<int>>(n, vector<int>(n));
  dfs(0, -1);
  cout << dp[0][0] << '\n';
}
