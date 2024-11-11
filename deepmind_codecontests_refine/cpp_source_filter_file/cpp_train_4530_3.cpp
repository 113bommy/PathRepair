#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
double eps = 1e-9;
const double pi = acos(-1);
int r, v;
double gettime(double len, double al) {
  double q = r * cos(al);
  double head = 0, tail = (double)(len + r * 2) / v;
  for (int j = 0; j <= 40; ++j) {
    double mid = (head + tail) / 2;
    if ((mid * v - q + r * cos(al - mid * v / r)) < len)
      head = mid;
    else
      tail = mid;
  }
  return head;
}
int main() {
  int n;
  scanf("%d%d%d", &n, &r, &v);
  for (int i = 1; i <= n; ++i) {
    int s, t;
    scanf("%d%d", &s, &t);
    double ans = min(2 * gettime((double)(t - s) / 2, pi / 2),
                     2 * gettime((double)(t - s) / 2, -pi / 2));
    printf("%.15f\n", ans);
  }
}
