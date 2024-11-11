#include <bits/stdc++.h>
using namespace std;
int n, k, dp[2][1010];
char s[1010];
int main() {
  scanf("%d %d", &n, &k);
  scanf(" %s", s + 1);
  dp[0][0] = dp[1][0] = 0;
  for (int i = 1; i < (n); i++) {
    if (s[i] == '?') {
      dp[0][i] = max(dp[0][i - 1] - 1, -(k - 1));
      dp[1][i] = min(dp[1][i - 1] + 1, k - 1);
    } else if (s[i] == 'W') {
      if (dp[0][i - 1] < k - 1)
        dp[0][i] = dp[0][i - 1] + 1;
      else {
        puts("NO");
        return 0;
      }
      dp[1][i] = min(dp[1][i - 1] + 1, k - 1);
    } else if (s[i] == 'D') {
      dp[0][i] = dp[0][i - 1];
      dp[1][i] = dp[1][i - 1];
    } else if (s[i] == 'L') {
      dp[0][i] = max(dp[0][i - 1] - 1, -(k - 1));
      if (dp[1][i - 1] > -(k - 1))
        dp[1][i] = dp[1][i - 1] - 1;
      else {
        puts("NO");
        return 0;
      }
    }
  }
  if (dp[0][n - 1] == -(k - 1) && (s[n] == 'L' || s[n] == '?')) {
    int now = -k;
    s[n] = 'L', now++;
    for (int i = n - 1; i; i--) {
      if (s[i] == 'D')
        continue;
      else if (s[i] == 'L')
        now += 1;
      else if (s[i] == 'W')
        now -= 1;
      else {
        if (now - 1 >= dp[0][i - 1])
          s[i] = 'W', now--;
        else if (now + 1 <= dp[1][i - 1])
          s[i] = 'L', now++;
        else
          s[i] = 'D';
      }
    }
    printf("%s\n", s + 1);
  } else if (dp[1][n - 1] == k - 1 && (s[n] == 'W' || s[n] == '?')) {
    int now = k;
    s[n] = 'W', now--;
    for (int i = n - 1; i; i--) {
      if (s[i] == 'D')
        continue;
      else if (s[i] == 'L')
        now += 1;
      else if (s[i] == 'W')
        now -= 1;
      else {
        if (now - 1 >= dp[0][i - 1])
          s[i] = 'W', now--;
        else if (now + 1 <= dp[1][i - 1])
          s[i] = 'L', now++;
        else
          s[i] = 'D';
      }
    }
    printf("%s\n", s + 1);
  } else
    puts("NO");
}
