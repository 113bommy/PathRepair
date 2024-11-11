#include <bits/stdc++.h>
using namespace std;
long long p2[61], dp[61][500][2];
bitset<500> mat[2][61][500];
int main() {
  ios::sync_with_stdio(0);
  p2[0] = 1;
  for (int i = 1; i < 61; i++) p2[i] = (p2[i - 1] * 2ll);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int v, u, t;
    cin >> v >> u >> t;
    v--, u--;
    dp[0][v][t] = 1;
    mat[t][0][v][u] = 1;
  }
  for (int i = 1; i < 61; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (mat[0][i - 1][j][k]) mat[0][i][j] |= mat[1][i - 1][k];
        if (mat[1][i - 1][j][k]) mat[1][i][j] |= mat[0][i - 1][k];
      }
    }
  }
  bool failed = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (mat[0][60][i][j]) failed = true;
    }
  }
  long long ans = -1;
  if (!failed) {
    ans = 0;
    for (int i = 1; i < 60; i++) {
      for (int j = 0; j < n; j++) {
        dp[i][j][0] = dp[i - 1][j][0];
        dp[i][j][1] = dp[i - 1][j][1];
        for (int k = 0; k < n; k++) {
          if (mat[0][i][j][k])
            dp[i][j][0] = max(dp[i][j][0], (1ll << i) + dp[i - 1][k][1]);
          if (mat[1][i][j][k])
            dp[i][j][1] = max(dp[i][j][1], (1ll << i) + dp[i - 1][k][0]);
        }
      }
    }
    for (int i = 0; i < 60; i++)
      for (int j = 0; j < n; j++) ans = max(ans, dp[i][j][0]);
  }
  if (ans > 1000000000000000000ll)
    cout << "-1";
  else
    cout << ans;
  return 0;
}
