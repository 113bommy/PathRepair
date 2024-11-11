#include <bits/stdc++.h>
using namespace std;
int main() {
  int x1, x2, y1, y2, c = 0, f = 2;
  cin >> x1 >> y1 >> x2 >> y2;
  while (1) {
    if (x1 == 0 && y1 == 0) {
      f = 0;
      break;
    }
    if (x2 == 0 && y2 == 0) {
      f = 1;
      break;
    }
    if (c & 1) {
      if (x2 > 0 && y2 > 0 && !(x1 + 1 == x2 && y1 + 1 == y2))
        x2--, y2--;
      else {
        if (x2 + y2 <= x1 + y1)
          f = 1;
        else
          f = 0;
        break;
      }
    } else {
      if (x1 == 0)
        y1--;
      else if (y1 == 0)
        x1--;
      else if (x1 <= x2 && y1 >= y2)
        y1--;
      else if (x1 >= x2 && y1 <= y2)
        x1--;
      else if (x1 <= x2 && y1 <= y2) {
        if (y2 - y1 <= x2 - x1)
          y1--;
        else
          x1--;
      } else {
        f = 0;
        break;
      }
    }
    c++;
  }
  if (f)
    cout << "Vasiliy\n";
  else
    cout << "Polycarp\n";
  return 0;
}
