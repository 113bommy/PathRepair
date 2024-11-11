#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y;
  cin >> x >> y;
  if ((x == 0 || x == 1) && y == 0) {
    cout << 0;
    return 0;
  }
  int a, b;
  a = max(abs(x), abs(y));
  b = a;
  int cnt = 1;
  if (x - abs(y) == 1) a--, b--;
  if (x < a && x >= -a && y == b) {
    cout << (a - 1) * 4 + 1 + cnt;
    return 0;
  }
  if (x == -a && y <= b && y >= -b) {
    cout << (a - 1) * 4 + 2 + cnt;
    return 0;
  }
  if (y == -b && x >= -a && x <= a + 1) {
    cout << (a - 1) * 4 + 3 + cnt;
    return 0;
  }
  if (x == a && y <= b && y > -b) {
    cout << (a - 1) * 4 + cnt;
    return 0;
  }
}
