#include <bits/stdc++.h>
using namespace std;
int n;
int judge(double x, double y) {
  y += 1;
  return sqrt(x * x + y * y) <= (double)n + 1e-9;
}
int main() {
  scanf("%d", &n);
  long long ans = 1;
  double d = sqrt(3) * 3 / 2;
  int an = 6, I;
  for (I = 2;; I++) {
    if (sqrt(d * d + 0.25) <= n)
      ans += an;
    else
      break;
    an += 6;
    d += sqrt(3);
  }
  I--;
  d -= sqrt(3) / 2 * 3;
  double x, y;
  x = -d / 2;
  y = d / 2 * sqrt(3);
  x += sqrt(3) / 2;
  y += 1.5;
  I--;
  for (; x <= 1e-9 && I > 0; I--) {
    while (judge(x, y) == 0 && x <= 1e-9) {
      I -= 2;
      x += sqrt(3);
    }
    if (x <= 1e-9) ans += 6 * I;
    x += sqrt(3) / 2;
    y += 1.5;
  }
  printf("%I64d\n", ans);
  return 0;
}
