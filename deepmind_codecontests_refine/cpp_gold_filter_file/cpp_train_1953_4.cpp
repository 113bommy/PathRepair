#include <bits/stdc++.h>
using namespace std;
int main() {
  long double a, b;
  cin >> a >> b;
  long double x, y;
  x = 1.0 * a * log(1.0 * b);
  y = 1.0 * b * log(1.0 * a);
  if (x > y)
    cout << "<" << endl;
  else if (y > x)
    cout << ">" << endl;
  else
    cout << "=" << endl;
  return 0;
}
