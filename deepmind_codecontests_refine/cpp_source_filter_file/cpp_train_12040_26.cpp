#include <bits/stdc++.h>
using namespace std;
int sv[1000006], dp[1000006][10];
int digit_mul(int n) {
  int i, j, k = 1, x;
  while (n > 0) {
    x = n % 10;
    if (x != 0) k = k * x;
    n = n / 10;
  }
  return k;
}
int main() {
  int i, j, k, n, temp, q, l, r;
  for (i = 1; i < 1000006; i++) {
    temp = i;
    while (temp >= 10) {
      temp = digit_mul(temp);
    }
    sv[i] = temp;
  }
  memset(dp, 0, sizeof(dp));
  for (i = 1; i < 10; i++) {
    for (j = 1; j < 1000006; j++) {
      if (sv[j] == i) {
        dp[j][i] = dp[j - 1][i] + 1;
      } else {
        dp[j][i] = dp[j - 1][i];
      }
    }
  }
  scanf("%d", &q);
  while (q--) {
    scanf("%d %d %d", &l, &r, &k);
    int ans = dp[r + 1][k] - dp[l - 1][k];
    printf("%d", ans);
    puts("");
  }
  return 0;
}
