#include <bits/stdc++.h>
using namespace std;
int main() {
  int i;
  cin >> i;
  int j, k, l = 0, m = 0, n = 0, h, a;
  for (j = 19;; j++) {
    a = j;
    h = j;
    for (k = 1; k < 6; k++) {
      l = h % 10;
      h = h / 10;
      m = l + m;
      if (h < 10) {
        m = m + h;
        break;
      }
    }
    if (m == 10) {
      n = n + 1;
      if (n == i) {
        cout << a << endl;
        break;
      }
    }
    m = 0;
  }
  return 0;
}
