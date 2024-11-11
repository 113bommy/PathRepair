#include <bits/stdc++.h>
using namespace std;
int m, n;
int dp[45][64][64];
int main() {
  cin >> m >> n;
  if (n < m) swap(m, n);
  memset(dp, 63, sizeof(dp));
  int g = (1 << m);
  for (int k = 0; k < g; k++) dp[1][0][k] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < g; j++) {
      for (int k = 0; k < g; k++) {
        if (dp[i][j][k] == 63) continue;
        for (int z = 0; z < g; z++) {
          int t = j | k | z | ((k << 1) % g) | (k >> 1);
          t = (g - 1) & t;
          if (t == (g - 1))
            dp[i + 1][k][z] =
                min(dp[i + 1][k][z], dp[i][j][k] + __builtin_popcount(k));
        }
      }
    }
  }
  int ans = n * m;
  for (int i = 0; i < (1 << m); i++) ans = min(ans, dp[n + 1][i][0]);
  cout << n * m - ans;
  return 0;
}
