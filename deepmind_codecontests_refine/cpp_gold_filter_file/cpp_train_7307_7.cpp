#include <bits/stdc++.h>
using namespace std;
int n, k, b, N = 220;
int dp[225][225];
vector<vector<int> > adj;
vector<int> w;
void dfs(int a, int p) {
  int dis, i, j;
  dp[a][0] = w[a];
  for (i = 0; i < adj[a].size(); i++)
    if (adj[a][i] != p) dfs(adj[a][i], a);
  for (dis = 0; dis < N; dis++) {
    if (dis == 0) {
      for (i = 0; i < adj[a].size(); i++)
        if (adj[a][i] != p) dp[a][dis] += dp[adj[a][i]][max(0, k - 1)];
    } else
      for (i = 0; i < adj[a].size(); i++) {
        int to = adj[a][i];
        if (to == p) continue;
        int sum = dp[to][dis - 1];
        for (j = 0; j < adj[a].size(); j++) {
          if (adj[a][j] == to || adj[a][j] == p) continue;
          sum += dp[adj[a][j]][max(dis - 1, k - 1 - dis)];
        }
        dp[a][dis] = max(sum, dp[a][dis]);
      }
  }
  for (dis = N - 1; dis >= 0; dis--)
    dp[a][dis] = max(dp[a][dis], dp[a][dis + 1]);
}
int main() {
  cin >> n >> k;
  int a, i;
  adj = vector<vector<int> >(n);
  w = vector<int>(n);
  for (i = 0; i < n; i++) cin >> w[i];
  for (i = 0; i < n - 1; i++) {
    cin >> a >> b;
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  k++;
  dfs(0, -1);
  cout << dp[0][0];
}
