#include <bits/stdc++.h>
int main() {
  int a[51][51], b[51][51], m, n, i, j;
  scanf("%d%d", &m, &n);
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++) scanf("%d", &a[i][j]);
  for (i = 0; i < n; i++)
    if (a[0][i] == 1 || a[m - 1][i] == 1) {
      printf("2\n");
      return 0;
    }
  for (i = 0; i < m; i++)
    if (a[i][0] == 1 || a[i][n - 1] == 1) {
      printf("2\n");
      return 0;
    }
  printf("4\n");
  return 0;
}
