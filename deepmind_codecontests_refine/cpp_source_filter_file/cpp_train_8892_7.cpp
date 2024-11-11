#include <bits/stdc++.h>
using namespace std;
long double a, d;
long long n;
long long r;
void enter() {
  scanf("%Lf%Lf", &a, &d);
  scanf("%I64d", &n);
  double tmp = 0.0;
  for (int i = 1; i <= n; i++) {
    tmp = d * i;
    r = floor(tmp / a);
    if (r % 4 == 1)
      printf("%.10lf %.10f\n", a, tmp - r * a);
    else if (r % 4 == 2)
      printf("%.10lf %.10lf\n", a - tmp + r * a, a);
    else if (r % 4 == 3)
      printf("%.10lf %.10lf\n", 0.0, a - tmp + r * a);
    else
      printf("%.10lf %.10lf\n", tmp - r * a, 0.0);
  }
}
int main() {
  enter();
  return 0;
}
