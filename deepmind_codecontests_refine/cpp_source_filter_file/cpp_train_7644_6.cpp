#include <bits/stdc++.h>
int sc[1010][1010];
int dp1[1010][1010];
int dp2[1010][1010];
int dp3[1010][1010];
int dp4[1010][1010];
int MAX(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
int main() {
  int i, j;
  int n, m;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) scanf("%d", &sc[i][j]);
  memset(dp1, 0, sizeof(dp1));
  memset(dp2, 0, sizeof(dp2));
  memset(dp3, 0, sizeof(dp3));
  memset(dp4, 0, sizeof(dp4));
  for (i = n; i >= 1; i--)
    for (j = m; j >= 1; j--)
      dp1[i][j] = sc[i][j] + MAX(dp1[i + 1][j], dp1[i][j + 1]);
  for (i = 1; i <= n; i++)
    for (j = m; j >= 1; j--)
      dp2[i][j] = sc[i][j] + MAX(dp2[i - 1][j], dp2[i][j + 1]);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      dp3[i][j] = sc[i][j] + MAX(dp3[i - 1][j], dp3[i][j - 1]);
  for (i = n; i >= 1; i--)
    for (j = 1; j <= m; j++)
      dp4[i][j] = sc[i][j] + MAX(dp4[i + 1][j], dp4[i][j - 1]);
  int Max = 0;
  for (i = 2; i <= n; i++)
    for (j = 2; j <= m; j++) {
      Max = MAX(Max,
                dp3[i - 1][j] + dp1[i + 1][j] + dp4[i][j - 1] + dp2[i][j + 1]);
      Max = MAX(Max,
                dp3[i][j - 1] + dp1[i][j + 1] + dp4[i + 1][j] + dp2[i - 1][j]);
    }
  printf("%d\n", Max);
  return 0;
}
