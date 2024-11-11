#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int> > v[100002];
int ind[100002], dp[100002];
int dfs(int i) {
  if (dp[i]) return dp[i];
  dp[i] = 1;
  for (int j = 0; j < v[i].size(); j++) {
    if (dfs(v[i][j].first) + 1 > dp[i]) {
      dp[i] = dp[v[i][j].first] + 1;
      ind[i] = max(ind[v[i][j].first], v[i][j].second);
    }
  }
  return dp[i];
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  int a, b;
  for (int i = 1; i <= m; i++) {
    cin >> a >> b;
    v[a].push_back(make_pair(b, i));
  }
  for (int i = 1; i <= n; i++) {
    if (dfs(i) == n) {
      cout << ind[i] << "\n";
      return 0;
    }
  }
  cout << "-1";
  return 0;
}
