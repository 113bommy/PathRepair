#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, x, y, z;
  cin >> a >> b >> c >> x >> y >> z;
  int free = 0, need = 0;
  if (a > x) {
    free += (a - x) / 2;
  } else {
    need += (x - a);
  }
  if (b > y) {
    free += (b - y) / 2;
  } else {
    need += (y - b);
  }
  if (c > z) {
    free += (c - z) / 2;
  } else {
    need += (z - c);
  }
  if (free >= need)
    cout << "Yes\n";
  else
    cout << "No\n";
  return 0;
}
