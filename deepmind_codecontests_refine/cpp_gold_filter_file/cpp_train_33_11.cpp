#include <bits/stdc++.h>
using namespace std;
const int MAX1 = 0x7f7f7f7f;
const int MAX = 1e5 + 10;
double exgcd(long long l, long long r, double &x, double &y) {
  if (r == 0) {
    x = 1;
    y = 0;
    return l;
  } else {
    double d = exgcd(r, l % r, y, x);
    y -= l / r * x;
    return d;
  }
}
int main() {
  int n, m;
  int i, j, k;
  int ans;
  double a, b, c, res1, res2;
  double num[20];
  memset(num, 0, sizeof(num));
  scanf("%lf%lf%lf", &a, &b, &c);
  double flag = b * b - 4 * (a * c);
  if (a == 0 && c == 0 && b == 0)
    printf("-1\n");
  else if (a == 0 && b != 0) {
    ans = 1;
    res1 = (-c) * 1.0 / b;
    printf("%d\n%.10lf\n", ans, res1);
  } else if (a == 0 && b == 0 && c != 0)
    printf("0\n");
  else {
    if (b * b - 4 * (a * c) < 0) {
      printf("0\n");
    } else if (b * b - 4 * (a * c) == 0) {
      ans = 1;
      res1 = -b / (2 * a);
      printf("%d\n%.10lf\n", ans, res1);
    } else {
      ans = 2;
      res1 = (-b - sqrt(flag * 1.0)) / (2 * a);
      res2 = (-b + sqrt(flag * 1.0)) / (2 * a);
      if (res1 > res2) {
        flag = res1;
        res1 = res2;
        res2 = flag;
      }
      printf("%d\n%.10lf\n%.10lf\n", ans, res1, res2);
    }
  }
  return 0;
}
