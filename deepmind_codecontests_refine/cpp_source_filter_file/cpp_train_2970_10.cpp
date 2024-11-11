#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
int main() {
  double n;
  double r;
  cin >> n >> r;
  double t1 = tan(PI / n), t2 = tan(PI / (n * 2));
  double h = r * t2 * t1 / (t1 + t2);
  double s1 = h * r * n;
  printf("%lf\n", s1);
  return 0;
}
