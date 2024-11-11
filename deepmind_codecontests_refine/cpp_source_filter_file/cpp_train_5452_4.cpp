#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  double arc[100000] = {0};
  for (int i = 0; i < n; ++i) {
    double x, y;
    scanf("%lf%lf", &x, &y);
    arc[i] = atan2(y, x) / 3.1415926535897932384626433832795 * 180.0;
    if (arc[i] < 0.0) arc[i] += 360.0;
  }
  std::sort(arc, arc + n);
  double ans = 0;
  for (int i = 0; i < n; ++i) {
    ans = std::max(ans, arc[i] - arc[i - 1]);
  }
  printf("%.6lf", 360.0 - std::max(ans, 360.0 - (arc[n - 1] - arc[0])));
}
