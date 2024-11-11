#include <bits/stdc++.h>
using namespace std;
long long dist[85][85], dp[15][85];
int c[85];
int n, k;
long long ans = 0xfffffffffffffff;
void solve() {
  for (int i = 0; i < 15; i++)
    for (int j = 1; j <= 80; j++) dp[i][j] = 0xfffffffffffffff;
  dp[0][1] = 0;
  for (int p = 1; p <= k; p++)
    for (int u = 1; u <= n; u++)
      for (int v = 1; v <= n; v++)
        if (c[u] != c[v] && dp[p - 1][u] != 0xfffffffffffffff)
          dp[p][v] = min(dp[p][v], dp[p - 1][u] + dist[u][v]);
  ans = min(ans, dp[k][1]);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &dist[i][j]);
  int t = 4687;
  srand(time(0));
  while (t--) {
    for (int i = 1; i <= n; i++) c[i] = rand() % 2;
    solve();
  }
  printf("%d", ans);
  return 0;
}
