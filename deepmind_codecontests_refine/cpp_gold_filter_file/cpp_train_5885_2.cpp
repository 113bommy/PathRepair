#include <bits/stdc++.h>
using namespace std;
double a, b, c, th, pi = acos(-1);
double sq(double a) { return a * a; }
double s(double n, double a) {
  return a / 2 / tan(pi / n) * a / 2 * n * 1 / 3 *
         sqrt(sq(a) - sq(a / 2 / sin(pi / n)));
}
int main() {
  cin >> a >> b >> c;
  cout << setprecision(15) << s(3, a) + s(4, b) + s(5, c);
}
