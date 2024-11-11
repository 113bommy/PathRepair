#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
int n;
long long dp[MAXN][2], v[MAXN];
bool mark[MAXN];
vector<int> adj[MAXN];
void dfs(int sou) {
  mark[sou] = true, dp[sou][1] = -MAXN;
  for (auto &u : adj[sou]) {
    if (mark[u]) continue;
    dfs(u);
    int x = dp[sou][0], y = dp[sou][1];
    dp[sou][0] = max(x + dp[u][0], y + dp[u][1]);
    dp[sou][1] = max(y + dp[u][0], x + dp[u][1]);
  }
  dp[sou][1] = max(dp[sou][0] + v[sou], dp[sou][1]);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x >> v[i];
    if (x > 0) adj[i].push_back(x), adj[x].push_back(i);
  }
  dfs(1);
  cout << max(dp[1][1], dp[1][0]);
  return 0;
}
