#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
vector<int> G[N];
int dp[2][N];
int dis[N];
int tree_d;
void dfs(int u, int pre) {
  for (int v : G[u]) {
    if (v == pre) continue;
    dis[v] = dis[u] + 1;
    dfs(v, u);
    if (dp[0][v] + 1 > dp[0][u]) {
      dp[1][u] = dp[0][u];
      dp[0][u] = dp[0][v] + 1;
    } else if (dp[0][v] + 1 > dp[1][u]) {
      dp[1][u] = dp[0][v] + 1;
    }
  }
  tree_d = max(dp[0][u] + dp[1][u], tree_d);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    tree_d = 0;
    for (int i = 0; i <= n; i++) {
      dis[i] = dp[0][i] = dp[1][i] = 0;
      G[i].clear();
    }
    for (int i = 1; i < n; i++) {
      int x, y;
      cin >> x >> y;
      G[x].push_back(y);
      G[y].push_back(x);
    }
    dfs(a, 0);
    if (dis[b] <= da) {
      cout << "Alice" << endl;
      continue;
    }
    if (2 * da >= db) {
      cout << "Alice" << endl;
      continue;
    }
    if (tree_d <= 2 * da) {
      cout << "Alice" << endl;
      continue;
    }
    cout << "Bob" << endl;
  }
  return 0;
}
