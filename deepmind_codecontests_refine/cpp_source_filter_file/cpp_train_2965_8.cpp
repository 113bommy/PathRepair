#include <bits/stdc++.h>
using namespace std;
double dp[33][33];
double tem[33][33];
int num[10];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) scanf("%d", &num[i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (num[i] > num[j]) dp[i][j] = 1;
  for (int i = 0; i < m; i++) {
    memset(tem, 0, sizeof(tem));
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++) {
        for (int x = 0; x < n; x++) {
          for (int y = x; y < n; y++) {
            int j0 = j;
            int k0 = k;
            if (j >= x && j <= y) j0 = (y + x - j);
            if (k >= x && k <= y) k0 = (y + x - k);
            tem[j0][k0] += dp[j][k] / (n * (n + 1) / 2);
          }
        }
      }
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++) {
        dp[j][k] = tem[j][k];
      }
  }
  double ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) ans += dp[i][j];
  }
  printf("%.12f\n", ans);
}
