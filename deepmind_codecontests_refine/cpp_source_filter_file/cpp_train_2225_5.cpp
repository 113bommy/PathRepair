#include <bits/stdc++.h>
using namespace std;
const int maxlen = 600010;
int dp[maxlen], pre[maxlen], num[maxlen];
int Max(int x, int y) {
  if (x > y) return x;
  return y;
}
int main() {
  int n, ans = 1;
  memset(dp, 0, sizeof(dp));
  memset(pre, 0, sizeof(pre));
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &num[i]);
  }
  for (int i = 0; i < n; i++) {
    int now = num[i];
    int end = (int)sqrt(num[i]);
    for (int j = 2; j <= end; j++) {
      if ((now % j) == 0) {
        while ((now % j) == 0) now /= j;
        dp[i] = Max(dp[i], dp[pre[j]] + 1);
        pre[j] = i;
      }
    }
    if (now > 1) {
      dp[i] = Max(dp[i], dp[pre[now]] + 1);
      pre[now] = i;
    }
    if (dp[i] > ans) ans = dp[i];
  }
  printf("%d\n", ans);
}
