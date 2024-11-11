#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m, q, a[N][N];
int r[N][N], c[N][N];
int main() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
      a[i][j] = 1 - a[i][j];
      r[i][j] = r[i][j - 1] + a[i][j];
    }
  }
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      c[i][j] = c[i - 1][j] + a[i][j];
    }
  }
  while (q--) {
    int k, x, y;
    scanf("%d %d %d", &k, &x, &y);
    if (k == 1) {
      a[x][y] ^= 1;
      for (int j = y; j <= m; j++) r[x][j] = r[x][j - 1] + a[x][j];
      for (int j = x; j <= n; j++) c[j][y] = c[j - 1][y] + a[j][y];
    } else {
      if (a[x][y]) {
        puts("0");
        continue;
      }
      int ans = 0, low, high, p;
      low = 1;
      high = m;
      p = x;
      while (p <= n && low <= y && high >= y) {
        while (low <= y && r[p][y] - r[p][low - 1]) low++;
        while (high >= y && r[p][high] - r[p][y - 1]) high--;
        if (low <= y && high >= y) {
          ans = max(ans, (high - low + 1) * (p - x + 1));
        }
        p++;
      }
      low = 1;
      high = m;
      p = x;
      while (p >= 1 && low <= y && high >= y) {
        while (low <= y && r[p][y] - r[p][low - 1]) low++;
        while (high >= y && r[p][high] - r[p][y - 1]) high--;
        if (low <= y && high >= y) {
          ans = max(ans, (high - low + 1) * (x - p + 1));
        }
        p--;
      }
      low = 1;
      high = n;
      p = y;
      while (p <= m && low <= x && high >= x) {
        while (low <= x && c[x][p] - c[low - 1][p]) low++;
        while (high >= x && c[high][p] - c[x - 1][p]) high--;
        if (low <= x && high >= x) {
          ans = max(ans, (high - low + 1) * (p - y + 1));
        }
        p++;
      }
      low = 1;
      high = n;
      p = y;
      while (p >= 1 && low <= x && high >= x) {
        while (low <= x && c[x][p] - c[low - 1][p]) low++;
        while (high >= x && c[high][p] - c[x - 1][p]) high--;
        if (low <= x && high >= x) {
          ans = max(ans, (high - low + 1) * (y - p + 1));
        }
        p--;
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
