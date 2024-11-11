#include <bits/stdc++.h>
using namespace std;
int n, m, b;
struct fd {
  int cost, mon, solve;
  bool operator<(const fd &k) const { return mon < k.mon; }
};
long long dp[1 << 21], res = (1LL << 60);
fd f[101];
int main() {
  scanf("%d %d %d", &n, &m, &b);
  for (int i = (1); i <= ((1 << n) - 1); i++) dp[i] = (1LL << 60);
  for (int i = (1); i <= (n); i++) {
    int w;
    scanf("%d %d %d", &f[i].cost, &f[i].mon, &w);
    for (int j = (1); j <= (w); j++) {
      int x;
      scanf("%d", &x);
      f[i].solve += (1 << x - 1);
    }
  }
  sort(f + 1, f + n + 1);
  for (int i = (1); i <= (n); i++) {
    for (int j = (0); j <= ((1 << n) - 1); j++)
      dp[j | f[i].solve] = min(dp[j | f[i].solve], dp[j] + f[i].cost);
    res = min(res, dp[(1 << n) - 1] + 1LL * b * f[i].mon);
  }
  if (res == (1LL << 60)) res = -1;
  printf("%lld\n", res);
  return 0;
}
