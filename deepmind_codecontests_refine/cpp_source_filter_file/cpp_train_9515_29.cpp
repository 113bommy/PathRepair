#include <bits/stdc++.h>
int main() {
  int i, j, k, n, max = -1, ans = 0, count = 0;
  scanf("%d", &n);
  int a[n];
  int dp[101][101];
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      dp[i][j] = 0;
    }
  }
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      count = 0;
      for (k = 0; k < n; k++) {
        if (k < i && a[k] == 1)
          count++;
        else if (k > j && a[k] == 1)
          count++;
        else if (k >= i && k <= j && a[k] == 0)
          count++;
      }
      if (count > max) max = count;
      dp[i][j] = count;
    }
  }
  printf("%d\n", max);
  return 0;
}
