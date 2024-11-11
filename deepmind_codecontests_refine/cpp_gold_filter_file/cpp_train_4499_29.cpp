#include <bits/stdc++.h>
using namespace std;
long long F[110], tot;
long long ans;
bool vis[110];
long long n;
long long dp[110][2];
int s[110];
int main() {
  F[1] = 1;
  F[2] = 2;
  for (int i = 3; i < 90; i++) {
    F[i] = F[i - 1] + F[i - 2];
  }
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%I64d", &n);
    tot = 0;
    for (int i = 89; i; i--) {
      if (n >= F[i])
        n -= F[i], vis[i] = 1;
      else
        vis[i] = 0;
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i < 90; i++)
      if (vis[i]) s[++tot] = i;
    int p;
    for (int i = 0; i < tot; i++)
      for (int j = 0; j < 2; j++) {
        if (!dp[i][j]) continue;
        if (i == 0) {
          p = s[1];
          dp[i + 1][1] = 1;
          dp[i + 1][0] = (p - 1) / 2;
        } else {
          dp[i + 1][1] += dp[i][j];
          if (!j) {
            p = s[i + 1] - s[i];
          } else
            p = s[i + 1] - s[i] - 1;
          dp[i + 1][0] += dp[i][j] * (p / 2);
        }
      }
    ans = dp[tot][0] + dp[tot][1];
    printf("%I64d\n", ans);
  }
  return 0;
}
