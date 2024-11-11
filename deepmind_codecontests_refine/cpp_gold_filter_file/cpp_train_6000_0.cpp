#include <bits/stdc++.h>
using namespace std;
int main() {
  int x1, y1, x2, y2;
  int r, r1;
  cin >> x1 >> y1 >> x2 >> y2;
  if (x1 == x2) {
    r = abs(y2 - y1) + 1;
    cout << r * 2 + 4;
    return 0;
  }
  if (y1 == y2) {
    r = abs(x2 - x1) + 1;
    cout << r * 2 + 4;
    return 0;
  }
  r = abs(x2 - x1) + 1;
  r1 = abs(y2 - y1) + 1;
  cout << r * 2 + r1 * 2;
}
