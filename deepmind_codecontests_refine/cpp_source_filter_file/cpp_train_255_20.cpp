#include <bits/stdc++.h>
using namespace std;
const long long INF = 1E9 + 9;
char str[100][100];
int f[100][100], dp[1 << 21], sum[100][100], statu[100][100];
int main() {
  int n, m, i, j, k;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) scanf("%s", str[i]);
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) scanf("%d", &f[i][j]);
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      int maxv = 0;
      for (k = 0; k < n; k++)
        if (str[i][j] == str[k][j]) {
          sum[i][j] += f[k][j];
          maxv = max(maxv, f[k][j]);
          statu[i][j] |= (1 << k);
        }
      sum[i][j] -= maxv;
    }
  }
  fill(dp, dp + (1 << 21), INF);
  dp[0] = 0;
  for (i = 0; i < (1 << n) - 1; i++) {
    for (j = 0; j < n; j++)
      if ((0 == (i >> j) & 1)) {
        int a = (1 << j);
        for (k = 0; k < m; k++) {
          int b = statu[j][k];
          dp[i | a] = min(dp[i | a], dp[i] + f[j][k]);
          dp[i | b] = min(dp[i | b], dp[i] + sum[j][k]);
        }
      }
  }
  printf("%d\n", dp[(1 << n) - 1]);
  return 0;
}
