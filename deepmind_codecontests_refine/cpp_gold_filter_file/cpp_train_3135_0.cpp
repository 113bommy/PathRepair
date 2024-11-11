#include <bits/stdc++.h>
using namespace std;
int main() {
  long long h, w, x, y;
  cin >> h >> w;
  x = min(h, w);
  y = max(h, w);
  if (x >= 3) {
    cout << h * w - h * w % 2 << endl;
  } else if (x == 2) {
    if (y == 2) {
      cout << 0 << endl;
    } else if (y == 3 || y == 7) {
      cout << h * w - 2 << endl;
    } else {
      cout << h * w << endl;
    }
  } else {
    y %= 6;
    if (y == 0) {
      cout << h * w << endl;
    } else {
      cout << h * w - 3 + abs(3 - y) << endl;
    }
  }
}
