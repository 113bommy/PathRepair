#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:32777216")
using namespace std;
int n, rr, v;
double x, y;
double bp(double l, double r) {
  for (int i = 0; i < 100; i++) {
    double x = (l + r) / 2;
    if (2 * rr * x + rr * cos(acos(-1.0) / 2 - x) -
            rr * cos(acos(-1.0) / 2 + x) >
        y)
      r = x;
    else
      l = x;
  }
  return r;
}
int main() {
  cin >> n >> rr >> v;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    y -= x;
    double z = (int)((y + .0) / (2.0 * acos(-1.0) * rr));
    y -= 2 * z * acos(-1.0) * rr;
    printf("%.9lf",
           z * (2.0 * acos(-1.0) * rr) / v + 2 * rr * bp(0, acos(-1.0)) / v);
  }
  return 0;
}
