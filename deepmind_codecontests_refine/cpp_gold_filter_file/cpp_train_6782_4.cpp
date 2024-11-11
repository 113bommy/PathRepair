#include <bits/stdc++.h>
using namespace std;
const int N = 55, inF = 1e9 + 100;
int n, h, m, l[N], r[N], x[N], c[N], dp[N][N][N];
int get(int i, int j, int dex, int h) {
  int res = 0;
  for (int q = 0; q < m; q++)
    if (l[q] <= dex && l[q] >= i && r[q] <= j && r[q] >= dex && x[q] < h)
      res += c[q];
  return res;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n >> h >> m;
  for (int i = 0; i < m; i++) cin >> l[i] >> r[i] >> x[i] >> c[i];
  for (int k = 1; k <= h; k++)
    for (int l = 1; l <= n; l++)
      for (int i = 1; i + l - 1 <= n; i++) {
        int j = i + l - 1;
        dp[i][j][k] = dp[i][j][k - 1];
        for (int dex = i; dex <= j; dex++)
          dp[i][j][k] =
              max(dp[i][j][k], dp[i][dex - 1][k - 1] + dp[dex + 1][j][k] +
                                   k * k - get(i, j, dex, k));
      }
  cout << dp[1][n][h];
  return 0;
}
