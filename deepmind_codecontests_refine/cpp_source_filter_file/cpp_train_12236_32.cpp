#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z;
  cin >> x >> y >> z;
  while (z != 0) {
    if (z > 0) {
      z--;
      y++;
      if (y == 7) {
        y = 1;
      }
    }
    if (z < 0) {
      z++;
      y--;
      if (y == 0) {
        y = 6;
      }
    }
  }
  cout << y;
  return 0;
}
