#include <bits/stdc++.h>
char s[100006];
long long dp[2][2];
int main() {
  scanf("%s", s);
  int len = strlen(s);
  int i, j;
  for (i = 0; i < 2; i++)
    for (j = 0; j < 2; j++) dp[i][j] = 0;
  long long odd = 0, even = 0;
  for (i = 0; i < len; i++) {
    int tmp = s[i] - 'a';
    dp[tmp][i % 2]++;
    even += dp[tmp][(i % 2) ^ 1];
    odd += dp[tmp][(i % 2)];
  }
  printf("%d %d", even, odd);
  return 0;
}
