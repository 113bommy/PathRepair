#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, t, a, b, c, x1, x2;
  cin >> t;
  for (i = 0; i < t; ++i) {
    cin >> a >> b >> c;
    x1 = 0;
    x2 = 0;
    if (a >= c) {
      x1 = -1;
    } else {
      x1 = 1;
    }
    if (a * b <= c) {
      x2 = -1;
    } else {
      x2 = b;
    }
    cout << x1 << " " << x2 << endl;
  }
  return 0;
}
