#include <bits/stdc++.h>
using namespace std;
int main() {
  double s, a, b, c;
  while (scanf("%lf%lf%lf%lf", &s, &a, &b, &c) != EOF) {
    if (a < 1e-10 && b < 1e-10 && c < 1e-10) {
      printf("%lf %lf %lf\n", s, 0, 0);
    } else {
      double ans1 = a * s / (a + b + c), ans2 = b * s / (a + b + c),
             ans3 = c * s / (a + b + c);
      printf("%lf %lf %lf\n", ans1, ans2, ans3);
    }
  }
}
