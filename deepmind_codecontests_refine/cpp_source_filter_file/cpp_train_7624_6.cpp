#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int t, x, y;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> x >> y;
    if (x == y) {
      cout << x * y * 4 << endl;
    } else if (x > y) {
      y = 2 * y;
      if (y > x) {
        cout << y * y << endl;
      } else if (x > y) {
        cout << x * x << endl;
      } else if (x == y) {
        cout << x * y * 4 << endl;
      }
    } else if (x < y) {
      x = 2 * x;
      if (y < x) {
        cout << x * x << endl;
      } else if (x < y) {
        cout << y * y << endl;
      } else if (x == y) {
        cout << x * y * 4 << endl;
      }
    }
  }
  return 0;
}
