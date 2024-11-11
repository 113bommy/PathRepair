#include <bits/stdc++.h>
using namespace std;
double x;
int main() {
  double a, h;
  scanf("%lf", &x);
  for (a = 1; a <= 10; a++) {
    for (h = 1; h <= 10; h++) {
      if ((fabs((((a * h / 2) / sqrt((a / 2) * (a / 2) + h * h))) - (x)) <=
           0.00001)) {
        printf("%d %d\n", a, h);
        return 0;
      }
    }
  }
  return 0;
}
