#include <bits/stdc++.h>
using namespace std;
int main() {
  int no = 0;
  double a, b, c, res, res1, res2, d, p, q;
  scanf("%lf%lf%lf", &a, &b, &c);
  if (a == 0 && b == 0 && c == 0) {
    cout << "-1" << endl;
    return 0;
  }
  if (a == 0 && b != 0) {
    res = -(c / b);
    printf("1\n%lf", res);
    return 0;
  }
  if (a == 0 && b == 0) no = 1;
  d = b * b - 4 * a * c;
  if (d < 0) no = 1;
  if (!no) {
    p = -b + sqrt(d);
    q = -b - sqrt(d);
    res1 = p / (2 * a);
    res2 = q / (2 * a);
    if (res1 == res2) {
      printf("1\n%lf", res1);
    } else {
      double x = min(res1, res2);
      double y = max(res1, res2);
      printf("2\n%lf\n%lf", x, y);
    }
    return 0;
  }
  printf("0");
  return 0;
}
