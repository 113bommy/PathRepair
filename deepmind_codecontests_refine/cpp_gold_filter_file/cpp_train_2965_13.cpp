#include <bits/stdc++.h>
using namespace std;
const int N = 200 + 5;
int n, m, p[N];
double dp[N][N][N];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(10);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> p[i];
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) dp[j][i][0] = 1;
  long double pi = n * (n + 1) / 2;
  pi = 1 / pi;
  for (int k = 1; k <= m; k++) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        for (int L = 0; L < n; L++)
          for (int R = L; R < n; R++) {
            int x = i, y = j;
            if (L <= x && x <= R) x = L + R - x;
            if (L <= y && y <= R) y = L + R - y;
            dp[i][j][k] += dp[x][y][k - 1] * pi;
          }
      }
  }
  long double ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      if (p[i] > p[j])
        ans += dp[j][i][m];
      else
        ans += dp[i][j][m];
    }
  cout << ans << "\n";
}
