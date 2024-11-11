#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-5;
int a[100005], b[100005], n, p;
bool check(double x) {
  double ans = 0;
  for (int i = 0; i < n; i++) ans += max(0.0, (a[i] * x - b[i]) / p);
  if (ans - x > eps) return false;
  return true;
}
int main() {
  scanf("%d%d", &n, &p);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a[i], &b[i]);
    sum += a[i];
  }
  if (p >= sum)
    printf("-1\n");
  else {
    double l = 0, r = 0x3f3f3f3f3f;
    double mid, ans;
    while (l - r < eps) {
      mid = (l + r) / 2;
      if (check(mid)) {
        ans = mid;
        l = mid + eps;
      } else
        r = mid - eps;
    }
    printf("%.10lf\n", ans);
  }
}
