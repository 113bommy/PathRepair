#include <bits/stdc++.h>
using namespace std;
int main() {
  double r, x1, y1, x2, y2;
  cin >> r >> x1 >> y1 >> x2 >> y2;
  double z = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
  cout << ceil(z / (2 * r));
  return 0;
}
