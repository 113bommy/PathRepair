#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d;
    int x, y, x1, y1, x2, y2;
    cin >> a >> b >> c >> d;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    int flag = 1;
    if (a > b) {
      if ((x - x1) < (a - b)) flag = 0;
    } else if (b > a) {
      if ((x2 - x) < (b - a)) flag = 0;
    } else {
      if (x2 - x == 0 && x - x1 == 0 && a != 0) flag = 0;
    }
    if (c > d) {
      if ((y - y1) < (c - d)) flag = 0;
    } else if (d > c) {
      if ((y2 - y) < (d - c)) flag = 0;
    } else {
      if (y2 - y == 0 && y - y1 == 0 && c != 0) flag = 0;
    }
    if (flag) {
      cout << "YES" << endl;
    } else
      cout << "NO" << endl;
  }
  return 0;
}
