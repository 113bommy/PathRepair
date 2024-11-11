#include <bits/stdc++.h>
using namespace std;
double pow2(double a, int b) {
  double r = 1, base = a;
  while (b != 0) {
    if (b % 2) r *= base;
    base *= base;
    b /= 2;
  }
  return r;
}
int main() {
  double m;
  int n;
  cin >> m >> n;
  double ans;
  if (n <= 100000) {
    ans = m;
    for (int i = 1; i <= m - 1; ++i) {
      ans -= pow2(i / m, n);
    }
  } else {
    ans = m;
  }
  printf("%.4lf\n", ans);
  return 0;
}
