#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x, y;
    cin >> n >> x >> y;
    int res = 0x3f3f3f3f;
    ;
    int diff = -1;
    for (int d = 1; d <= 50; d++) {
      int n0 = n;
      if ((y - x) % d != 0) {
        continue;
      } else {
        n -= (y - x) / d;
        n--;
        if (n < 0) {
          n = n0;
          continue;
        }
        if (y + n * d < res) {
          res = y + n * d;
          diff = d;
        }
      }
      n = n0;
    }
    if ((y - 1) / diff + 1 >= n) {
      while (n--) {
        cout << y << " ";
        y -= diff;
      }
    } else {
      int curr = y % diff;
      if (curr == 0) curr = diff;
      while (n--) {
        cout << curr << " ";
        curr += diff;
      }
    }
    cout << endl;
  }
}
