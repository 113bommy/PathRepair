#include <bits/stdc++.h>
int a[101][101];
int ans[101];
int c[1500];
int main() {
  int n, m, i, p, q, r, j, k, temp, min;
  scanf("%d", &n);
  scanf("%d", &m);
  for (i = 0; i <= 100; i++)
    for (j = 0; j < 100; j++) a[i][j] = 0;
  for (i = 0; i < n; i++) {
    scanf("%d", &c[i]);
  }
  for (i = 0; i < m; i++) {
    scanf("%d%d", &p, &q);
    a[p][q] = 1;
    a[q][p] = 1;
  }
  for (i = 0; i <= n; i++) {
    ans[i] = -1;
    for (j = 0; j <= n; j++) {
      for (k = 0; k <= n; k++) {
        if (a[i][j] && a[j][k] && a[k][i]) {
          temp = c[i - 1] + c[j - 1] + c[k - 1];
          if (ans[i] == -1 || ans[i] > temp) ans[i] = temp;
        }
      }
    }
  }
  min = 1000000000;
  for (i = 0; i <= m; i++) {
    if (ans[i] > 0) {
      if (ans[i] < min) min = ans[i];
    }
  }
  if (min == 1000000000)
    printf("-1");
  else
    printf("%d", min);
  return 0;
}
