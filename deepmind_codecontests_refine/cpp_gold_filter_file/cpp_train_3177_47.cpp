#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, x, y, z, l = 0, o = 0, r = 0;
  cin >> a >> b >> c >> x >> y >> z;
  l = (x > a) ? l + (x - a) : l;
  l = (y > b) ? l + (y - b) : l;
  l = (z > c) ? l + (z - c) : l;
  if (a > x) {
    o += (a - x) / 2;
  }
  if (b > y) {
    o += (b - y) / 2;
  }
  if (c > z) {
    o += (c - z) / 2;
  }
  if (o >= l)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
