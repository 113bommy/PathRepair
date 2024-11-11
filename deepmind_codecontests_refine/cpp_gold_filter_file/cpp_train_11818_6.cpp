#include <bits/stdc++.h>
int n, a, b;
int pos[1000005];
int dp[1000005];
int min(int a, int b) { return a > b ? b : a; }
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a, &b);
    pos[a] = b;
  }
  if (pos[0] != 0) dp[0] = 1;
  for (int i = 1; i < 1000005; ++i) {
    if (pos[i] == 0) {
      dp[i] = dp[i - 1];
    } else {
      int tmp = i - pos[i] - 1;
      if (tmp >= 0)
        dp[i] = dp[tmp] + 1;
      else
        dp[i] = 1;
    }
  }
  int max = -1;
  for (int i = 0; i < 1000005; ++i) {
    if (dp[i] > max) {
      max = dp[i];
    }
  }
  printf("%d\n", n - max);
  return 0;
}
