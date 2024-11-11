#include <bits/stdc++.h>
using namespace std;
char str[10050];
int main() {
  int i, j, n, m, k;
  double a, b, c, d, t1, t2;
  scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
  t1 = a / b;
  t2 = c / d;
  double t = (1 - t1) * (1 - t2), sum = t1;
  double ans = t;
  while (t1 * ans > 1e-7) {
    sum += t1 * ans;
    ans *= t;
  }
  printf("%lf", sum);
  return 0;
}
