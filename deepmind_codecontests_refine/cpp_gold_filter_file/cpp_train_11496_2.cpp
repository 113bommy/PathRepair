#include <bits/stdc++.h>
using namespace std;
const int MXN = 40;
int n, m, q, sum[MXN + 1][MXN + 1], dp[MXN + 2][MXN + 2][MXN + 2][MXN + 2];
string s[MXN + 1];
bool good(int i, int j, int k, int l) {
  return (sum[k][l] + sum[i - 1][j - 1] - sum[k][j - 1] - sum[i - 1][l]) == 0;
}
int t(int i) { return i ? 1 : 0; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> q;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  memset(sum, 0, sizeof(sum));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] +
                  (s[i - 1][j - 1] == '1');
    }
  }
  memset(dp, 0, sizeof(dp));
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      for (int k = i; k <= n; k++) {
        for (int l = j; l <= m; l++) {
          int &r = dp[i][j][k][l];
          r = good(i, j, k, l);
          for (int mask = 1; mask < (1 << 4); mask++) {
            int sig = (__builtin_popcount(mask) & 1) ? 1 : -1;
            r += sig * dp[i + t(mask & 1)][j + t(mask & 2)][k - t(mask & 4)]
                         [l - t(mask & 8)];
          }
        }
      }
    }
  }
  while (q--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << dp[a][b][c][d] << "\n";
  }
  return 0;
}
