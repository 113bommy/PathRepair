#include <bits/stdc++.h>
using namespace std;
double a, d, n, b;
void f(double x, double y) {
  if (x <= y)
    cout << setprecision(8) << x << ' ' << 0 << endl;
  else if (x <= 2 * y)
    cout << setprecision(8) << y << ' ' << x - y << endl;
  else if (x <= 3 * y)
    cout << setprecision(8) << y - (x - 2 * a) << ' ' << y << endl;
  else
    cout << setprecision(8) << 0 << ' ' << y - (x - 3 * a) << endl;
}
int main() {
  cin >> a >> d >> n;
  while (d >= 4 * a) d -= 4 * a;
  for (int i = 1; i <= n; i++) {
    b += d;
    while (b >= 4 * a) b -= 4 * a;
    f(b, a);
  }
  return 0;
}
