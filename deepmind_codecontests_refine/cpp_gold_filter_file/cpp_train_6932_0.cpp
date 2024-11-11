#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
void answer(long long int x, long long int y) { cout << x << " " << y << endl; }
lint gcd(lint a, lint b, lint& x, lint& y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  lint x1, y1;
  lint d = gcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
bool find_any_solution(lint a, lint b, lint c, lint& x0, lint& y0, lint& g) {
  g = gcd(abs(a), abs(b), x0, y0);
  if (c % g != 0) return false;
  x0 *= c / g;
  y0 *= c / g;
  if (a > 0) x0 *= -1;
  if (b > 0) y0 *= -1;
  return true;
}
int main() {
  using ldouble = long double;
  lint a, b, c, x0, y0, g;
  ldouble y, k, l, y_max;
  cin >> a >> b >> c;
  if (find_any_solution(a, b, c, x0, y0, g)) {
    answer(x0, y0);
    return 0;
  }
  cout << -1;
  return 0;
}
