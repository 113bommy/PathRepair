#include <bits/stdc++.h>
using namespace std;
double as[100005];
int main() {
  int n, a, d;
  while (scanf("%d%d%d", &n, &a, &d) > 0) {
    for (int i = 1; i <= n; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      double s = (1.0 * y * y) / (2.0 * a);
      double t = 0.0;
      if (s <= d)
        t = (y * 1.0) / (a * 1.0) + (1.0 * (d - s)) / (1.0 * y);
      else
        t = sqrt(2.0 * d / (1.0 * a));
      if (i >= 2 && t + (double)x < as[i - 1])
        as[i] = as[i - 1];
      else
        as[i] = t + (double)x;
    }
    for (int i = 1; i <= n; i++) printf("%.8f\n", as[i]);
  }
}
