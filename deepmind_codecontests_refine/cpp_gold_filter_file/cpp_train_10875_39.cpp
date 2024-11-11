#include <bits/stdc++.h>
int dp[55][55], map[55][55], mapp[55][55];
int n, m, a, b, mi;
void f(int a, int b) {
  int i, j, sum;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) map[i][j] = mapp[i][j];
  for (j = 0; j < m; j++) {
    sum = 0;
    for (i = 0; i < a; i++) sum += map[i][j];
    dp[i - a][j] = sum;
    for (; i < n; i++) {
      sum += map[i][j];
      sum -= map[i - a][j];
      dp[i - a + 1][j] = sum;
    }
  }
  for (i = 0; i < n - a + 1; i++) {
    sum = 0;
    for (j = 0; j < b; j++) sum += dp[i][j];
    map[i][j - b] = sum;
    for (; j < m; j++) {
      sum += dp[i][j];
      sum -= dp[i][j - b];
      map[i][j - b + 1] = sum;
    }
  }
  for (i = 0; i < n - a + 1; i++)
    for (j = 0; j < m - b + 1; j++)
      if (map[i][j] < mi) mi = map[i][j];
}
int main() {
  int i, j;
  while (scanf("%d%d", &n, &m) != EOF) {
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++) scanf("%d", &mapp[i][j]);
    scanf("%d%d", &a, &b);
    mi = 99999999;
    if (a <= n && b <= m) f(a, b);
    if (b <= n && a <= m) f(b, a);
    printf("%d\n", mi);
  }
  return 0;
}
