#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, a, b, c, k = 0, q = 0, w = 0;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> a >> b >> c;
    while (c >= 2 and b >= 1) {
      if ((b - c / 2) >= 0) {
        q = b - c / 2;
        k = k + 3 * (b - q);
        c = c - 2 * (b - q);
        b = q;
      }
      c -= 2;
    }
    while (b >= 2 and a >= 1) {
      if ((a - b / 2) >= 0) {
        q = a - b / 2;
        w = w + 3 * (a - q);
        b = b - 2 * (a - q);
        a = w;
      }
      b -= 2;
    }
    cout << k + w << "\n";
    k = 0;
    w = 0;
  }
}
