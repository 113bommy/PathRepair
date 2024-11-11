#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > ad[100004];
int dp[100004] = {0}, res[100004] = {0};
inline int dfs(int v) {
  if (dp[v]) return dp[v];
  dp[v] = 1;
  for (auto x : ad[v]) {
    if (dfs(x.first) + 1 > dp[v]) {
      dp[v] = dfs(x.first) + 1;
      res[v] = max(res[x.first], x.second);
    }
  }
  return dp[v];
}
inline void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d", &x), scanf("%d", &y);
    x--, y--;
    ad[x].push_back(make_pair(y, i + 1));
  }
  for (int i = 0; i < n; i++) {
    if (dp[i] == n) {
      cout << res[i];
      return;
    }
  }
  puts("-1");
}
int main() {
  int t = 1;
  while (t--) solve();
  return 0;
}
