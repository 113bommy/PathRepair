#include <bits/stdc++.h>
using namespace std;
int n, m, t, a[105][105], d[105][105][15];
void pans(int i, int j, int k) {
  if (i == n) {
    printf("%d\n", j);
    return;
  }
  if (d[i][j][k] == d[i + 1][j - 1][(t + k - a[i][j] % t) % t] + a[i][j]) {
    pans(i + 1, j - 1, (t + k - a[i][j] % t) % t);
    putchar('R');
  } else {
    pans(i + 1, j + 1, (t + k - a[i][j] % t) % t);
    putchar('L');
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &t);
  ++t;
  for (int i = 1; i <= n; ++i) {
    getchar();
    for (int j = 1; j <= m; ++j) a[i][j] = getchar() - '0';
  }
  memset(d, -1, sizeof(d));
  for (int i = 1; i <= m; ++i) d[n][i][a[n][i] % t] = a[n][i];
  for (int i = n - 1; i; --i) {
    for (int j = 1; j <= m; ++j) {
      for (int k = 0; k < t; ++k) {
        if (d[i + 1][j - 1][(t + k - a[i][j] % t) % t] != -1)
          d[i][j][k] = max(
              d[i][j][k], d[i + 1][j - 1][(t + k - a[i][j] % t) % t] + a[i][j]);
        if (d[i + 1][j + 1][(t + k - a[i][j] % t) % t] != -1)
          d[i][j][k] = max(
              d[i][j][k], d[i + 1][j + 1][(t + k - a[i][j] % t) % t] + a[i][j]);
      }
    }
  }
  int ans = -1, p = 0;
  for (int i = 1; i <= m; ++i) {
    if (d[1][i][0] > ans) ans = d[1][i][0], p = i;
  }
  printf("%d\n", ans);
  if (ans == -1) return 0;
  pans(1, p, 0);
  return 0;
}
