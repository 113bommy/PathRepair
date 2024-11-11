#include <bits/stdc++.h>
using namespace std;
int n;
long double A[73][73] = {0};
long double dp[73][73] = {0}, h[73][73] = {0};
bool flag[73][73] = {0}, flagh[73][73] = {0};
void opp(int i, int k, int &l, int &r) {
  int len = 1 << k;
  l = 1, r = 1 << n;
  while (r - l + 1 > len) {
    int mid = (l + r) >> 1;
    if (i > mid)
      l = mid + 1;
    else
      r = mid;
  }
  len = 1 << (k - 1);
  if (l <= i && i <= l + len - 1)
    l += len;
  else
    r -= len;
}
long double f(int i, int k) {
  if (k == 0) return 1.0;
  if (flag[i][k]) return dp[i][k];
  int l, r;
  opp(i, k, l, r);
  dp[i][k] = 0;
  for (int j = l; j <= r; j++) dp[i][k] += A[i][j] * f(j, k - 1);
  dp[i][k] *= f(i, k - 1);
  flag[i][k] = true;
  return dp[i][k];
}
long double g(int i, int k) {
  if (k == 0) return 0.0;
  if (flagh[i][k]) return h[i][k];
  int l, r;
  opp(i, k, l, r);
  h[i][k] = 0.0;
  for (int j = l; j <= r; j++) h[i][k] = max(h[i][k], g(j, k - 1));
  h[i][k] += g(i, k - 1) + f(i, k) * (long double)(1 << (k - 1));
  flagh[i][k] = true;
  return h[i][k];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= (1 << n); i++)
    for (int j = 1; j <= (1 << n); j++) {
      int x;
      scanf("%d", &x);
      A[i][j] = (long double)x / 100.0;
    }
  long double ans = 0;
  for (int i = 1; i <= n; i++) ans = max(ans, g(i, n));
  printf("%.10Lf\n", ans);
  return 0;
}
