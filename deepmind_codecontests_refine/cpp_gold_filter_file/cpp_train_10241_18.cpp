#include <bits/stdc++.h>
using namespace std;
int x[5 * 100010];
int v[5 * 100010];
double eps = 0.000000001;
int n;
bool check(double t) {
  double rightmost = -(1e10) - 10;
  for (int i = 0; i < n; i++) {
    if (v[i] < 0) {
      if (rightmost > x[i] * 1.0f + t * v[i]) return true;
    } else
      rightmost = max(rightmost, x[i] + t * v[i]);
  }
  return false;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d", &x[i], &v[i]);
  bool ok = false;
  bool more = false;
  for (int i = 0; i < n; i++) {
    if (v[i] > 0) more = true;
    if (v[i] < 0 && more) ok = true;
  }
  if (!ok) {
    printf("-1\n");
    return 0;
  }
  double low = 0, high = 1e9 + 10;
  for (int i = 0; i < 100; i++) {
    double mid = (low + high) / 2.0f;
    if (check(mid))
      high = mid;
    else
      low = mid;
  }
  printf("%.15lf\n", low);
  return 0;
}
