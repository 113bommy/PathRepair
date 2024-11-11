#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  if (a != 0 && b != 0 && c != 0) {
    long long d = b * b - 4 * a * c;
    if (d < 0) {
      cout << 0;
      return 0;
    }
    long double r = sqrt(d), one = 1.0 * (-b - r) / (2 * a),
                two = 1.0 * (-b + r) / (2 * a);
    if (d == 0) {
      cout << fixed << setprecision(7) << "1\n" << one;
      return 0;
    }
    if (one < two) {
      cout << fixed << setprecision(7) << "2\n" << one << "\n" << two << "\n";
    } else {
      cout << fixed << setprecision(7) << "2\n" << two << "\n" << one << "\n";
    }
    return 0;
  }
  if (a == 0 && b != 0 && c != 0) {
    long double one = 1.0 * (-c) / b;
    cout << fixed << setprecision(7) << "1\n" << one;
    return 0;
  }
  if (a != 0 && b == 0 && c != 0) {
    if (c < 0) {
      cout << 0;
      return 0;
    }
    long double one = sqrt((c / a)), two = -one;
    if (one < two) {
      cout << fixed << setprecision(7) << "2\n" << one << "\n" << two;
    } else {
      cout << fixed << setprecision(7) << "2\n" << two << "\n" << one;
    }
    return 0;
  }
  if (a != 0 && b != 0 && c == 0) {
    long double one = 0.0, two = 1.0 * (-b) / a;
    if (one < two) {
      cout << fixed << setprecision(7) << "2\n" << one << "\n" << two;
    } else {
      cout << fixed << setprecision(7) << "2\n" << two << "\n" << one;
    }
    return 0;
  }
  if (a == 0 && b == 0 && c != 0) {
    cout << 0;
    return 0;
  }
  if (a == 0 && b != 0 && c == 0) {
    cout << fixed << setprecision(7) << "1\n" << 0.000000000;
    return 0;
  }
  if (a != 0 && b == 0 && c == 0) {
    cout << fixed << setprecision(7) << "1\n" << 0.00000000;
    return 0;
  }
  if (a == 0 && b == 0 && c == 0) {
    cout << "-1";
    return 0;
  }
  return 0;
}
