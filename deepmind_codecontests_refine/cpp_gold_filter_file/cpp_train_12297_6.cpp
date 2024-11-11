#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    int x, y;
    cin >> x >> y;
    if (x == y) {
      if (x & 1) x = -x;
      cout << x << endl;
    } else {
      int s = y - x + 1;
      int r;
      if (s & 1) {
        r = x + (y - x + 1) / 2;
        if (x & 1) r = -r;
      } else {
        r = (y - x + 1) / 2;
        if (!(x & 1)) r = -r;
      }
      cout << r << endl;
    }
  }
}
