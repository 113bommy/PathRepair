#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, xx, yy;
bool F(int x1, int y1, int x2, int y2) {
  if (abs(x1 - x2) <= 2)
    if (abs(y1 - y2) <= 4) return true;
  if (abs(x1 - x2) <= 3)
    if (abs(y1 - y2) <= 3) return true;
  return false;
}
int main() {
  cin >> n >> m >> x >> y >> xx >> yy;
  x--;
  y--;
  xx--;
  yy--;
  if (F(x, y, xx, yy) || F(xx, yy, x, y))
    cout << "First" << endl;
  else
    cout << "Second" << endl;
  return 0;
}
