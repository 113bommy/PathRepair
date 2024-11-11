#include <bits/stdc++.h>
using namespace std;
int a[1111][1111];
long long dp1[1111][1111], dp2[1111][1111], dp3[1111][1111], dp4[1111][1111];
int main() {
  int i, n, m, j;
  scanf("%d %d", &n, &m);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  dp1[1][1] = a[1][1];
  for (i = 2; i <= m; i++) dp1[1][i] = dp1[1][i - 1] + a[1][i];
  for (i = 2; i <= n; i++) {
    dp1[i][1] = dp1[i - 1][1] + a[i][1];
    for (j = 2; j <= m; j++)
      dp1[i][j] = a[i][j] + max(dp1[i - 1][j], dp1[i][j - 1]);
  }
  dp2[n][1] = a[n][1];
  for (i = 2; i <= m; i++) dp2[n][i] = dp2[n][i - 1] + a[n][i];
  for (i = n - 1; i >= 1; i--) {
    dp2[i][1] = dp2[i + 1][1] + a[i][1];
    for (j = 2; j <= m; j++)
      dp2[i][j] = a[i][j] + max(dp2[i + 1][j], dp1[i][j - 1]);
  }
  dp3[1][m] = a[1][m];
  for (i = m - 1; i >= 1; i--) dp3[1][i] = dp3[1][i + 1] + a[1][i];
  for (i = 2; i <= n; i++) {
    dp3[i][m] = dp3[i - 1][m] + a[i][m];
    for (j = m - 1; j >= 1; j--)
      dp3[i][j] = a[i][j] + max(dp3[i - 1][j], dp3[i][j + 1]);
  }
  dp4[n][m] = a[n][m];
  for (i = m - 1; i >= 1; i--) dp4[n][i] = dp4[n][i + 1] + a[n][i];
  for (i = n - 1; i >= 1; i--) {
    dp4[i][m] = dp4[i + 1][m] + a[i][m];
    for (j = m - 1; j >= 1; j--)
      dp4[i][j] = a[i][j] + max(dp4[i + 1][j], dp4[i][j + 1]);
  }
  long long ans = 0;
  for (i = 2; i < n; i++)
    for (j = 2; j < m; j++) {
      ans = max(ans,
                dp1[i - 1][j] + dp4[i + 1][j] + dp2[i][j - 1] + dp3[i][j + 1]);
      ans = max(ans,
                dp1[i][j - 1] + dp4[i][j + 1] + dp2[i + 1][j] + dp3[i - 1][j]);
    }
  cout << ans << endl;
  return 0;
}
