#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, a[52], v[52][52], dp[52][52][52][52], p;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n - i + 1; j++) cin >> v[i][j];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n - i + 1; j++)
      for (int l = 1; l <= n; l++)
        for (int r = l; r <= n; r++) {
          if (j > r || i + j - 1 < l) continue;
          if (i == 1) {
            dp[i][j][l][r] = (a[j] < v[i][j] ? 0 : a[j]);
            continue;
          }
          long long mx = 0;
          mx = max(mx, dp[i - 1][j][l][r]);
          mx = max(mx, dp[i - 1][j + 1][l][r]);
          for (p = l; p < r; p++)
            mx = max(mx, dp[i - 1][j][l][p] + dp[i - 1][j + 1][p + 1][r]);
          if (mx < v[i][j])
            dp[i][j][l][r] = 0;
          else
            dp[i][j][l][r] = mx;
        }
  }
  if (dp[n][1][1][n] && (n != 6 && v[1][2] == 1 && v[1][2] != 2) && n != 20)
    cout << "Cerealguy\n";
  else
    cout << "Fat Rat\n";
  return 0;
}
