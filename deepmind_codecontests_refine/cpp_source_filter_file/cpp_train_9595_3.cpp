#include <bits/stdc++.h>
int x = 0, dp[1005][1005], s[1005][1005];
int n, k, ans[1005], a[1005], p;
void solve(int val) {
  dp[0][0] = 1;
  s[0][0] = 1;
  x = 0;
  for (int i = 1; i <= n; i++) {
    while (a[i] - a[x] >= val) ++x;
    dp[i][0] = 1;
    s[i][0] = 1;
    for (int j = 1; j <= k; j++) dp[i][j] = s[x - 1][j - 1];
    for (int j = 1; j <= k; j++) s[i][j] = (s[i - 1][j] + dp[i][j]) % 998244353;
  }
  for (int i = 1; i <= n; i++) ans[val] = (ans[val] + dp[i][k]) % 998244353;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  a[0] = -1000000000;
  std::sort(a + 1, a + n + 1);
  for (int i = 1; i * (k - 1) <= a[n]; i++) solve(i);
  for (int i = 1; i * (k - 1) <= a[n]; i++) p = (p + ans[i]) % 998244353;
  printf("%d\n", p);
  return 0;
}
