#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z;
  cin >> x >> y >> z;
  if (z - y == 1 && y - x == 1) {
    cout << x + y + z << endl;
  } else {
    if (z > y) {
      while (z - y != 1) {
        z--;
      }
    } else if (y > z) {
      while (y != z - 1) {
        y--;
      }
    } else if (y == z) {
      y--;
    }
    if (x > y) {
      while (x != y - 1) {
        x--;
      }
    } else if (y >= x) {
      if (y == x) {
        x--;
      } else {
        while (y != x + 1) {
          y--;
        }
        while (z != y + 1) {
          z--;
        }
      }
    }
    cout << x + y + z << endl;
  }
}
