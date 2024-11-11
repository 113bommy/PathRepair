#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, numberOfRoots, temp;
  double r1, r2;
  cin >> a >> b >> c;
  if (a == 0 && b == 0 && c == 0) {
    cout << -1 << endl;
    return 0;
  } else if (a == 0 && b == 0) {
    cout << 0 << endl;
    return 0;
  } else if (a == 0) {
    r1 = -c / b;
    cout << 1 << endl << fixed << setprecision(5) << r1 << endl;
    return 0;
  }
  temp = b * b - 4 * a * c;
  if (temp == 0)
    numberOfRoots = 1;
  else if (temp > 0)
    numberOfRoots = 2;
  else if (temp < 0) {
    cout << 0 << endl;
    return 0;
  }
  r1 = (-b + sqrt(temp)) / (2 * a);
  r2 = (-b - sqrt(temp)) / (2 * a);
  if (r1 > r2)
    cout << numberOfRoots << endl
         << fixed << setprecision(5) << r2 << endl
         << fixed << setprecision(5) << r1 << endl;
  else if (r1 < r2)
    cout << numberOfRoots << endl
         << fixed << setprecision(5) << r1 << endl
         << fixed << setprecision(5) << r2 << endl;
  else
    cout << numberOfRoots << endl << fixed << setprecision(5) << r2 << endl;
  return 0;
}
