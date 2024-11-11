#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, x, y, xx, yy;
  cin >> r >> x >> y >> xx >> yy;
  double dis = sqrt(pow((xx - x), 2) + pow((yy - y), 2));
  dis /= 2.0 * r;
  int t = (int)dis;
  if (dis - t > 0) t++;
  cout << t;
}
