#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  long double d = sqrt(b * b - 4 * a * c);
  long double x1 = (-b - d) / (2 * a);
  long double x2 = (-b + d) / (2 * a);
  if (x1 > x2)
    cout << fixed << showpoint << setprecision(18) << x1 << '\n' << x2;
  else
    cout << fixed << showpoint << setprecision(18) << x2 << '\n' << x1;
  return 0;
}
