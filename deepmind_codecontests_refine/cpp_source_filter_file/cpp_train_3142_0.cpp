#include <bits/stdc++.h>
using namespace std;
bool g[20][20];
long long dp[1 << 20][20];
int low[1 << 20];
int main() {
  int n, m;
  long long ans = 0;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--, b--;
    g[a][b] = g[b][a] = 1;
  }
  for (int i = 1; i < (1 << n); i++) {
    int j;
    for (j = 0;; j++)
      if ((1 << j) & i) break;
    low[i] = j;
  }
  for (int i = 0; i < n; i++) dp[1 << i][i] = 1;
  for (int i = 1; i < (1 << n); i++)
    for (int j = 0; j < n; j++)
      if (dp[i][j])
        for (int k = low[i]; k < n; k++)
          if (!((1 << k) & i) && g[j][k]) dp[i | (1 << k)][k] += dp[i][j];
  for (int i = 1; i < (1 << n); i++)
    if (__builtin_popcount(i) >= 3)
      for (int j = 0; j < n; j++)
        if (g[j][low[i]]) ans += dp[i][j];
  printf("%d\n", ans / 2);
  return 0;
}
