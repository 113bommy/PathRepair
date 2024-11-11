#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, x1, y1, x2, y2, d;
  double n;
  cin >> r;
  cin >> x1;
  cin >> y1;
  cin >> x2;
  cin >> y2;
  d = hypot(x2 - x1, y2 - y1);
  n = d / (2 * r);
  cout << ceil(n);
}
