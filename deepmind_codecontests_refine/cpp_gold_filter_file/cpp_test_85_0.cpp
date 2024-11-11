#include <bits/stdc++.h>
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
int vv[202 + 1], ff[202 + 1], gg[202 + 1];
void init(int md) {
  int i;
  ff[0] = gg[0] = 1;
  for (i = 1; i <= 202; i++) {
    vv[i] = i == 1 ? 1 : (long long)vv[i - md % i] * (md / i + 1) % md;
    ff[i] = (long long)ff[i - 1] * i % md;
    gg[i] = (long long)gg[i - 1] * vv[i] % md;
  }
}
int main() {
  static int dp[202 + 1][202 + 1];
  int n, md, a, b, k, l, s, ans;
  scanf("%d%d", &n, &md), init(md);
  ans = 0;
  for (a = 1; a <= n + 1; a++) {
    for (k = 0; k <= n; k++) memset(dp[k], 0, (a + 1) * sizeof *dp[k]);
    dp[0][0] = 1;
    for (b = a; b <= n + 1; b++) {
      for (k = n; k >= 0; k--)
        for (s = 0; s + (n - k) * (b - a) <= a && s + k * a <= a * (b - 1);
             s++) {
          int x = dp[k][s], k_, s_, lower, upper;
          if (x == 0) continue;
          lower = max(1, s + (n - k) * (b + 1 - a) - a);
          upper = min(n - k, (a * b - s - k * a) / b);
          for (l = lower; l <= upper; l++) {
            k_ = k + l, s_ = s + l * (b - a);
            dp[k_][s_] = (dp[k_][s_] + (long long)dp[k][s] * gg[l]) % md;
          }
        }
      if (b == a) dp[0][0] = 0;
    }
    for (s = 0; s <= a; s++) ans = (ans + (long long)dp[n][s] * ff[n]) % md;
  }
  printf("%d\n", ans);
  return 0;
}
