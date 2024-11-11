#include <bits/stdc++.h>
using namespace std;
double s, a, b, c, sum, x, y, z;
int main() {
  scanf("%lf%lf%lf%lf", &s, &a, &b, &c);
  sum = a + b + c;
  if (sum == 0)
    x = y = z = 0;
  else {
    x = a * s / sum;
    y = b * s / sum;
    z = c * s / sum;
  }
  printf("%.6lf %.6lf %.6lf\n", x, y, z);
  return 0;
}
