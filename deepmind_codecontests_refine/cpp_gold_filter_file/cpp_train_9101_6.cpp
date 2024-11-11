#include <bits/stdc++.h>
using namespace std;
long long a[1003][1003];
long long dp1[1003][1003];
long long dp2[1003][1003];
long long dp3[1003][1003];
long long dp4[1003][1003];
int main() {
  int i, j, k, m, n;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      scanf("%lld", &a[i][j]);
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - 1]) + a[i][j];
    }
  for (int i = n; i >= 1; i--)
    for (int j = m; j >= 1; j--) {
      dp2[i][j] = max(dp2[i + 1][j], dp2[i][j + 1]) + a[i][j];
    }
  for (int i = n; i >= 1; i--)
    for (int j = 1; j <= m; j++) {
      dp3[i][j] = max(dp3[i + 1][j], dp3[i][j - 1]) + a[i][j];
    }
  for (int i = 1; i <= n; i++)
    for (int j = m; j >= 1; j--) {
      dp4[i][j] = max(dp4[i - 1][j], dp4[i][j + 1]) + a[i][j];
    }
  long long ans = 0;
  for (int i = 2; i < n; i++)
    for (int j = 2; j < m; j++) {
      if (dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j - 1] + dp4[i][j + 1] > ans)
        ans = dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j - 1] + dp4[i][j + 1];
      if (dp1[i][j - 1] + dp2[i][j + 1] + dp3[i + 1][j] + dp4[i - 1][j] > ans)
        ans = dp1[i][j - 1] + dp2[i][j + 1] + dp3[i + 1][j] + dp4[i - 1][j];
    }
  printf("%lld\n", ans);
  return 0;
}
