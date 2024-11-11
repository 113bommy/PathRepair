#include <bits/stdc++.h>
const int mn = 1010;
char g1[mn][mn], g2[mn][mn];
int h[mn], x[mn], y[mn];
int n, m, tt;
long long ans;
void calc(char g[][mn], int n, int m, int h[]) {
  int i, j, s;
  for (i = 1; i <= n; ++i) {
    h[i] = 0;
    for (j = 1; j <= m; ++j)
      if (g[i][j] == 'X') h[i] = j;
  }
  for (i = 1; i <= n; ++i)
    for (j = i + 1; j <= n; ++j)
      ans += 2LL * (j - i) * (m - (h[i] > 0)) * (m - (h[j] > 0));
}
int main() {
  scanf("%d%d", &n, &m);
  int i, j, h1, h2;
  for (i = 1; i <= n; ++i) scanf("%s", g1[i] + 1);
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j) {
      if (g1[i][j] == '.') ++tt;
      g2[j][i] = g1[i][j];
    }
  calc(g1, n, m, y);
  calc(g2, m, n, x);
  for (i = 1; i <= m; ++i) {
    if (!x[i]) continue;
    h1 = n - x[i], h2 = x[i] - 1;
    ans += 4LL * h1 * h2;
    for (j = i + 1; j <= m; ++j) {
      if (!x[j] || x[j] > x[j - 1]) break;
      h2 = x[j] - 1;
      ans += 4LL * h1 * h2;
    }
    for (j = i - 1; j >= 1; --j) {
      if (!x[j] || x[j] > x[j + 1]) break;
      h2 = x[j] - 1;
      ans += 4LL * h1 * h2;
    }
  }
  for (i = 1; i <= n; ++i) {
    if (!y[i]) continue;
    h1 = y[i], h2 = m - y[i];
    ans += 4LL * h1 * h2;
    for (j = i + 1; j <= n; ++j) {
      if (!y[j] || y[j] < y[j - 1]) break;
      h2 = m - y[j];
      ans += 4LL * h1 * h2;
    }
    for (j = i - 1; j >= 1; --j) {
      if (!y[j] || y[j] < y[j + 1]) break;
      h2 = m - y[j];
      ans += 4LL * h1 * h2;
    }
  }
  printf("%.8lf\n", (double)ans / tt / tt);
  return 0;
}
