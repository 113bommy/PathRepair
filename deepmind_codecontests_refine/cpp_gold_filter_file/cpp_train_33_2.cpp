#include <bits/stdc++.h>
using namespace std;
int main() {
  double a, b, c;
  double x, y, d, p;
  cin >> a >> b >> c;
  d = b * b;
  p = 4 * a * c;
  d = d - p;
  if (a == 0 && b == 0 && c == 0)
    cout << "-1" << endl;
  else if (a == 0 && b == 0)
    cout << "0" << endl;
  else if (a == 0) {
    x = c * -1;
    x = x / b;
    printf("1\n%.5lf\n", x);
  } else if (d > 0) {
    p = sqrt(d);
    b = b * -1;
    x = (b + p);
    x = x / 2.0;
    x = x / a;
    y = (b - p);
    y = y / 2.0;
    y = y / a;
    if (x > y)
      printf("2\n%.7lf\n%.7lf\n", y, x);
    else
      printf("2\n%.7lf\n%.7lf\n", x, y);
  } else if (d < 0)
    cout << "0" << endl;
  else if (d == 0) {
    b = b * -1;
    x = b / 2.0;
    x = x / a;
    printf("1\n%.7lf\n", x);
  }
  return 0;
}
