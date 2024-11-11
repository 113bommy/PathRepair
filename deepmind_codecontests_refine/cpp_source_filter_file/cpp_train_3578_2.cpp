#include <bits/stdc++.h>
using namespace std;
const long long M = 1000000007;
int m;
long long sum = 0;
int cnt[20];
long long dp[15][2][15];
void DP() {
  int digit[10];
  memset(digit, 0, sizeof(digit));
  int mm = m;
  int index = 1;
  while (mm > 0) {
    digit[index++] = mm % 10;
    mm /= 10;
  }
  memset(dp, 0, sizeof(dp));
  dp[0][0][0] = 1;
  for (int i = 1; i <= 10; i++) {
    for (int j = 0; j <= i; j++) {
      dp[i][0][j] = 8 * dp[i - 1][0][j];
      if (j > 0) dp[i][0][j] += dp[i - 1][0][j - 1] * 2;
      for (int k = 0; k < digit[i]; k++) {
        if (k == 4 || k == 7)
          dp[i][1][j] += dp[i - 1][0][j - 1];
        else
          dp[i][1][j] += dp[i - 1][0][j];
      }
      if (digit[i] == 4 || digit[i] == 7)
        dp[i][1][j] += dp[i - 1][1][j - 1];
      else
        dp[i][1][j] += dp[i - 1][1][j];
    }
  }
  for (int i = 0; i <= 10; i++) {
    cnt[i] = dp[10][1][i];
  }
  cnt[0]--;
}
void Search(int depth, int left, long long ways) {
  ways %= M;
  if (depth == 0) {
    sum += ways;
    sum %= M;
    return;
  }
  for (int i = 0; i <= left; i++) {
    if (cnt[i] > 0) {
      Search(depth - 1, left - i, ways * cnt[i]--);
      cnt[i]++;
    }
  }
}
int main() {
  scanf("%d", &m);
  m++;
  for (int i = 10; i > 0; i--) {
    if (cnt[i] == 0) continue;
    Search(6, i - 1, cnt[i]);
  }
  cout << sum << endl;
  return 0;
}
