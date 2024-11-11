#include <bits/stdc++.h>
using namespace std;
int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  if (x1 < x2 && y1 > y2)
    cout << 2 * (y1 - y2 + x2 - x1) + 4;
  else if (x1 > x2 && y1 < y2)
    cout << 2 * (y2 - y1 + x1 - x2) + 4;
  else if (x1 == x2 && y1 < y2)
    cout << 2 * (2 + y2 - y1 + 1);
  else if (x1 == x2 && y1 > y2)
    cout << 2 * (2 + y1 - y2 + 1);
  else if (y1 == y2 && x1 < x2)
    cout << 2 * (2 + x2 - x1 + 1);
  else if (y1 == y2 && x1 > x2)
    cout << 2 * (2 + x1 - x2 + 1);
  else if (x1 > x2 && y1 > y2)
    cout << 2 * (x1 - x2 + y1 - y2) + 4;
  else if (x1 < x2 && y1 < y2)
    cout << 2 * (x2 - x1 + y2 - y1) + 4;
  return 0;
}
