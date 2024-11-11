#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, x1, y1, x2, y2;
  cin >> r >> x1 >> y1 >> x2 >> y2;
  double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
  cout << ceil(d / (2 * r));
  return 0;
}
