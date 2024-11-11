#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int main() {
  int T;
  scanf("%d", &T);
  for (; T--;) {
    double d;
    scanf("%lf", &d);
    double o = d * d - 4.0 * d;
    if (o < 0) {
      printf("N\n");
      continue;
    }
    printf("Y ");
    if (o == 0) {
      double ans = (d + sqrt(o)) / 2.0;
      printf("%lf %lf\n", ans, ans);
    } else {
      double a = (d + sqrt(o)) / 2.0;
      double b = (d - sqrt(o)) / 2.0;
      printf("%lf %lf\n", a, b);
    }
  }
  return 0;
}
