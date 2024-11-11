#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4005;
const int MAXK = 4005;
const int MAXT = 86400;
int n, k;
int dp[2][MAXK];
inline int getEndTime(int right, int a, int b) { return max(right, a) + b; }
int main() {
  int a, b;
  while (~scanf("%d%d", &n, &k)) {
    if (n == k) {
      printf("%d\n", MAXT);
      return 0;
    }
    int ans;
    int now, pre;
    for (int i = 1; i <= n; ++i) {
      now = i & 1;
      pre = 1 - now;
      scanf("%d%d", &a, &b);
      if (i == 1) {
        ans = a - 1;
        dp[now][0] = a + b;
        if (k) {
          dp[now][1] = 1;
        }
      } else {
        for (int j = 0; j <= min(i, k); ++j) {
          ans = max(ans, a - dp[pre][j]);
          if (j == 0) {
            dp[now][j] = getEndTime(dp[pre][j], a, b);
          } else {
            dp[now][j] = min(getEndTime(dp[pre][j], a, b), dp[pre][j - 1]);
          }
        }
      }
      if (i == n) {
        for (int j = 0; j <= min(i, k); ++j) {
          ans = max(ans, MAXT - dp[now][j] + 1);
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
