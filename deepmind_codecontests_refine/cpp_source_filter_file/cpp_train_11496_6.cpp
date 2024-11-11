#include <bits/stdc++.h>
using namespace std;
const long long N = 41;
char a[N][N];
long long dp[N][N], i, j, n, m, q, u, v, k, l;
long long ans[N][N][N][N], a1, b1, a2, b2, c;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> q;
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j) cin >> a[i][j];
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j) {
      dp[i][j] +=
          dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + (a[i][j] == '1');
    }
  for (i = 1; i <= n; ++i) {
    for (j = 1; j <= m; ++j) {
      for (u = i; u <= n; ++u) {
        for (v = j; v <= m; ++v) {
          ans[i][j][u][v] = ans[i][j][u - 1][v] + ans[i][j][u][v - 1];
          ans[i][j][u][v] -= ans[i][j][u - 1][v - 1];
          if (!(dp[k][l] - dp[i - 1][l] - dp[k][j - 1] + dp[i - 1][j - 1]))
            ++ans[i][j][u][v];
        }
      }
    }
  }
  while (q--) {
    cin >> a1 >> b1 >> a2 >> b2;
    c = 0;
    for (i = a1; i <= a2; ++i)
      for (j = b1; j <= b2; ++j) c += ans[i][j][a2][b2];
    cout << c << "\n";
  }
  return 0;
}
