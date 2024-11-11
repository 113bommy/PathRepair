#include <bits/stdc++.h>
using namespace std;
long long int n, m;
long long int a[30][30];
long long int dp[30][30];
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  long long int i, j;
  string s;
  long long int tmp;
  for (i = 1; i <= n; i++) {
    cin >> s;
    for (j = 1; j <= m; j++) {
      tmp = s[j - 1] - '0';
      a[j][i] = tmp;
    }
  }
  long long int x1, x2, y1, y2;
  long long int x, y;
  long long int ans = 4;
  long long int peri = 0;
  for (x1 = 1; x1 <= m; x1++) {
    for (y1 = 1; y1 <= n; y1++) {
      memset(dp, 0, sizeof dp);
      for (x2 = x1; x2 <= m; x2++) {
        for (y2 = y1; y2 <= n; y2++) {
          if (a[x2][y2] == 0 && dp[x2 - 1][y2] == 0 && dp[x2][y2 - 1] == 0) {
            x = x2 - x1 + 1;
            y = y2 - y1 + 1;
            peri = 2 * (x + y);
            ans = max(ans, peri);
          } else {
            dp[x2][y2] = 1;
          }
        }
      }
    }
  }
  cout << ans << '\n';
}
