#include <bits/stdc++.h>
using namespace std;
int n, k;
int cnt[41];
int fie[41][41];
int dp[1 << 21];
int main(void) {
  scanf("%d%d", &n, &k);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &fie[i][j]);
    }
  }
  for (int bit = 0; bit < (1 << (n / 2)); bit++) {
    bool flag = true;
    for (int i = 0; i < n; i++) {
      if (!flag) break;
      if (!((bit >> i) & 1)) continue;
      for (int j = i + 1; j < n / 2; j++) {
        if (!flag) break;
        if (!((bit >> j) & 1)) continue;
        if (fie[i][j] == 0) flag = false;
      }
    }
    if (!flag) continue;
    dp[bit] = __builtin_popcount(bit);
  }
  int res = 0;
  for (int i = 0; i < (1 << (n / 2)); i++) {
    for (int j = 0; j < (n / 2); j++) {
      if (((i >> j) & 1)) {
        dp[i] = max(dp[i], dp[i - (1 << j)]);
      }
    }
    res = max(res, dp[i]);
  }
  int rest = n - (n / 2);
  for (int bit = 0; bit < (1 << rest); bit++) {
    bool flag = true;
    for (int i = n / 2; i < n; i++) {
      if (!flag) break;
      if (!(bit >> (i - n / 2) & 1)) continue;
      for (int j = i + 1; j < n; j++) {
        if (!flag) break;
        if (!(bit >> (j - n / 2) & 1)) continue;
        if (fie[i][j] == 0) flag = false;
      }
    }
    if (!flag) continue;
    int bit2 = (1 << (n / 2)) - 1;
    for (int i = n / 2; i < n; i++) {
      if (!((bit >> (i - n / 2)) & 1)) continue;
      for (int j = 0; j < n / 2; j++) {
        if (fie[i][j] == 0 && ((bit2 >> j) & 1)) {
          bit2 -= (1 << j);
        }
      }
    }
    res = max(res, __builtin_popcount(bit) + dp[bit2]);
  }
  long double ans =
      (long double)(res - 1.0) * (long double)k * (long double)k / 2.0;
  ans /= (long double)res;
  printf("%.10f\n", (double)ans);
  return 0;
}
