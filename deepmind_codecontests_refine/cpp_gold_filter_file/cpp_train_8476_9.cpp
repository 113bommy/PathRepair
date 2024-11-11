#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-5;
bool check(int a, int b, double x) {
  double s = a * b / 2.0, c = sqrt(a * a / 4.0 + b * b);
  return (fabs((x * c) - (s)) < eps);
}
void solve(double x) {
  int l = (int)ceil(x * 2.0), r = (int)ceil(x), i, j;
  for (i = l; i < 11; ++i) {
    for (j = r; j < 11; ++j) {
      if (check(i, j, x)) {
        printf("%d %d\n", i, j);
        return;
      }
    }
  }
}
int main() {
  double x;
  while (~scanf("%lf", &x)) {
    solve(x);
  }
  return 0;
}
