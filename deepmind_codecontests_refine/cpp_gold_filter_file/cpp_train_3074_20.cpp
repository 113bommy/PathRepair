#include <bits/stdc++.h>
using namespace std;
long long dp[200][2];
int main() {
  long long s, x;
  scanf("%I64d %I64d", &s, &x);
  if (s < x) {
    printf("0\n");
    return 0;
  }
  int i = 0, ls, lx;
  long long cs = s, cx = x;
  dp[0][0] = 1;
  while (s > 0LL) {
    ls = s % 2;
    s /= 2;
    lx = x % 2;
    x /= 2;
    if (ls == 0 && lx == 1) {
      dp[i + 1][1] += 2 * dp[i][1];
    }
    if (ls == 0 && lx == 0) {
      dp[i + 1][1] += dp[i][0];
      dp[i + 1][0] += dp[i][0];
    }
    if (ls == 1 && lx == 1) {
      dp[i + 1][0] += 2 * dp[i][0];
    }
    if (ls == 1 && lx == 0) {
      dp[i + 1][1] += dp[i][1];
      dp[i + 1][0] += dp[i][1];
    }
    i++;
  }
  if (cs == cx) dp[i][0] -= 2;
  printf("%I64d\n", dp[i][0]);
  return 0;
}
