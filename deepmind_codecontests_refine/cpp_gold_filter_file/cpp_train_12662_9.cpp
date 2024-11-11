#include <bits/stdc++.h>
using namespace std;
const int maxd = 1e9 + 7, pri[] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29,
                                   31, 37, 41, 43, 47, 53, 59, 61, 67};
int n, cnt[71], sit[71], dp[71][1 << 19], powe[100500];
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while ((ch < '0') || (ch > '9')) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ((ch >= '0') && (ch <= '9')) {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x * f;
}
void init() {
  int i, j;
  memset(sit, 0, sizeof(sit));
  for (i = 2; i <= 70; i++) {
    int x = i;
    for (j = 0; j < 19; j++) {
      while (x % pri[j] == 0) {
        x /= pri[j];
        sit[i] ^= (1 << j);
      }
    }
  }
}
int main() {
  n = read();
  init();
  int i, j, all = (1 << 19);
  memset(cnt, 0, sizeof(cnt));
  for (i = 1; i <= n; i++) {
    int x = read();
    cnt[x]++;
  }
  powe[0] = 1;
  for (i = 1; i <= n; i++) powe[i] = (powe[i - 1] * 2) % maxd;
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (i = 1; i <= 70; i++) {
    if (cnt[i]) {
      for (j = 0; j < all; j++) {
        dp[i][j] =
            ((long long)dp[i][j] + (long long)dp[i - 1][j] * powe[cnt[i] - 1]) %
            maxd;
        dp[i][j ^ sit[i]] = ((long long)dp[i][j ^ sit[i]] +
                             (long long)dp[i - 1][j] * powe[cnt[i] - 1]) %
                            maxd;
      }
    } else {
      for (j = 0; j < all; j++) dp[i][j] = dp[i - 1][j];
    }
  }
  printf("%d", (dp[70][0] - 1 + maxd) % maxd);
  return 0;
}
