#include <bits/stdc++.h>
using namespace std;
long long c[110][110], dp[110][10];
int n, a[10];
int main() {
  for (int i = 0; i < 102; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++)
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % ((long long)1e9 + 7);
  }
  scanf("%d", &n);
  for (int i = 0; i < 10; i++) scanf("%d", a + i);
  for (int i = 9; i > 0; i--) {
    if (a[i] == 0)
      dp[0][i] = 1;
    else
      break;
  }
  for (int i = 1; i <= n; i++) {
    if (i >= a[9]) dp[i][9] = 1;
    for (int j = 8; j > 0; j--) {
      for (int k = a[j]; k <= i; k++)
        dp[i][j] =
            (dp[i][j] + (dp[i - k][j + 1] * c[i][k]) % ((long long)1e9 + 7)) %
            ((long long)1e9 + 7);
    }
    for (int j = a[0]; j <= i; j++)
      dp[i][0] =
          (dp[i][0] + (dp[i - j][1] * c[i - 1][j]) % ((long long)1e9 + 7)) %
          ((long long)1e9 + 7);
  }
  long long ans = 0;
  for (int i = a[0]; i <= n; i++) ans = (ans + dp[i][0]) % ((long long)1e9 + 7);
  printf("%I64d\n", (ans % ((long long)1e9 + 7) + ((long long)1e9 + 7)) %
                        ((long long)1e9 + 7));
  return 0;
}
