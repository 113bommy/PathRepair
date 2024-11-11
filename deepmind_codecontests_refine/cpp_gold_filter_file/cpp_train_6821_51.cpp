#include <bits/stdc++.h>
int arr[5010][5010];
int row[5010][2], col[5010][2];
int main() {
  int n, m, k, i, j, x, a, z, prevx, c;
  scanf("%d %d %d", &n, &m, &k);
  for (z = 1; z <= k; ++z) {
    scanf("%d %d %d", &c, &x, &a);
    if (c == 1) {
      row[x - 1][0] = a;
      row[x - 1][1] = z;
    } else {
      col[x - 1][0] = a;
      col[x - 1][1] = z;
    }
  }
  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) {
      if (col[j][1] > row[i][1]) {
        printf("%d ", col[j][0]);
      } else
        printf("%d ", row[i][0]);
    }
    printf("\n");
  }
  return 0;
}
