#include <bits/stdc++.h>
using namespace std;
const double s2 = 1.4142135624;
int main() {
  int m, r;
  scanf("%d%d", &m, &r);
  if (m == 1) {
    printf("%.10lf\n", 2.0 * r);
    return 0;
  }
  if (m == 2) {
    printf("%.10lf\n", 2.7071067812 * r);
    return 0;
  }
  double ans = 0.0;
  ans += m * 2.0 + (2 + s2) * (m - 1) * 2;
  for (int i = 3; i <= m; i++) {
    ans += ((i - 2) * 2.0 + s2 * 2) * (m - i + 1) * 2;
  }
  printf("%.10lf\n", ans / m / m);
  return 0;
}
