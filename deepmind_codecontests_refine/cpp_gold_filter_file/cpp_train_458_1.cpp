#include <bits/stdc++.h>
using namespace std;
int n, m, x;
void ans(int x1, int x2, int y1, int y2, int now) {
  if (x1 + 1 > x2 - 1 || y1 + 1 > y2 - 1) {
    cout << 0;
    return;
  } else {
    if (now + 1 == x) {
      if ((x2 - x1 - 1) == 1 || (y2 - y1 - 1) == 1) {
        if ((x2 - x1 - 1) == 1 && (y2 - y1 - 1) == 1)
          cout << 1;
        else
          cout << ((x2 - x1 - 1) + (y2 - y1 - 1) - 1) / 2;
      } else
        cout << ((x2 - x1 - 1) + (y2 - y1 - 1) - 2);
    } else
      ans(x1 + 1, x2 - 1, y1 + 1, y2 - 1, now + 1);
  }
}
int main() {
  cin >> n >> m >> x;
  if (n == 1 || m == 1) {
    if (n == 1 && m == 1) {
      if (x == 1) {
        cout << 1;
      } else
        cout << 0;
      return 0;
    }
    if (x == 1) {
      cout << (n + m) / 2;
    } else
      cout << 0;
    return 0;
  }
  if (x == 1) {
    cout << (n + m - 2);
    return 0;
  }
  ans(1, n, 1, m, 1);
  return 0;
}
