#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x1, x2, x3, x31, x4, x41, y1, y2, y3, y31, y4, y41;
  long long side = 0;
  cin >> x1 >> y1 >> x2 >> y2;
  if (x1 == x2) {
    side = abs(y2 - y1);
    x3 = x1 + side;
    x31 = x1 - side;
    x4 = x2 + side;
    x41 = x2 - side;
    y3 = y1;
    y4 = y2;
  }
  if (y1 == y2) {
    side = abs(y1 - y2);
    y3 = y1 + side;
    y31 = y1 - side;
    y4 = y2 + side;
    y41 = y2 - side;
    x3 = x1;
    x4 = x2;
  }
  if (abs(x1 - x2) == abs(y1 - y2)) {
    x3 = x1;
    y3 = y2;
    x4 = x2;
    y4 = y1;
  }
  if (x3 <= 1000 && x3 >= -1000 && y3 <= 1000 && y3 >= -1000 && x4 <= 1000 &&
      x4 >= -1000 && y4 <= 1000 && y4 >= -1000) {
    cout << x3 << " " << y3 << " " << x4 << " " << y4;
    return 0;
  }
  if (x31 <= 1000 && x31 >= -1000 && y31 <= 1000 && y31 >= -1000 &&
      x41 <= 1000 && x41 >= -1000 && y41 <= 1000 && y41 >= -1000) {
    cout << x31 << " " << y31 << " " << x41 << " " << y41;
    return 0;
  } else
    cout << -1;
}
