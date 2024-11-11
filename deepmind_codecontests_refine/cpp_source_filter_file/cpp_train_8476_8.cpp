#include <bits/stdc++.h>
using namespace std;
double r;
int main() {
  scanf("%lf", &r);
  for (int a = 1; a <= 10; a++)
    for (int h = 1; h <= 10; h++) {
      double l = 4 * r * r / (a * a);
      double p = h * h / (double)(h * h + a * a / 4.0);
      if (l <= p + 0.000001 && l >= p - 0.000001) {
        printf("%d %d\n", a, h);
        return 0;
      }
    }
  return 0;
}
