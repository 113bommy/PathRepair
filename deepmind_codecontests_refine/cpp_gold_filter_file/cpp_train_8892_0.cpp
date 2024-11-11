#include <bits/stdc++.h>
using namespace std;
int main() {
  double a, d;
  int n;
  scanf("%lf%lf%d", &a, &d, &n);
  double tot = 0;
  for (int i = 1; i <= n; i++) {
    tot = d * i;
    long long q = tot / (4 * a);
    tot -= q * (4 * a);
    double o = 0;
    if (tot < a) {
      printf("%.5lf %.5lf\n", tot, o);
    } else if (tot < 2 * a) {
      printf("%.5lf %.5lf\n", a, tot - a);
    } else if (tot < 3 * a) {
      printf("%.5lf %.5lf\n", 3 * a - tot, a);
    } else {
      printf("%.5lf %.5lf\n", o, 4 * a - tot);
    }
  }
  return 0;
}
