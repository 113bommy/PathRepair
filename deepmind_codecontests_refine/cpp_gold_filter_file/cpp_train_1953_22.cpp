#include <bits/stdc++.h>
using namespace std;
double x, y;
const double eps = 1e-10;
int main() {
  scanf("%lf%lf", &x, &y);
  if (x == 1) {
    if (y > 1)
      puts("<");
    else
      puts("=");
  } else if (fabs((y / x) - (log(y) / log(x))) < eps)
    puts("=");
  else if ((y / x) - (log(y) / log(x)) < 0)
    puts("<");
  else
    puts(">");
  return 0;
}
