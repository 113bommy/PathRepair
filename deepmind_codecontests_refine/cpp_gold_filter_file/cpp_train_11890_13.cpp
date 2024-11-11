#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
bool que(int x, int y) {
  char ch;
  cout << "? " << x + 1 << ' ' << y + 1 << endl;
  cin >> ch;
  return ch == '<';
}
int main() {
  int ii, tt, i, j, k, m, n, x1, x2, y1, y2;
  cin >> tt;
  for (ii = 0; ii < tt; ii++) {
    cin >> n;
    x1 = 0;
    x2 = 1;
    y1 = 2;
    y2 = 3;
    if (!que(x1, x2)) {
      swap(x1, x2);
    }
    if (!que(y1, y2)) {
      swap(y1, y2);
    }
    if (!que(x1, y1)) {
      swap(x1, y1);
      swap(x2, y2);
    }
    for (i = 4; i < 2 * n; i++) {
      x1 = i;
      if (!que(x1, x2)) {
        swap(x1, x2);
      }
      if (!que(x1, y1)) {
        swap(x1, y1);
        swap(x2, y2);
      }
    }
    for (i = 0; i < 2 * n; i++) {
      for (j = 0; j < i; j++) {
        if (i != x2 && i != y1 && i != y2 && j != x2 && j != y1 && j != y2) {
          que(i, j);
        }
      }
    }
    cout << "!" << endl;
  }
  return 0;
}
