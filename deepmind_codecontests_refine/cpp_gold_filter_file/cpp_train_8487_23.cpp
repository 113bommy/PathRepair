#include <bits/stdc++.h>
using namespace std;
int n, k, t[200007];
double pre[200007], sum[200007], rev[200007], dp[57][200007];
double score(int k, int j, int i) {
  return dp[k - 1][j] + pre[i] - pre[j] - sum[j] * (rev[i] - rev[j]);
}
void solve(int k, int i1, int i2, int j1, int j2) {
  if (i1 > i2) return;
  int i = (i1 + i2) / 2, opt = j1;
  for (int j = j1; j <= min(j2, i); j++) {
    if (score(k, j, i) < score(k, opt, i)) {
      opt = j;
    }
  }
  dp[k][i] = score(k, opt, i);
  solve(k, i1, i - 1, j1, opt);
  solve(k, i + 1, i2, opt, j2);
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &t[i]);
    sum[i] = sum[i - 1] + t[i];
    rev[i] = rev[i - 1] + 1.0 / t[i];
    pre[i] = pre[i - 1] + sum[i] / t[i];
  }
  fill(dp[0] + 1, dp[0] + n + 1, 1e20);
  for (int i = 1; i <= k; i++) {
    solve(i, i, n, i - 1, n);
  }
  printf("%0.9f\n", dp[k][n]);
}
