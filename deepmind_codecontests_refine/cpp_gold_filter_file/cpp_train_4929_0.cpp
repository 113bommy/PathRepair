#include <bits/stdc++.h>
using namespace std;
using namespace std;
int g[70][70][70];
int dp[70][70][70];
void solve() {
  int n, m, r;
  scanf("%d%d%d", &n, &m, &r);
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        scanf("%d", &g[i][j][k]);
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        for (int u = 1; u <= n; u++) {
          g[i][k][u] = min(g[i][k][u], g[i][k][j] + g[i][j][u]);
        }
      }
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        dp[i][j][k] = 1000000007;
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        for (int u = 1; u <= n; u++) {
          dp[0][k][u] = min(dp[0][k][u], g[i][k][u]);
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        for (int u = 1; u <= n; u++) {
          dp[i][k][u] = min(dp[i][k][u], dp[i - 1][k][j] + dp[0][j][u]);
        }
      }
    }
  }
  while (r--) {
    int s, e, k;
    int ans = 1000000007;
    scanf("%d%d%d", &s, &e, &k);
    k = min(n, k);
    for (int i = 0; i <= k; i++) ans = min(ans, dp[i][s][e]);
    printf("%d\n", ans);
  }
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
}
