#include <bits/stdc++.h>
using namespace std;
const int N = 35, P = 1000000009;
using ll = long long;
int n, h;
ll dp[2][N][N][N][2];
inline int M(int x) { return min(x, h); }
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> h;
  dp[1][1][1][1][1] = 4;
  for (int i = 2; i <= n; i++) {
    memset(dp[i & 1], 0, sizeof(dp[i & 1]));
    for (int j1 = 1; j1 <= h; j1++)
      for (int j2 = 1; j2 <= h; j2++)
        for (int j3 = 1; j3 <= h; j3++)
          for (int k = 0; k < 2; k++) {
            auto &d = dp[(i - 1) & 1][j1][j2][j3][k];
            d %= P;
            if (!d) continue;
            int j4 = k ? 0 : h;
            dp[i & 1][M(j2 + 1)][M(j3 + 1)][M(j4 + 1)][j1 < h] += d;
            dp[i & 1][M(j1 + 1)][M(j3 + 1)][M(j4 + 1)][j2 < h] += d;
            dp[i & 1][M(j1 + 1)][M(j2 + 1)][M(j4 + 1)][j3 < h] += d;
            dp[i & 1][M(j1 + 1)][M(j2 + 1)][M(j3 + 1)][k] += d;
          }
  }
  ll ans = 0;
  for (int i = 1; i <= h; i++)
    for (int j = 1; j <= h; j++)
      for (int k = 1; k <= h; k++)
        for (int l = 0; l < 2; l++)
          if (i < h || j < h || k < h || l)
            ans = (ans + dp[n & 1][i][j][k][l]) % P;
  cout << ans << endl;
  return 0;
}
