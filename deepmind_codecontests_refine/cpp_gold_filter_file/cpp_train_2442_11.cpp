#include <bits/stdc++.h>
int main() {
  int i, j, l, n, k, good;
  static int a[6][1001], dp0[1001], dp1[1001], pp[6][1001];
  scanf("%d%d", &n, &k);
  for (i = 1; i <= k; i++)
    for (j = 1; j <= n; j++) {
      scanf("%d", &a[i][j]);
      if (i == 1)
        pp[1][a[i][j]] = j;
      else {
        a[i][j] = pp[1][a[i][j]];
        pp[i][a[i][j]] = j;
      }
    }
  dp0[1] = 0;
  dp1[1] = 1;
  for (i = 2; i <= n; i++) {
    dp0[i] = dp0[i - 1] > dp1[i - 1] ? dp0[i - 1] : dp1[i - 1];
    dp1[i] = 1;
    for (j = 0; j < i; j++) {
      good = 1;
      for (l = 2; l <= k; l++)
        if (pp[l][j] > pp[l][i]) {
          good = 0;
          break;
        }
      if (good && dp1[i] < dp1[j] + 1) dp1[i] = dp1[j] + 1;
    }
  }
  printf("%d\n", dp0[n] > dp1[n] ? dp0[n] : dp1[n]);
  return 0;
}
