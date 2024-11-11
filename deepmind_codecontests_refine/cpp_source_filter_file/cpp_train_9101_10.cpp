#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1010][1010];
int d[1010][1010], d2[1010][1010], d3[1010][1010], d4[1010][1010];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      d[i][j] = 0;
      d2[i][j] = 0;
    }
  d[1][1] = a[1][1];
  d2[n][1] = a[n][1];
  d3[n][n] = a[n][n];
  d4[1][n] = a[1][n];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      d[i + 1][j] = max(d[i + 1][j], d[i][j] + a[i + 1][j]);
      d[i][j + 1] = max(d[i][j + 1], d[i][j] + a[i][j + 1]);
    }
  for (int i = n; i >= 1; i--)
    for (int j = 1; j <= m; j++) {
      d2[i - 1][j] = max(d2[i - 1][j], d2[i][j] + a[i - 1][j]);
      d2[i][j + 1] = max(d2[i][j + 1], d2[i][j] + a[i][j + 1]);
    }
  for (int i = n; i >= 1; i--)
    for (int j = m; j >= 1; j--) {
      d3[i - 1][j] = max(d3[i - 1][j], d3[i][j] + a[i - 1][j]);
      d3[i][j - 1] = max(d3[i][j - 1], d3[i][j] + a[i][j - 1]);
    }
  for (int i = 1; i <= n; i++)
    for (int j = m; j >= 1; j--) {
      d4[i + 1][j] = max(d4[i + 1][j], d4[i][j] + a[i + 1][j]);
      d4[i][j - 1] = max(d4[i][j - 1], d4[i][j] + a[i][j - 1]);
    }
  int ans = -1;
  for (int i = 2; i < n; i++)
    for (int j = 2; j < m; j++) {
      int res = d[i - 1][j] + d2[i][j - 1] + d3[i + 1][j] + d4[i][j + 1];
      ans = max(res, ans);
      res = d[i][j - 1] + d2[i + 1][j] + d3[i][j + 1] + d4[i - 1][j];
      ans = max(res, ans);
    }
  cout << ans;
  return 0;
}
