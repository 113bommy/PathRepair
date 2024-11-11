#include <bits/stdc++.h>
using namespace std;
long long dp[119][2611];
long long f(int i, int j) {
  if (j < 0 || (i <= 0 && j != 0)) return 0;
  if (i <= 0 && j == 0) return 1;
  if (j < i) return 0;
  if (dp[i][j] >= 0) return dp[i][j];
  dp[i][j] = 0;
  for (int k = (1); k <= (26); ++k)
    dp[i][j] = (dp[i][j] + f(i - 1, j - k)) % (1000000007);
  return dp[i][j];
}
int main() {
  memset((dp), -1, sizeof(dp));
  int t;
  scanf("%d", &(t));
  while (t--) {
    char s[222];
    scanf("%s", (s));
    int cnt = 0;
    int len = strlen(s);
    for (int i = 0; i < (len); ++i) cnt += s[i] - 'a' + 1;
    printf("%I64d\n", f(len, cnt)) - 1;
  }
  return 0;
}
