#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int MOD = 1e9 + 7;
const int mx = 10000;
const int N = 110;
int n, l[N], r[N], k;
double p[10][10100][10], dp[10][10100][10], used[10][10100][10];
double solve(int i, int j, int t, int s) {
  if (used[i][j][t] == k) return dp[i][j][t];
  if (i > n) {
    if (t == 0)
      dp[i][j][t] = 1;
    else
      dp[i][j][t] = 0;
    return dp[i][j][t];
  }
  if (i == s) {
    dp[i][j][t] = solve(i + 1, j, t, s);
    return dp[i][j][t];
  }
  int l1, r1;
  dp[i][j][t] = 0;
  l1 = l[i];
  r1 = min(r[i], j - 1);
  if (l1 <= r1)
    dp[i][j][t] = dp[i][j][t] + (1.0 * (r1 - l1 + 1) / (r[i] - l[i] + 1)) *
                                    solve(i + 1, j, t, s);
  if (t > 0 && j >= l[i] && j <= r[i])
    dp[i][j][t] =
        dp[i][j][t] + (1.0 / (r[i] - l[i] + 1)) * solve(i + 1, j, t - 1, s);
  return dp[i][j][t];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &l[i], &r[i]);
  k = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= mx; j++) {
      for (int t = 1; t < n; t++) {
        k++;
        p[i][j][t] = solve(1, j, t, i);
      }
    }
  }
  double ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= mx; j++) {
      int l1, r1;
      l1 = max(l[i], j + 1);
      r1 = r[i];
      double p1 = 0;
      for (int t = 1; t < n; t++) p1 += p[i][j][t];
      if (l1 <= r1) ans += (1.0 * (r1 - l1 + 1) / (r[i] - l[i] + 1)) * p1 * j;
      if (j >= l[i] && j <= r[i]) {
        for (int t = 1; t < n; t++) {
          ans += (1.0 / (r[i] - l[i] + 1)) * p[i][j][t] * (1.0 / (t + 1)) * j;
        }
      }
    }
  cout << fixed << setprecision(9) << ans;
  return 0;
}
