#include <bits/stdc++.h>
using namespace std;
int dp[100009], in[100009];
vector<int> v[100009];
int dfs(int x) {
  if (dp[x] != -1) return dp[x];
  dp[x] = 0;
  for (int i = 0; i < v[x].size(); i++) {
    if (in[v[x][i]])
      dp[x] = max(dp[x], dfs(v[x][i]));
    else
      dp[x] = max(dp[x], dfs(v[x][i]) + in[x]);
  }
  if (v[x].size() == 0) dp[x] = in[x];
  return dp[x];
}
int n, m;
int main() {
  memset(dp, -1, sizeof(dp));
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> in[i];
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    v[y].push_back(x);
  }
  int mx = 0;
  for (int i = 0; i < n; i++) {
    mx = max(mx, dfs(i));
  }
  cout << mx;
}
