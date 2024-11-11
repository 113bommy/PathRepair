#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  double x1, x2;
  scanf("%d %d %d", &a, &b, &c);
  d = b * b - 4 * a * c;
  x1 = (-b + sqrt(d)) / (a << 1);
  x2 = -1. * b / a - x1;
  if (x1 < x2) swap(x1, x2);
  printf("%.13lf\n%.13lf", x1, x2);
  return 0;
}
