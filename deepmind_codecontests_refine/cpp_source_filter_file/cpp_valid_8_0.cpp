#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, n, c, d, i, b, j, mas[100002], v, m;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a;
    c = a / 1.5;
    if (c * 1.5 < a) {
      if (c * 1.5 + 2 > a) {
        if (c % 2 != 0) {
          d = (c / 2) + 1;
          b = c / 2;
        } else {
          b = (c / 2) + 1;
          d = c / 2;
        }
      } else {
        d = (c / 2) + 1;
        b = c / 2;
      }
    } else {
      b = c / 2;
      d = b;
    }
    cout << b << " " << d;
  }
  return 0;
}
