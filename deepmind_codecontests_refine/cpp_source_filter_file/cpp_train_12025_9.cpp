#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, i, j, k, x, y, n;
  while (cin >> n) {
    x = 0;
    y = 0;
    for (i = 1; i <= n; i++) {
      cin >> a >> b;
      if (i == 1) {
        x = b;
        y = b;
      } else if (y > b) {
        x = x + (b * a);
        y = b;
      } else
        x = x + (y * a);
    }
    cout << x << endl;
  }
  return 0;
}
