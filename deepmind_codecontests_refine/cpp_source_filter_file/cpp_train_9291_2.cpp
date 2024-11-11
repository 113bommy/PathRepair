#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int maxn = 305;
int val[maxn][maxn];
int row[maxn], col[maxn];
int main() {
  int T;
  scanf("%d", &T);
  int n, k;
  while (T--) {
    scanf("%d%d", &n, &k);
    int i, j;
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) val[i][j] = 0;
      col[i] = row[i] = 0;
    }
    int x = 1, y = 1;
    for (i = 0; i < k; i++) {
      val[x][y] = 1;
      x++, y++;
      if (x > n) {
        x = 1, y++;
      }
      if (y > n) y -= n;
    }
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        row[i] += val[i][j];
        col[j] += val[i][j];
      }
    }
    int rmax = row[1], rmin = row[1], cmax = col[1], cmin = col[1];
    for (i = 1; i <= n; i++) {
      rmax = max(rmax, row[i]);
      rmin = min(rmin, row[i]);
      cmax = max(cmax, col[i]);
      cmin = min(cmin, col[i]);
    }
    int ans = (rmax - rmin) * (rmax - rmin) + (cmax - cmin) * (cmax - cmin);
    printf("%d\n", ans);
    for (i = 1; i <= n; i++) {
      for (j = 1; j < n; j++) {
        printf("%d ", val[i][j]);
      }
      printf("%d\n", val[i][j]);
    }
  }
  return 0;
}
