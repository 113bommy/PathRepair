#include <bits/stdc++.h>
using namespace std;
int x, y, z, r;
int main() {
  cin >> x >> y;
  while (y >= 2 && x * 10 + y >= 22) {
    if (z == 0) {
      r = min(2, x);
      x -= r;
      y -= 2 + 10 * (2 - r);
    } else {
      r = min(2, (y - 2) / 10);
      x -= 2 - r;
      y -= 2 + 10 * r;
    }
    z = 1 - z;
  }
  if (z == 0)
    cout << "Hanako";
  else
    cout << "Ciel";
  return 0;
}
