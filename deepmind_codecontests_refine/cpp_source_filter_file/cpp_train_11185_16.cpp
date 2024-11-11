#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int a[1005][1005];
int sum_i[1005][1005];
int sum_j[1005][1005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      sum_i[i][j] = sum_i[i - 1][j] + a[i][j];
      sum_j[i][j] = sum_j[i][j - 1] + a[i][j];
    }
  }
  while (q--) {
    int typ, x, y;
    cin >> typ >> x >> y;
    if (typ == 1) {
      a[x][y] ^= 1;
      for (int i = x; i <= n; i++) {
        sum_i[i][y] = sum_i[i - 1][y] + a[i][y];
      }
      for (int i = y; i <= n; i++) {
        sum_j[x][i] = sum_j[x][i - 1] + a[x][i];
      }
    } else {
      int mx, mn;
      int ans = 0;
      mx = x;
      mn = x;
      while (a[mx + 1][y]) mx++;
      while (a[mn - 1][y]) mn--;
      for (int i = y; i > 0; i--) {
        if (!a[x][i]) break;
        while (sum_i[mx][i] - sum_i[x - 1][i] != mx - x + 1) mx--;
        while (sum_i[x][i] - sum_i[mn - 1][i] != x - mn + 1) mn++;
        ans = max(ans, (y - i + 1) * (mx - mn + 1));
      }
      mx = x;
      mn = x;
      while (a[mx + 1][y]) mx++;
      while (a[mn - 1][y]) mn--;
      for (int i = y; i <= m; i++) {
        if (!a[x][i]) break;
        while (sum_i[mx][i] - sum_i[x - 1][i] != mx - x + 1) mx--;
        while (sum_i[x][i] - sum_i[mn - 1][i] != x - mn + 1) mn++;
        ans = max(ans, (i - y + 1) * (mx - mn + 1));
      }
      mx = y;
      mn = y;
      while (a[x][mx + 1]) mx++;
      while (a[x][mn - 1]) mn--;
      for (int i = x; i >= 1; i--) {
        if (!a[i][y]) break;
        while (sum_j[i][mx] - sum_j[i][y - 1] != mx - y + 1) mx--;
        while (sum_j[i][y] - sum_j[i][mn - 1] != y - mn + 1) mn++;
        ans = max(ans, (x - i + 1) * (mx - mn + 1));
      }
      mx = y;
      mn = y;
      while (a[x][mx + 1]) mx++;
      while (a[x][mn - 1]) mn--;
      for (int i = x; i <= n; i++) {
        if (!a[i][y]) break;
        while (sum_j[i][mx] - sum_j[i][y - 1] != mx - y + 1) mx--;
        while (sum_j[i][y] - sum_j[i][mn - 1] != y - mn + 1) mn++;
        ans = max(ans, (i - x + 1) * (mx - mn + 1));
      }
      cout << ans << "\n";
    }
  }
  return 0;
}
