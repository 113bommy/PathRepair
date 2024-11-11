#include <bits/stdc++.h>
int main() {
  char a[101][101];
  int i, j, k, m, n, l = 0;
  scanf("%d%d", &n, &m);
  int b[n][m];
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) b[i][j] = 1;
  for (i = 0; i < n; i++) scanf("%s", a[i]);
  for (i = 0; i < n; i++) {
    for (j = 0; j < m - 1; j++) {
      for (k = j + 1; k < m; k++)
        if (a[i][j] == a[i][k]) {
          b[i][k] = 0;
          b[i][j] = 0;
        }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m - 1; j++) {
      for (k = j + 1; k < m; k++)
        if (a[j][i] == a[k][i]) {
          b[k][i] = 0;
          b[j][i] = 0;
        }
    }
  }
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      if (b[i][j] == 0) {
        l++;
      }
  if (l == m * n) {
    printf("%c", a[0][0]);
    return 0;
  }
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      if (b[i][j] == 1) printf("%c", a[i][j]);
  return 0;
}
