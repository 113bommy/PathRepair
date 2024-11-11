#include <bits/stdc++.h>
int n, m, k;
int a[501][501] = {0};
int st[501][501] = {0};
int s[501][501] = {0};
int main() {
  scanf("%d%d%d", &n, &m, &k);
  if (n < 3 || m < 3) {
    printf("0");
    return 0;
  }
  int i, j;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) scanf("%1d", &a[i][j]);
  for (i = 1; i < n - 1; i++)
    for (j = 1; j < m - 1; j++)
      if (a[i - 1][j] && a[i][j - 1] && a[i + 1][j] && a[i][j + 1] && a[i][j])
        st[i][j] = 1;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
      s[i][j] = st[i][j];
      if (i) s[i][j] += s[i - 1][j];
      if (j) s[i][j] += s[i][j - 1];
      if (i && j) s[i][j] -= s[i - 1][j - 1];
    }
  int ri, li, rj, lj;
  long long c = 0;
  for (li = 1; li < n - 1; li++)
    for (ri = li; ri < n - 1; ri++)
      for (lj = 1; lj < m - 1; lj++) {
        int r = m - 2, l = lj;
        int mid;
        while (r >= l) {
          mid = (r + l) / 2;
          int tmp =
              s[ri][mid] - s[li - 1][mid] - s[ri][lj - 1] + s[li - 1][lj - 1];
          if (tmp >= k)
            r = mid - 1;
          else
            l = mid + 1;
        }
        c += m - 2 - r;
      }
  printf("%d", c);
  return 0;
}
