#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int r, n, t[N], x[N], y[N], dp[N];
bool check(int i, int j) {
  return abs(x[i] - x[j]) + abs(y[i] - y[j]) <= abs(t[i] - t[j]);
}
int main() {
  scanf("%d %d", &r, &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d %d", t + i, x + i, y + i);
  }
  t[0] = 0;
  x[0] = y[0] = 1;
  memset(dp, -0x3f3f3f3f, (n + 1) * sizeof(dp[0]));
  dp[0] = 0;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = max(0, i - 4 * (r - 1)); j < i; ++j) {
      if (check(i, j)) {
        dp[i] = max(dp[i], 1 + dp[j]);
      }
    }
    ans = max(ans, dp[i]);
  }
  printf("%d\n", ans);
  return 0;
}
