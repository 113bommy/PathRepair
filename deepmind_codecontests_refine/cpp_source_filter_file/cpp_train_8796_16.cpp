#include <bits/stdc++.h>
using namespace std;
int n, r, v;
double c;
double solve(double z) {
  double l = 0, u = 8 * atan(1), m = 0.0000000000001;
  while (u - l > m) {
    double x = (l + u) / 2;
    if (x + 2 * sin(x / 2) > z)
      u = x;
    else
      l = x;
  }
  return (l + u) / 2;
}
int main() {
  scanf("%d%d%d", &n, &r, &v);
  c = 8 * atan(1) * r;
  cout << fixed << setprecision(10);
  for (int i = 0; i < n; i++) {
    int s, f;
    double ans = 0, dist;
    scanf("%d%d", &s, &f);
    dist = f - s - (int((f - s) / c)) * c;
    cout << (f - s - 2 * r * sin(solve(dist / r) / 2)) / v << endl;
  }
}
