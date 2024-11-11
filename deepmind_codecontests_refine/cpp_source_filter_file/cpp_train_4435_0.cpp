#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, h;
  cin >> n >> h;
  double A, B;
  A = 0;
  B = h;
  double ss = h / 2;
  for (int i = 0; i < n - 1; i++) {
    double l = A;
    double r = B;
    for (int it = 0; it < 300; it++) {
      double mid = (l + r) / 2;
      double s = (A + mid) / 2 / h * (mid - A);
      if (s > ss / n)
        r = mid;
      else
        l = mid;
    }
    l = (l + r) / 2;
    printf("%.10lf\n", l);
    A = l;
  }
  return 0;
}
