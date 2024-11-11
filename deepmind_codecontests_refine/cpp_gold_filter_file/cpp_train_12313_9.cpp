#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, x, y;
  cin >> s >> x >> y;
  if (y % s == 0 || x >= s || x <= -s) {
    cout << -1;
    return 0;
  }
  y = y / s + 1;
  if (y == 1) {
    if (x < (s + s % 2) / 2 && x > -(s + s % 2) / 2) {
      cout << 1;
    } else {
      cout << -1;
    }
  } else if (y % 2 == 0) {
    y = y / 2;
    if (x < (s + s % 2) / 2 && x > -(s + s % 2) / 2) {
      cout << 2 + (y - 1) * 3;
    } else {
      cout << -1;
    }
  } else {
    y = (y - 1) / 2;
    if (x < 0) {
      cout << 3 + 3 * (y - 1);
    }
    if (x > 0) {
      cout << 3 + 3 * (y - 1) + 1;
    }
    if (x == 0) {
      cout << -1;
    }
  }
}
