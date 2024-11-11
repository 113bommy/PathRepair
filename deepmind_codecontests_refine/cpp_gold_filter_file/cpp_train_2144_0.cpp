#include <bits/stdc++.h>
using namespace std;
int dp[81][81][81][81];
vector<pair<int, int>> graph[81];
int solve(int v, int l, int r, int k) {
  if (k == 0) return 0;
  if (dp[v][l][r][k] != -1) return dp[v][l][r][k];
  int &ret = dp[v][l][r][k];
  ret = 1000000;
  for (auto e : graph[v]) {
    int w = e.second;
    int u = e.first;
    if (u < r && u > v) {
      ret = min(ret, solve(u, v, r, k - 1) + w);
    }
    if (u > l && u < v) {
      ret = min(ret, solve(u, l, v, k - 1) + w);
    }
  }
  return ret;
}
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    graph[a].push_back({b, c});
  }
  int ans = 1000000;
  memset(dp, -1, sizeof dp);
  for (int i = 1; i <= n; i++) {
    ans = min(ans, solve(i, 0, n + 1, k - 1));
  }
  printf("%d\n", ans >= 1000000 ? -1 : ans);
  return 0;
}
