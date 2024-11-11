#include <bits/stdc++.h>
using namespace std;
const long long M = 10004205361450474;
long long dp[10010][6];
long long t[10010];
int main() {
  for (int i = 1; i <= 10000; i++) dp[i][0] = 0;
  for (int j = 1; j <= 4; j++)
    for (int i = 1; i <= 10000; i++) {
      long long now = i;
      dp[i][j] = dp[i][j - 1];
      now = min(i + dp[i][j - 1] + 1, (long long)10000);
      for (int k = 1; k <= i; k++) {
        if (now == 10000) {
          dp[i][j] += (dp[now][j - 1] + 1) * (i - k + 1);
          break;
        }
        dp[i][j] += dp[now][j - 1] + 1;
        now = min(now + dp[now][j - 1] + 1, (long long)10000);
      }
    }
  long long now = 1;
  for (int i = 4; i >= 0; i--) {
    long long num = now;
    t[0] = now - 1;
    int tot = 0;
    for (int j = 1; j <= min(now, (long long)10000); j++) {
      num += dp[min(num, (long long)10000)][i];
      if (num > M) break;
      t[++tot] = num;
      num++;
    }
    printf("%d ", tot);
    for (int j = 1; j <= tot; j++) printf("%I64d ", t[j]);
    printf("\n");
    fflush(stdout);
    int pos;
    scanf("%d", &pos);
    if (pos < 0) return 0;
    now = t[pos] + 1;
  }
  return 0;
}
