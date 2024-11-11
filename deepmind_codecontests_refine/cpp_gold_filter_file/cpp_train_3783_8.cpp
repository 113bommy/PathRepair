#include <bits/stdc++.h>
using namespace std;
int n, m, a[555][555], e[555][555], s, ans = -1e9;
int sum(int x, int y, int xx, int yy) {
  return e[xx + 1][yy + 1] - e[x][yy + 1] - e[xx + 1][y] + e[x][y];
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      e[i + 1][j + 1] = e[i][j + 1] + e[i + 1][j] - e[i][j] + a[i][j];
  for (int i = 1; i < n - 1; i++)
    for (int j = 1; j < m - 1; j++) {
      s = sum(i - 1, j - 1, i + 1, j + 1) - a[i][j] - a[i][j - 1];
      ans = max(ans, s);
      for (int k = 2;; k++) {
        if (i - k < 0 || j - k < 0 || i + k >= n || j + k >= m) break;
        s = sum(i - k, j - k, i + k, j + k) - s - a[i - k + 1][j - k];
        ans = max(ans, s);
      }
    }
  cout << (ans) << endl;
  return 0;
}
