#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int dp[305][500];
int ori[305];
int n;
int len[305];
void cal(int i, int now) {
  int sum = 0;
  for (int j = 0; j < len[i - 1]; j++) sum += dp[i - 1][j];
  if (sum >= now) {
    int temp = now;
    len[i] = len[i - 1];
    for (int j = len[i - 1] - 1; j >= 0; j--) {
      if (now <= dp[i - 1][j]) {
        int t = j + 1;
        while (1) {
          if (dp[i][t] < 9) break;
          t++;
        }
        dp[i][t]++;
        now = 0;
        if (t >= len[i]) {
          for (int j = 0; j < t; j++) dp[i][j] = 0;
          now += dp[i][t];
          len[i] = t + 1;
        } else {
          for (int j = 0; j < len[i]; j++) {
            if (j < t)
              dp[i][j] = 0;
            else
              now += dp[i][j];
          }
        }
        now = temp - now;
        t = 0;
        while (now > 0) {
          if (dp[i][t] == 9) {
            t++;
            continue;
          }
          dp[i][t]++;
          now--;
        }
        break;
      } else
        dp[i][j] = dp[i - 1][j], now -= dp[i - 1][j];
    }
  } else {
    len[i] = len[i - 1];
    now -= sum;
    for (int j = 0; j < len[i]; j++) dp[i][j] = dp[i - 1][j];
    int pos = 0;
    while (now > 0) {
      if (dp[i][pos] == 9) {
        pos++;
        continue;
      }
      dp[i][pos]++;
      now--;
    }
    if (pos >= len[i]) len[i] = pos + 1;
  }
}
void pre(int i, int now) {
  while (now > 9) {
    dp[i][len[i]] = 9;
    len[i]++;
    now -= 9;
  }
  if (now > 0) {
    dp[i][len[i]] = now;
    now = 0;
    len[i]++;
  }
}
int main() {
  while (cin >> n) {
    memset(len, 0, sizeof(len));
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
      int a;
      scanf("%d", &a);
      if (i == 1)
        pre(i, a);
      else
        cal(i, a);
    }
    for (int i = 1; i <= n; i++) {
      for (int j = len[i] - 1; j >= 0; j--) {
        printf("%d", dp[i][j]);
      }
      puts("");
    }
  }
}
