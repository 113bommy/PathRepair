#include <bits/stdc++.h>
using namespace std;
int main() {
  double a, b, c, x1, x2, deta;
  while (scanf("%lf %lf %lf", &a, &b, &c) != EOF) {
    deta = b * b - 4 * a * c;
    x1 = (-b + sqrt(deta)) / (a * 2);
    x2 = (-b - sqrt(deta)) / (a * 2);
    if (x1 < x2) swap(x1, x2);
    printf("%.8lf\n", x1);
    printf("%.8lf\n", x2);
  }
  return 0;
}
