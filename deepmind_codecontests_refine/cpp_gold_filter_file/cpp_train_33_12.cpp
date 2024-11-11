#include <bits/stdc++.h>
using namespace std;
int main() {
  float a, b, c, zero = 0, count = 0;
  cin >> a >> b >> c;
  if (a != 0) {
    float z = (b * b) - (4 * a * c);
    if (z > -1) {
      if (b == 0 && c == 0) {
        cout << 1 << endl << setprecision(10) << fixed << 0 << endl;
        return 0;
      } else if (c == 0) {
        cout << 2 << endl;
        cout << setprecision(10) << fixed << min(-b / a, zero) << endl
             << max(-b / a, -zero) << endl;
        return 0;
      } else if (z == 0) {
        cout << 1 << endl << setprecision(10) << fixed << -b / (2 * a) << endl;
        return 0;
      } else {
        cout << 2 << endl
             << setprecision(10) << fixed
             << min(((-b - sqrt(z)) / (2 * a)), ((-b + sqrt(z)) / (2 * a)))
             << endl
             << setprecision(10) << fixed
             << max(((-b - sqrt(z)) / (2 * a)), ((-b + sqrt(z)) / (2 * a)))
             << endl;
        return 0;
      }
    } else {
      cout << 0 << endl;
      return 0;
    }
  } else if (b != 0) {
    cout << 1 << endl << setprecision(10) << fixed << -c / b << endl;
    return 0;
  } else if (c != 0) {
    cout << 0 << endl;
    return 0;
  }
  cout << -1 << endl;
  return 0;
}
