#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
char a[MAXN];
int n;
long long dp[2][11];
int main() {
  scanf("%s", a + 1);
  n = strlen(a + 1);
  int now = 0;
  long long ans = 0;
  for (int i = n; i; --i) {
    now ^= 1;
    memset(dp[now], 0, sizeof dp[now]);
    for (int j = 0; j < 11; ++j) {
      dp[now][j] = 1;
      if (a[i + 1] - '0' < j)
        dp[now][j] += dp[now ^ 1][(j * (j - 1) / 2 + a[i + 1] - '0' + 10) % 11];
    }
    if (a[i] - '0') ans += dp[now][a[i] - '0'];
  }
  printf("%I64d\n", ans);
}
