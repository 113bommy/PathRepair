#include <bits/stdc++.h>
using namespace std;
char s[524288], t[524288];
int st[524288][25], d[524288][25], num[524288];
int dp2[524288][25], pre2[524288][25], now[524288], dp[524288], pre[524288];
int st2[32], d2[32], num2, now2;
void add1(int val) {
  if (now2 < 0) {
    now2 = val;
    return;
  }
  if (num2 == 0 || d2[num2 - 1] != now2 - val) {
    st2[num2] = now2;
    d2[num2] = now2 - val;
    num2++;
  }
  now2 = val;
}
void add2(int stt, int edd, int dd) {
  add1(stt);
  if (stt == edd) {
    return;
  }
  add1(stt - dd);
  now2 = edd;
}
int main() {
  scanf("%s%s", s + 1, t + 1);
  int n = strlen(s + 1);
  for (int i = 1; i <= n; i++) {
    num2 = 0;
    now2 = -1;
    for (int j = 0; j < num[i - 1]; j++) {
      if (s[i - st[i - 1][j] - 1] == t[i] && t[i - st[i - 1][j] - 1] == s[i]) {
        add1(st[i - 1][j] + 2);
      }
      int val = st[i - 1][j] - d[i - 1][j];
      if (val == st[i - 1][j + 1]) {
        continue;
      }
      if (s[i - val - 1] == t[i] && t[i - val - 1] == s[i]) {
        add2(val + 2, st[i - 1][j + 1] + d[i - 1][j] + 2, d[i - 1][j]);
      }
    }
    if (s[i - 1] == t[i] && t[i - 1] == s[i]) {
      add1(2);
    }
    if (s[i] == t[i]) {
      add1(1);
    }
    add1(0);
    num[i] = num2;
    now[i] = num2 - 1;
    dp[i] = 1000000;
    for (int j = 0; j < num2; j++) {
      st[i][j] = st2[j];
      d[i][j] = d2[j];
      dp2[i][j] = 1000000;
      if ((st2[j] - 1) / d2[j] <= 2) {
        for (int k = st2[j]; k > 0; k -= d2[j]) {
          if (dp[i - k] < dp2[i][j]) {
            dp2[i][j] = dp[i - k] + 1;
            pre2[i][j] = i - k;
          }
        }
      } else {
        int &k = now[i - d2[j]];
        while (d[i - d2[j]][k] != d2[j]) {
          k--;
        }
        dp2[i][j] = dp2[i - d2[j]][k];
        pre2[i][j] = pre2[i - d2[j]][k];
        int dd = st2[j] % d2[j];
        if (dd == 0) {
          dd = d2[j];
        }
        if (dp[i - dd] < dp2[i][j]) {
          dp2[i][j] = dp[i - dd] + 1;
          pre2[i][j] = i - dd;
        }
      }
      if (dp2[i][j] < dp[i]) {
        dp[i] = dp2[i][j];
        pre[i] = pre2[i][j];
      }
    }
    if (s[i] == t[i]) {
      if (dp[i - 1] < dp[i]) {
        pre[i] = i - 1;
        dp[i] = dp[i - 1];
      }
    }
  }
  if (dp[n] > n) {
    printf("-1\n");
    return 0;
  }
  printf("%d\n", dp[n]);
  for (int i = n; i > 0; i = pre[i]) {
    if (pre[i] < i - 1) {
      printf("%d %d\n", pre[i] + 1, i);
    }
  }
  return 0;
}
