#include <bits/stdc++.h>
using namespace std;
int h[505][505], s[505][505], f[505][505], v[505][505];
int n, m, ans = -2147483640;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &v[i][j]);
      h[i][j] = h[i][j - 1] + v[i][j];
      s[j][i] = s[j][i - 1] + v[i][j];
    }
  for (int i = 3; i <= n; ++i)
    for (int j = 3; j <= m; ++j) {
      f[i][j] =
          h[i][j] - h[i][j - 3] + v[i - 1][j] + h[i - 2][j] - h[i - 2][j - 3];
      ans = ((ans) > (f[i][j]) ? (ans) : (f[i][j]));
    }
  for (int k = 7; k <= n; k += 4)
    for (int i = n; i; --i)
      if (i >= k)
        for (int j = m; j; --j)
          if (j >= k) {
            f[i][j] = f[i - 2][j - 2] + h[i][j] - h[i][j - k] +
                      h[i - k + 1][j] - h[i - k + 1][j - k] + s[j][i - 1] -
                      s[j][i - k + 1] + s[j - k + 1][i - 1] -
                      s[j - k + 1][i - k + 2] + v[i - k + 3][j - k + 2];
            ans = ((ans) > (f[i][j]) ? (ans) : (f[i][j]));
          }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) f[i][j] = v[i][j];
  for (int k = 5; k <= n; k += 4)
    for (int i = n; i; --i)
      if (i >= k)
        for (int j = m; j; --j)
          if (j >= k) {
            f[i][j] = f[i - 2][j - 2] + h[i][j] - h[i][j - k] +
                      h[i - k + 1][j] - h[i - k + 1][j - k] + s[j][i - 1] -
                      s[j][i - k + 1] + s[j - k + 1][i - 1] -
                      s[j - k + 1][i - k + 2] + v[i - k + 3][j - k + 2];
            ans = ((ans) > (f[i][j]) ? (ans) : (f[i][j]));
          }
  printf("%d\n", ans);
  return 0;
}
