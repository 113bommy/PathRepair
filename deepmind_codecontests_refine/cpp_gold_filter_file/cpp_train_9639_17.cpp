#include <bits/stdc++.h>
using namespace std;
long long x, y;
long long Max(long long a, long long b) { return a < b ? a : b; }
int main() {
  cin >> x >> y;
  while (1) {
    if (100 * Max(2, x) + 10 * y < 220) {
      printf("Hanako\n");
      break;
    }
    if (x >= 2) {
      x -= 2;
      y -= 2;
    } else {
      if (x == 1 && y >= 12) {
        x -= 1;
        y -= 12;
      } else {
        y -= 22;
      }
    }
    if (100 * Max(2, x) + 10 * y < 220) {
      printf("Ciel\n");
      break;
    }
    if (y >= 22) {
      y -= 22;
    } else {
      if (y >= 12 && x >= 1) {
        x -= 1;
        y -= 12;
      } else {
        x -= 2;
        y -= 2;
      }
    }
  }
  return 0;
}
