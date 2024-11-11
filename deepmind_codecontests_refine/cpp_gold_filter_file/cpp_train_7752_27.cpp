#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const double E = 2.7182818284590452353602874713527;
const int MAXN = 105;
int a[MAXN], b[MAXN];
double dp[MAXN], dp2[MAXN];
double fx(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int ok(double x, double y) {
  if (x < y || fabs(x - y) < eps) return 1;
  return 0;
}
int main() {
  int n, k, e;
  scanf("%d", &n);
  scanf("%d%d", &k, &e);
  int x, y;
  scanf("%d%d", &x, &y);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i], &b[i]);
    if (x == a[i] && y == b[i]) cnt++;
  }
  if (cnt >= k) {
    printf("%.9lf\n", 0.0);
    return 0;
  }
  double l = 0, r = 3000.0;
  double ans = r;
  while (r - l > eps) {
    double mid = (l + r) / 2;
    cnt = 0;
    vector<int> q;
    for (int i = 1; i <= n; i++) {
      if (ok(fx(a[i], b[i], x, y), mid))
        cnt++;
      else
        q.push_back(i);
    }
    if (cnt >= k) {
      ans = mid;
      r = mid;
      continue;
    }
    int mx = n - cnt;
    cnt = k - cnt;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1.0;
    for (int i = 0; i < mx; i++) {
      memset(dp2, 0, sizeof(dp2));
      int id = q[i];
      double temp = fx(a[id], b[id], x, y);
      temp = pow(E, (1.0 - temp * temp / mid / mid));
      for (int j = 0; j <= mx; j++) {
        if (j > 0) dp2[j] += dp[j - 1] * temp;
        dp2[j] += dp[j] * (1.0 - temp);
      }
      for (int j = 0; j <= mx; j++) dp[j] = dp2[j];
    }
    double A = 0.0;
    for (int i = cnt; i <= mx; i++) A += dp[i];
    if (ok(1.0 - e * 1.0 / 1000, A)) {
      ans = mid;
      r = mid;
    } else
      l = mid;
  }
  printf("%.9lf\n", ans);
  return 0;
}
