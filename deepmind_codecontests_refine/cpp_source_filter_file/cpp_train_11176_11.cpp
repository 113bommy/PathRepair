#include <bits/stdc++.h>
using namespace std;
int main() {
  cout << fixed;
  cout.precision(9);
  long a1, b1, c1, a2, b2, c2;
  cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
  if (a1 == 0 && b1 == 0) {
    if (c1 != 0) {
      cout << "0\n";
      return 0;
    }
  }
  if (a2 == 0 && b2 == 0) {
    if (c2 != 0) {
      cout << "0\n";
      return 0;
    }
  }
  if (a1 == 0 && b1 == 0) {
    cout << "-1\n";
    return 0;
  }
  if (a2 == 0 && b2 == 0) {
    cout << "-1\n";
    return 0;
  }
  if (a1 * b2 - a2 * b1 != 0) {
    cout << "1\n";
    return 0;
  }
  if (a1 == a2 && b1 == b2 && c1 == c2) {
    cout << "-1\n";
    return 0;
  }
  if (a1 * c2 == a2 * c1 && b1 * c2 == b2 * c1) {
    cout << "wrong\n";
    return 0;
  }
  cout << "0\n";
  return 0;
}
