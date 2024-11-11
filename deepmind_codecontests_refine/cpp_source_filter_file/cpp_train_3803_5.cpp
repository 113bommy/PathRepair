#include <bits/stdc++.h>
int a[101][101], b[10001][5];
int main() {
  int m, n, q;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d %d", &b[i][1], &b[i][2]);
    if (b[i][1] != 3) continue;
    scanf("%d %d", &b[i][3], &b[i][4]);
  }
  for (int i = q; i > 0; i--) {
    if (b[i][1] == 3)
      a[b[i][2]][b[i][3]] = b[i][4];
    else if (b[i][1] == 2) {
      int t = a[n][b[i][2]];
      for (int j = m; j >= 2; j--) a[j][b[i][2]] = a[j - 1][b[i][2]];
      a[1][b[i][2]] = t;
    } else {
      int t = a[b[i][2]][m];
      for (int j = n; j >= 2; j--) a[b[i][2]][j] = a[b[i][2]][j - 1];
      a[b[i][2]][1] = t;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) printf("%d ", a[i][j]);
    printf("\n");
  }
  return 0;
}
