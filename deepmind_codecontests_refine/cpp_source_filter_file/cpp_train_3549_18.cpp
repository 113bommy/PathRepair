#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const int NMAX = 1010;
int n, m;
int a[NMAX], b[NMAX];
double ans;
bool check(double mid) {
  double remain = mid;
  remain -= (m + remain) / a[1];
  for (int i = 2; i <= n; i++) {
    remain -= (m + remain) / b[i];
    if (remain < 0) return false;
    remain -= (m + remain) / a[i];
    if (remain < 0) return false;
  }
  remain -= (m + remain) / b[1];
  if (remain < 0) return false;
  return true;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  double l = 0, r = 1e10;
  bool found = false;
  while (r - l > eps) {
    double mid = (l + r) / 2;
    if (check(mid)) {
      ans = mid;
      found = true;
      r = mid - eps;
    } else
      l = mid + eps;
  }
  if (found)
    printf("%.8lf\n", ans);
  else
    printf("-1\n");
  return 0;
}
