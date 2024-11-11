#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 55;
const double eps = 1e-12;
char s[MAXN];
int main() {
  int t;
  scanf("%d", &t);
  double a, b, d;
  while (t--) {
    scanf("%lf", &d);
    if (d * d - 4 * d < -eps || d - sqrt(d * d - 4 * d) < -eps) {
      printf("N\n");
      continue;
    }
    a = (d + sqrt(d * d - 4 * d)) / 2;
    b = (d - sqrt(d * d - 4 * d)) / 2;
    b += eps;
    printf("Y %.9lf %.9lf\n", a, b);
  }
}
