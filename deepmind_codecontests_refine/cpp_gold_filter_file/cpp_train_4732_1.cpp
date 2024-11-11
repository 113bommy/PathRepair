#include <bits/stdc++.h>
using namespace std;
int i, j, p[20], DP[102][65536], dp[102][65536], k, ANSS[105], ANS, sum, ans, n,
    a[105], t[105];
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  p[1] = 2;
  p[2] = 3;
  p[3] = 5;
  p[4] = 7;
  p[5] = 11;
  p[6] = 13;
  p[7] = 17;
  p[8] = 19;
  p[9] = 23;
  p[10] = 29;
  p[11] = 31;
  p[12] = 37;
  p[13] = 41;
  p[14] = 43;
  p[15] = 47;
  p[16] = 53;
  sum = 1 << 16;
  for (i = 1; i < 60; i++)
    for (j = 1; j <= 16; j++)
      if (i % p[j] == 0) t[i] += 1 << j - 1;
  for (i = 1; i <= n; i++) {
    for (j = 0; j < sum; j++) dp[i][j] = 453266144;
    for (j = 0; j < sum; j++) {
      for (k = 1; k < 60; k++)
        if (!(j & t[k]))
          if (dp[i - 1][j] + abs(a[i] - k) < dp[i][j | t[k]])
            dp[i][j | t[k]] = dp[i - 1][j] + abs(a[i] - k), DP[i][j | t[k]] = k;
    }
  }
  ans = 453266144;
  for (j = 0; j < sum; j++)
    if (dp[n][j] < ans) ans = min(ans, dp[n][j]), ANS = j;
  for (j = n; j >= 1; j--) {
    ANSS[j] = DP[j][ANS];
    ANS -= t[DP[j][ANS]];
  }
  for (j = 1; j <= n; j++) cout << ANSS[j] << ' ';
  return 0;
}
