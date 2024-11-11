#include <bits/stdc++.h>
using namespace std;
int main() {
  bool tmp = 0;
  double a, b, c, d, e, f, sum;
  scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &d, &e, &f);
  if (b * d * f / a / c / e > 1.0)
    printf("Ron\n");
  else if (c == 0 && d != 0)
    printf("Ron\n");
  else if (a == 0 && b != 0 && d != 0)
    printf("Ron\n");
  else
    printf("Hermione\n");
  return 0;
}
