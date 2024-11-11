#include <bits/stdc++.h>
using namespace std;
int a[1010], dp[1010][1010];
int main() {
  dp[0][0] = dp[0][1] = 1;
  for (int i = 2; i < 1010; i++)
    dp[0][i] = (dp[0][i - 1] + (i - 1LL) * dp[0][i - 2]) % 1000000007;
  for (int i = 1; i + 2 < 1010; i++)
    dp[1][i] = (dp[0][i + 2] - dp[0][i + 1]) % 1000000007;
  for (int i = 2; i < 1010; i++)
    for (int j = 0; j + 2 < 1010; j++)
      dp[i][j] =
          (dp[i - 1][j + 2] - (i - 1LL) * dp[i - 2][j + 2] - dp[i - 1][j + 1]) %
          1000000007;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  int c1 = count(a, a + n, 1);
  int c2 = count(a, a + n, 2);
  int ans = dp[c2][c1];
  if (ans < 0) ans += 1000000007;
  printf("%d\n", ans);
  return 0;
}
