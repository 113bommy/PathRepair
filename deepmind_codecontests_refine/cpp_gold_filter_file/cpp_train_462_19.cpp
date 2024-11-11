#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, x1, y1, x2, y2, b;
  double dist, a;
  cin >> r >> x1 >> y1 >> x2 >> y2;
  dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
  a = (dist / (float)(2 * r));
  b = (int)a;
  if (b == a)
    cout << b << endl;
  else
    cout << b + 1 << endl;
  return 0;
}
