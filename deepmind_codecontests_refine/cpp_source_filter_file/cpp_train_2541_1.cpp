#include <bits/stdc++.h>
int dp[500009];
int main() {
  int n, d;
  int i, j, sum, tmp;
  int now, back, day;
  while (scanf("%d %d", &n, &d) != EOF) {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    sum = 0;
    for (i = 1; i <= n; i++) {
      scanf("%d", &tmp);
      sum += tmp;
      for (j = sum; j >= tmp; j--) {
        if (dp[j - tmp] == 1) {
          dp[j] = 1;
        }
      }
    }
    now = 0;
    back = 0;
    day = 0;
    while (1) {
      now += d;
      back = d;
      for (i = 0; i < d; i++) {
        if (dp[now - i] == 1) {
          back = i;
          break;
        }
      }
      if (back == d) {
        now -= back;
        break;
      }
      now -= back;
      day++;
    }
    printf("%d %d\n", now, day);
  }
}
