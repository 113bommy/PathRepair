#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, f, k, i, y, ch = 0;
  cin >> a >> b >> f >> k;
  y = b - f;
  if (b < 2 * f && k != 1 && k != 2 || b < 2 * (a - f) && k != 1 || b < f ||
      b < a - f)
    cout << -1;
  else {
    for (i = 2; i <= k + 1; i++) {
      if (i == k + 1) {
        if (i % 2 == 0) {
          if (y < a - f) ch++;
        } else {
          if (y < f) ch++;
        }
      } else if (i % 2 == 0) {
        if (y < 2 * (a - f)) {
          ch++;
          y = b;
        }
        y = y - 2 * (a - f);
      } else {
        if (y < 2 * f) {
          ch++;
          y = b;
        }
        y = y - 2 * f;
      }
    }
    cout << ch;
  }
  return 0;
}
