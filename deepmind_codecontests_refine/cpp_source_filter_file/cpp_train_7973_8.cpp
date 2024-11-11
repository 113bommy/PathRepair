#include <bits/stdc++.h>
using namespace std;
int t, n;
double F(double x) { return n - x + min(n - x, x * (x - 1) / 2.0); }
int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    double l = 1, r = n;
    double res = 0;
    while (r - l > 0.1) {
      double m1 = (r - l) / 3.0;
      double m2 = r - m1;
      m1 += l;
      if (F(m1) >= F(m2))
        r = m2;
      else
        l = m1;
    }
    l = (int)(l + r) / 2.0;
    printf("%.0lf\n", max(F(l), F(l + 1)));
  }
  return 0;
}
