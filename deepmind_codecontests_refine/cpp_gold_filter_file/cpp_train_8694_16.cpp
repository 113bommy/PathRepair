#include <bits/stdc++.h>
using namespace std;
;
const int maxn = 1e5 + 10;
double a, b, c;
int main() {
  scanf("%lf %lf %lf", &a, &b, &c);
  double d = sqrt(b * b - 4 * a * c);
  double x1 = (-b + d) / 2 / a;
  double x2 = (-b - d) / 2 / a;
  if (x1 >= x2)
    printf("%.10f\n%.10f", x1, x2);
  else
    printf("%.10f\n%.10f", x2, x1);
}
