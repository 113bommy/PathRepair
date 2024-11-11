#include <bits/stdc++.h>
int dp[15][1000005], f[15][100005];
long long n, ans = 0;
int find(int x) { return !x ? 0 : std::max(x % 10, find(x / 10)); }
int main() {
  for (int x = 0; x <= 9; x++)
    for (int i = 0; i < 1000000; i++) {
      if (x == 0 && i == 0) {
        dp[x][i] = f[x][i] = 0;
        continue;
      }
      dp[x][i] = 1000000000;
      int delta = std::max(x, find(i));
      int t = i - delta;
      dp[x][i] = (t < 0 ? 1 : dp[x][t] + 1), f[x][i] = (t < 0 ? t : f[x][t]);
    }
  scanf("%lld", &n);
  int x = n / 1000000, y = n % 1000000;
  while (1) {
    int k = find(x);
    ans = ans + dp[k][y];
    if (x == 0) break;
    --x, y = 1000000 + f[k][y];
  }
  printf("%lld\n", ans);
  return 0;
}
