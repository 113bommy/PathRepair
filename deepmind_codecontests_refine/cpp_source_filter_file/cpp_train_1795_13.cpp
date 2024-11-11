#include <bits/stdc++.h>
using namespace std;
double x[15], tmp;
int main() {
  for (int i = 1; i <= 11; ++i) scanf("%lf", &x[i]);
  for (int i = 11; i >= 1; --i) {
    tmp = 5.0 * x[i] * x[i] * x[i] + sqrt(abs(x[i]));
    if (tmp <= 400)
      printf("f(%lf) = %.2lf\n", x[i], tmp);
    else
      printf("f(%lf) = MAGNA NIMIS!\n", x[i]);
  }
  return 0;
}
