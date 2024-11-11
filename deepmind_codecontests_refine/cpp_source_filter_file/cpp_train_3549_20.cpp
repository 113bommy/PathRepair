#include <bits/stdc++.h>
using namespace std;
int a[1010];
int b[1010];
int n, m;
bool check(double x) {
  double weight = x + m;
  double tot = x;
  for (int i = 1; i <= n; i++) {
    if (i == 1) {
      double tmp = weight / a[i];
      weight -= tmp;
      tot -= tmp;
      if (tot < 0) return false;
    } else if (i == n) {
      double tmp1 = weight / b[i];
      weight = weight - tmp1;
      tot -= tmp1;
      if (tot < 0) return false;
      double tmp2 = weight / a[i];
      weight = weight - tmp2;
      tot -= tmp2;
      if (tot < 0) return false;
      double tmp3 = weight / b[1];
      weight = weight - tmp3;
      tot -= tmp3;
      if (tot < 0) return false;
    } else {
      double tmp1 = weight / b[i];
      weight = weight - tmp1;
      tot -= tmp1;
      if (tot < 0) return false;
      double tmp2 = weight / a[i];
      weight = weight - tmp2;
      tot -= tmp2;
      if (tot < 0) return false;
    }
  }
  return true;
}
int main() {
  scanf("%d", &n);
  scanf("%d", &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  double le = 0, ri = 1e9;
  double ans;
  for (int i = 1; i <= 100; i++) {
    double mid = (le + ri) / 2;
    if (check(mid)) {
      ri = mid;
      ans = mid;
    } else {
      le = mid;
    }
  }
  if (ans > 0)
    printf("%.10lf\n", ans);
  else
    printf("-1\n");
}
