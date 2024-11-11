#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int y, x, n, i, f = 0, len = 1000000000000, x1, y1;
  cin >> n;
  for (y = 1; y < 1000000; y++) {
    x = (n - 7 * y) / 4;
    if (4 * x + 7 * y == n && x >= 0) {
      f = 1;
      if (x + y < len) {
        len = x + y;
        x1 = x;
        y1 = y;
      }
    }
  }
  if (!f)
    cout << "-1";
  else {
    for (i = 1; i <= x1; i++) cout << "4";
    for (i = 1; i <= y1; i++) cout << "7";
  }
}
