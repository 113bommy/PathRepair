#include <bits/stdc++.h>
using namespace std;
int main() {
  long long r, x1, y1, x2, y2;
  cin >> r >> x1 >> y1 >> x2 >> y2;
  double dist = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
  long long steps = (dist / (2.0 * r));
  dist = dist - steps * 2 * r;
  if (dist == 0) {
    cout << steps << endl;
  } else {
    cout << steps + 1 << endl;
  }
}
