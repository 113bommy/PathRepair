#include <bits/stdc++.h>
int n, m;
char str[(20)][(20)];
int a[(20)][(20)], dp[1 << (20)], logdown[1 << ((20) + 1)];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", str[i]);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 2; i < 1 << ((20) + 1); ++i) {
    logdown[i] = logdown[i >> 1] + 1;
  }
  memset(dp, 0x7f, sizeof(dp));
  dp[0] = 0;
  for (int mask = 0; mask < (1 << n) - 1; ++mask) {
    int sit = logdown[((~mask) & (-(~mask)))];
    for (int j = 0; j < m; ++j) {
      if (sit < n) {
        dp[mask ^ (1 << sit)] =
            std::min(dp[mask ^ (1 << sit)], dp[mask] + a[sit][j]);
      }
      int sum = 0, mxx = INT_MIN, _mask = mask;
      for (int i = 0; i < n; ++i) {
        if (str[i][j] == str[sit][j]) {
          sum += a[i][j];
          mxx = std::max(mxx, a[i][j]);
          _mask |= 1 << i;
        }
      }
      dp[_mask] = std::min(dp[_mask], dp[mask] + sum - mxx);
    }
  }
  printf("%d\n", dp[(1 << n) - 1]);
  return 0;
}
