#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
const int MOD = 1000000007;
int n, k, t[N], curK;
double dp[N][51], pr[N], rv[N], sum[N];
double exp(int l, int r) {
  return (pr[r] - pr[l - 1]) - (rv[r] - rv[l - 1]) * sum[l - 1];
}
void solve(int l, int r, int x, int y) {
  if (l > r) return;
  int md = (l + r) / 2;
  double &ret = dp[md][curK];
  ret = 1e15;
  int op = -1;
  for (int i = max(x, md); i <= y; ++i) {
    double cp = exp(md, i) + dp[i + 1][curK - 1];
    if (i >= x && cp < ret) {
      ret = cp;
      op = i;
    }
  }
  solve(md + 1, r, op, y);
  solve(l, md - 1, x, op);
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &t[i]);
    sum[i] = t[i] + sum[i - 1];
    rv[i] = 1.0 / t[i] + rv[i - 1];
    pr[i] = sum[i] / t[i] + pr[i - 1];
  }
  double cur = 0.0, sumA = 0.0;
  for (int i = n; i >= 1; --i) {
    dp[i][1] = exp(i, n);
  }
  for (curK = 2; curK <= k; ++curK) {
    solve(1, n, 1, n);
  }
  printf("%.9lf\n", dp[1][k]);
  return 0;
}
