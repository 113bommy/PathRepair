#include <bits/stdc++.h>
using namespace std;
long double dist(long double x1, long double y1, long double x2,
                 long double y2) {
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
long double area(long double a, long double b, long double c) {
  long double s = (a + b + c) / 2;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}
long double solve(long double x1, long double y1, long double x2,
                  long double y2, long double x3, long double y3) {
  return (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
  long double a = dist(x1, y1, x2, y2);
  long double b = dist(x1, y1, x3, y3);
  long double c = dist(x3, y3, x2, y2);
  return area(a, b, c);
}
int main() {
  int n, d;
  cin >> n >> d;
  long double area =
      solve(0, d, d, 0, n, n - d) + solve(d, 0, n, n - d, n - d, n);
  int m;
  cin >> m;
  while (m--) {
    long double x, y;
    cin >> x >> y;
    long double a = solve(x, y, 0, d, d, 0);
    a += solve(x, y, d, 0, n, n - d);
    a += solve(x, y, n, n - d, n - d, n);
    a += solve(x, y, n - d, n, 0, d);
    if (abs(a - area) <= 1e-10)
      cout << "YES\n";
    else
      cout << "NO" << endl;
  }
}
