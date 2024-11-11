#include <bits/stdc++.h>
using namespace std;
int main() {
  double r, x1, y1, x2, y2, dx, dy;
  cin >> r >> x1 >> y1 >> x2 >> y2;
  dx = x2 - x1;
  dy = y2 - y1;
  if (x1 == x2 && y1 == y2)
    cout << 0 << endl;
  else
    cout << ceil(sqrt((dx * dx + dy * dy) / (r * r))) - 1 << endl;
}
