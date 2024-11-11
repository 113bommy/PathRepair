#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int dp[1002][2][33][33][33];
int n, h;
void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
int main() {
  cin >> n >> h;
  n++;
  dp[1][1][0][0][0] = 1;
  int ans = 0;
  for (int i = 1; i < n; i++)
    for (int ok : {0, 1})
      for (int p1 = 0; p1 <= h; p1++)
        for (int p2 = 0; p2 <= h; p2++)
          for (int p3 = 0; p3 <= h; p3++) {
            add(dp[i + 1][ok][min(p1 + 1, h)][min(p2 + 1, h)][min(p3 + 1, h)],
                dp[i][ok][p1][p2][p3]);
            add(dp[i + 1][p1 < h][(ok ? 1 : h)][min(p2 + 1, h)][min(p3 + 1, h)],
                dp[i][ok][p1][p2][p3]);
            add(dp[i + 1][p2 < h][min(p1 + 1, h)][(ok ? 1 : h)][min(p3 + 1, h)],
                dp[i][ok][p1][p2][p3]);
            add(dp[i + 1][p3 < h][min(p1 + 1, h)][min(p2 + 1, h)][(ok ? 1 : h)],
                dp[i][ok][p1][p2][p3]);
          }
  for (int ok : {0, 1})
    for (int i = 0; i <= h; i++)
      for (int j = 0; j <= h; j++)
        for (int k = 0; k <= h; k++)
          if (i < h || j < h || k < h || ok) add(ans, dp[n][ok][i][j][k]);
  cout << ans;
  return 0;
}
