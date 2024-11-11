#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 10;
long long v, u, n, ans, dp[MAXN], k, _2k;
vector<int> adj_matrix[MAXN];
void dfs(int v, int p) {
  for (int u : adj_matrix[v]) {
    if (u != p) dfs(u, v);
  }
  for (int u : adj_matrix[v]) {
    if (u != p) dp[v] += dp[u];
  }
  if (2 * dp[v] <= _2k)
    ans += dp[v];
  else
    ans += (_2k - dp[v]);
  return;
}
int main() {
  cin >> n >> k;
  _2k = k * 2;
  for (int i = 0; i < _2k; i++) {
    cin >> v;
    dp[v]++;
  }
  for (int i = 1; i <= (n - 1); i++) {
    cin >> v >> u;
    adj_matrix[v].push_back(u);
    adj_matrix[u].push_back(v);
  }
  dfs(1, 1);
  cout << ans;
  return 0;
}
