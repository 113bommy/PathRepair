#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, a, b, c, d, max;
  cin >> t;
  while (t != 0) {
    cin >> a >> b >> c >> d;
    if (b == c && a == d) {
      cout << a + c << endl;
    } else if (c > a) {
      if (d >= b) {
        cout << c + d << endl;
      } else {
        max = c + d;
        if (max < (a + b)) {
          max = a + b;
        }
        cout << max << endl;
      }
    } else if (a > c) {
      if (b >= d) {
        cout << a + b;
      } else {
        max = a + b;
        if (max < (c + d)) {
          max = c + d;
        }
        cout << max << endl;
      }
    } else if (a == c) {
      max = a + b;
      if (max < (c + d)) {
        max = c + d;
      }
      cout << max << endl;
    }
    t--;
  }
  return 0;
}
