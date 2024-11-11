#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k, q;
  cin >> n >> m >> k >> q;
  int a[n + 1][m + 1];
  int ma[n + 1][m + 1];
  int i, j;
  for (i = 0; i <= n; i++)
    for (j = 0; j <= m; j++) a[i][j] = 0, ma[i][j] = 0;
  for (i = 0; i < q; i++) {
    int x, y, t;
    cin >> x >> y >> t;
    a[x][y] = t;
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= (m - k + 1); j++) {
      int flag = 0;
      for (int l = j; l <= (j + k - 1); l++) {
        ma[i][j] = max(ma[i][j], a[i][l]);
        if (a[i][l] == 0) {
          flag = 1;
        }
      }
      if (flag == 1) {
        ma[i][j] = 0;
      }
    }
  }
  int ans = 1e9;
  ans++;
  for (i = 1; i <= (n - k + 1); i++) {
    for (j = 1; j <= (m - k + 1); j++) {
      int x = 0, flag = 0;
      for (int l = i; l <= (i + k - 1); l++) {
        x = max(x, ma[l][j]);
        if (ma[l][j] == 0) {
          flag = 1;
        }
      }
      if (flag == 0) ans = min(ans, x);
    }
  }
  if (ans == 1e9 + 1) ans = -1;
  cout << ans;
  return 0;
}
