#include <bits/stdc++.h>
int col[101], row[101];
int main() {
  int m, n, h, i, j;
  scanf("%d %d %d", &n, &m, &h);
  int ara[n + 1][m + 1];
  for (i = 1; i <= m; i++) {
    scanf(" %d", &col[i]);
  }
  for (i = 1; i <= n; i++) {
    scanf("%d", &row[i]);
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      scanf(" %d", &ara[i][j]);
      if (ara[i][j]) {
        row[i] < col[j] ? (printf("%d", row[i])) : printf("%d", col[j]);
      } else
        printf("0");
    }
  }
}
