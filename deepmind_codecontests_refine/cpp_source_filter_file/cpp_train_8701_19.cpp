#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int a[maxn], b[maxn];
int dp[2][maxn][55][55];
inline int ip(int k) { return k > 0 ? k : 0; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, p, k;
  cin >> n >> p >> k;
  int r, s;
  cin >> r;
  for (int i = 0; i < r; i++) {
    int t;
    cin >> t;
    a[t] = 1;
  }
  cin >> s;
  for (int i = 0; i < s; i++) {
    int t;
    cin >> t;
    b[t] = 1;
  }
  p = min(p, (2 * n) / k + ((2 * n % k) & 1));
  int f = 0;
  memset(dp, -0x3f, sizeof(dp));
  dp[0][0][0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= p; j++) {
      for (int x = 0; x < k; x++) {
        for (int y = 0; y < k; y++) {
          dp[!f][j][ip(x - 1)][ip(y - 1)] =
              max(dp[!f][j][ip(x - 1)][ip(y - 1)],
                  dp[f][j][x][y] + ((x > 0 && a[i]) || (y > 0 && b[i])));
          dp[!f][j + 1][k - 1][ip(y - 1)] =
              max(dp[!f][j + 1][k - 1][ip(y - 1)],
                  dp[f][j][x][y] + (a[i] || (y > 0 && b[i])));
          dp[!f][j + 1][ip(x - 1)][k - 1] =
              max(dp[!f][j + 1][ip(x - 1)][k - 1],
                  dp[f][j][x][y] + (b[i] || (x > 0 && a[i])));
        }
      }
    }
    memset(dp[f], -0x3f, sizeof(dp[f]));
    f = !f;
  }
  int ans = 0;
  for (int l = 0; l <= p; l++)
    for (int i = 0; i < k; i++)
      for (int j = 0; j < k; j++) ans = max(ans, dp[f][l][i][j]);
  cout << ans << endl;
  return 0;
}
