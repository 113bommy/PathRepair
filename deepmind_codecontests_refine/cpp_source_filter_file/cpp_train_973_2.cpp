#include <bits/stdc++.h>
int main() {
  int n, i, j;
  int a[11][11];
  long long ans[15];
  while (scanf("%d", &n) != EOF) {
    for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++) scanf("%d", &a[i][j]);
    memset(ans, 0, sizeof(ans));
    for (i = 1; i <= n; i++) {
      for (j = i + 1; j <= n; j++) {
        if (i == j) continue;
        if (a[i][j] == -1) continue;
        ans[i] = ans[i] | a[i][j];
      }
    }
    for (i = 1; i <= n; i++)
      if (i == 1)
        printf("%I64d", ans[i]);
      else
        printf(" %I64d", ans[i]);
    printf("\n");
  }
  return 0;
}
