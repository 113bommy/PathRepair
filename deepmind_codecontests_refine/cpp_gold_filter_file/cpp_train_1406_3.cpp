#include <bits/stdc++.h>
using namespace std;
const int maxn = 5001, inf = 1e8;
int dp[maxn][maxn][2], sts[maxn], n;
vector<int> graph[maxn];
void dfs(int u, int prev) {
  sts[u] = 1;
  for (int i : graph[u])
    if (i != prev) {
      dfs(i, u);
      sts[u] += sts[i];
    }
  for (int i = 0; i < 2; i++) dp[u][graph[u].size() == 1 && i == 0][i] = 0;
  int mx = 1, tmp;
  for (int i : graph[u]) {
    if (i != prev)
      for (int j = mx; ~j; j--)
        for (int k = 0; k < 2; k++)
          if (dp[u][j][k] < n) {
            tmp = dp[u][j][k];
            dp[u][j][k] = inf;
            for (int I = 0; I <= sts[i]; I++)
              for (int J = 0; J < 2; J++)
                dp[u][j + I][k] =
                    min(dp[u][j + I][k], dp[i][I][J] + tmp + (k != J));
          }
    mx += sts[i];
  }
}
int main() {
  cin >> n;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      for (int k = 0; k < 2; k++) dp[i][j][k] = inf;
  int u, v;
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  int leaves = 0;
  for (int i = 1; i <= n; i++)
    if (graph[i].size() == 1) leaves++;
  dfs(1, -1);
  cout << min(dp[1][leaves / 2][0], dp[1][leaves / 2][1]) << endl;
}
