#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int r, x, y, x2, y2;
  cin >> r >> x >> y >> x2 >> y2;
  if (x == x2 && y == y2) {
    cout << 0;
    return 0;
  }
  double d = sqrt(pow(y2 - y, 2) + pow(x2 - x, 2));
  cout << (int)ceil(d / (2 * r));
}
