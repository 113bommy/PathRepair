#include <bits/stdc++.h>
using namespace std;
int main(void) {
  long double a, b, c, p, q, r;
  cin >> a >> b >> c;
  p = b * b - 4 * a * c;
  if (a == 0 && b == 0 && c == 0)
    cout << -1 << endl;
  else if (a == 0 && b == 0 && c != 0)
    cout << 0 << endl;
  else if (p < 0)
    cout << 0 << endl;
  else if (a == 0) {
    q = -c / b;
    cout << 1 << endl;
    cout << fixed << setprecision(6) << q;
  } else if (p == 0) {
    q = -b / (2 * a);
    cout << 1 << endl;
    cout << fixed << setprecision(6) << q;
  } else {
    q = (-b - sqrt(p)) / (2 * a);
    r = (-b + sqrt(p)) / (2 * a);
    if (q < r) {
      cout << 2 << '\n' << fixed << setprecision(6) << q << endl;
      cout << fixed << setprecision(6) << r << endl;
    } else {
      cout << 2 << '\n' << fixed << setprecision(6) << r << endl;
      cout << fixed << setprecision(6) << q << endl;
    }
  }
  return 0;
}
