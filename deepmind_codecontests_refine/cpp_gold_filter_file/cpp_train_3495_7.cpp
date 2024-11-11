#include <bits/stdc++.h>
int dp[(1000010)][(25)];
int leftPrime[(1000010)];
void preDp() {
  for (int i = 1; i < (25); ++i) dp[0][i] = 2;
  for (int i = 0; i < (1000010); ++i) dp[i][0] = 1;
  for (int i = 1; i < (1000010); ++i) {
    for (int j = 1; j < (25); ++j) {
      dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % (1000000007);
    }
  }
}
void preLeftPrime() {
  for (int i = 2; i < (1000010); ++i) {
    if (!leftPrime[i]) {
      for (int j = i; j < (1000010); j += i) {
        leftPrime[j] = i;
      }
    }
  }
}
int getans(int r, int n) {
  int res = 1;
  while (n != 1) {
    int cnt = 0, pri = leftPrime[n];
    while (!(n % pri)) {
      n /= pri;
      ++cnt;
    }
    res = (1ll) * res * dp[r][cnt] % (1000000007);
  }
  return res;
}
int main() {
  preDp();
  preLeftPrime();
  int q, r, n;
  scanf("%d", &q);
  for (int i = 1; i <= q; ++i) {
    scanf("%d%d", &r, &n);
    printf("%d\n", getans(r, n));
  }
  return 0;
}
