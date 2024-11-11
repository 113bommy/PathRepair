#include <bits/stdc++.h>
using namespace std;
signed main() {
  int w = 1;
  cin >> w;
  while (w--) {
    int x, y, z, m = 0, o = 0, x1 = 1, p = 0, y1 = 1, countt = 0;
    cin >> x >> y >> z;
    while (m <= z + 1) {
      if (x > y) {
        y += x;
      } else
        x += y;
      countt++;
      m = max(x, y);
    }
    cout << countt << endl;
  }
}
