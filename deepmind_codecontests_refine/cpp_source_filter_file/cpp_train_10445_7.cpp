#include <bits/stdc++.h>
using namespace std;
int n, l, p[300], a[300];
double dp[205][205][205];
double f(int i, int w, int c) {
  if (i == n) {
    if (w >= l && c >= w) return 1.0;
    return 0.0;
  }
  if (dp[i][w][c] > -0.5) return dp[i][w][c];
  double r, pp, q;
  int cc;
  pp = (double)p[i] / 100.0;
  q = 1.0 - pp;
  if (a[i] == -1) {
    r = pp * f(i + 1, w + 1, c) + q * f(i + 1, w, c);
  } else {
    cc = c + a[i];
    if (cc >= n) cc = n;
    r = pp * f(i + 1, w + 1, cc) + q * f(i + 1, w, c);
  }
  return dp[i][w][c] = r;
}
int main() {
  int i, j, k, m;
  scanf("%d %d %d", &n, &l, &k);
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= n; j++) {
      for (m = 0; m <= n; m++) dp[i][j][m] = -1.0;
    }
  }
  for (i = 0; i < n; i++) scanf("%d", &p[i]);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  if (k >= n) k = n;
  printf("%.10lf\n", f(0, 0, k));
  return 0;
}
