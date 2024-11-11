#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int n, r;
const double MYPI = acos(-1);
void run() {
  scanf("%d%d", &n, &r);
  double a = 2 * MYPI / n;
  double b = a / 4;
  double c = MYPI / 2 - a * 3 / 4;
  double d = a / 4;
  double x = r * sin(a / 2);
  double y = x * tan(c);
  double Y = x * tan(b + c);
  printf("%.12lf\n", 1.0 * n * r * r * sin(2 * d) * sin(2 * d) *
                         (cos(2 * d) / sin(2 * d) - cos(3 * d) / sin(3 * d)));
}
int main() {
  run();
  return 0;
}
