#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int dp[2][20005];
inline void add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
int main() {
  int n;
  scanf("%d", &n);
  int ans = 0, now = 0;
  for (int _i = 1; _i <= n; ++_i) {
    memset(dp[now], 0, sizeof dp[now]);
    int x;
    scanf("%d", &x);
    add(ans, dp[now ^ 1][x + 10000]), add(ans, dp[now ^ 1][-x + 10000]);
    dp[now][x + 10000] = dp[now][-x + 10000] = 1;
    for (int i = x + 1; i <= 20000 - x; ++i) {
      if (dp[now ^ 1][i]) {
        add(dp[now][i + x], dp[now ^ 1][i]);
        add(dp[now][i - x], dp[now ^ 1][i]);
      }
    }
    now ^= 1;
  }
  printf("%d\n", ans);
  return 0;
}
