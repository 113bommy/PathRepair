#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
const int maxm = 5e3 + 110;
double dp[maxn][maxm];
struct node {
  int f, s;
  double p;
} a[maxn];
int main() {
  int n, R;
  scanf("%d %d", &n, &R);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %lf", &a[i].f, &a[i].s, &a[i].p);
    a[i].p = a[i].p / 100.0;
  }
  double l = 0, r = 1e15, ans = 0;
  for (int ii = 0; ii <= 100; ii++) {
    double mid = (l + r) / 2.0;
    for (int j = 0; j <= R; j++) dp[n + 1][j] = j;
    for (int j = R + 1; j <= 5100; j++) dp[n + 1][j] = 0x3f3f3f3f;
    for (int i = n; i >= 1; i--) {
      for (int j = 5005; j >= 0; j--) {
        dp[i][j] = dp[i + 1][j + a[i].f] * a[i].p +
                   dp[i + 1][j + a[i].s] * (1 - a[i].p);
        dp[i][j] =
            min(dp[i][j], dp[i + 1][j + a[i].f] * a[i].p +
                              (1 - a[i].p) * (mid + (double)(j + a[i].s)));
        dp[i][j] =
            min(dp[i][j], a[i].p * ((double)(j + a[i].f) + mid) +
                              (1 - a[i].p) * ((double)(j + mid) + a[i].s));
      }
    }
    if (dp[1][0] > mid) {
      ans = mid;
      l = mid;
    } else
      r = mid;
  }
  printf("%.9f\n", ans);
  return 0;
}
