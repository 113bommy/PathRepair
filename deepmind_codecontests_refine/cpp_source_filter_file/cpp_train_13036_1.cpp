#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[3], t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int cnt = 0, x, y, z;
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    x = a[0], y = a[1], z = a[2];
    if (x >= 1) {
      x--;
      cnt++;
    }
    if (y >= 1) {
      y--;
      cnt++;
    }
    if (z >= 1) {
      z--;
      cnt++;
    }
    if (x >= 1 && y >= 1) {
      x--;
      y--;
      cnt++;
    }
    if (x >= 1 && z >= 1) {
      x--;
      z--;
      cnt++;
    }
    if (y >= 1 && z >= 1) {
      y--;
      z--;
      cnt++;
    }
    if (x >= 1 && y >= 1 && z >= 1) {
      x--;
      y--;
      z--;
      cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}
