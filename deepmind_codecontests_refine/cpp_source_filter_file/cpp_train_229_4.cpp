#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, i, j, a, a1, b, b1, f = 0;
  cin >> t;
  for (i = 0; i < t; i++) {
    cin >> n;
    cin >> a1 >> b1;
    if (a1 < b1) {
      f++;
    }
    for (j = 1; j < n; j++) {
      cin >> a >> b;
      if (a < b || a - a1 < b) {
        f++;
      } else if ((a > a1 && b >= b1) || (a == a1 && b == b1)) {
        a1 = a;
        b1 = b;
      } else {
        f++;
      }
    }
    if (f == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
    f = 0;
  }
}
