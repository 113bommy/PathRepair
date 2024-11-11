#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a1, b1, a2, b2, x1, x2;
  cin >> n >> a1 >> b1 >> a2 >> b2;
  if (((a1 == 2 || b1 == 0) && (a2 == 2 || b2 == 0)) ||
      ((a1 == 0 || b1 == 2) && (a2 == 0 || b2 == 2))) {
    x1 = abs(a1 + b1 - a2 - b2);
  } else {
    x1 = a1 + b1 + a2 + b2;
  }
  x2 = 4 * n - x1;
  (x1 > x2) ? cout << x2 : cout << x1;
  return 0;
}
