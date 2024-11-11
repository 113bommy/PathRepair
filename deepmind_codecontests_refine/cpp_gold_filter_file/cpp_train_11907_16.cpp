#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m;
int num[N];
double dp[N][N];
int main() {
  cin >> n >> m;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++) dp[i][j] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) dp[i][j] = num[i] > num[j];
  int u, v;
  while (m--) {
    cin >> u >> v;
    dp[u][v] = dp[v][u] = 0.5;
    for (int i = 1; i <= n; i++)
      if (i != u && i != v)
        dp[i][v] = dp[i][u] = dp[i][u] * 0.5 + dp[i][v] * 0.5;
    dp[u][v] = dp[v][u] = 0.5;
    for (int i = 1; i <= n; i++) {
      dp[v][i] = 1 - dp[i][v];
      dp[u][i] = 1 - dp[i][u];
    }
  }
  double ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) ans += dp[i][j];
  printf("%.7lf\n", ans);
}
