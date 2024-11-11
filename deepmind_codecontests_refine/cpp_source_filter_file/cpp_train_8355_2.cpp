#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, x, y, div, d, q, a;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> x;
    cin >> y;
    div = n;
    while (--div) {
      if ((y - x) % div == 0) break;
    }
    d = (y - x) / div;
    q = y / d < n - 1 ? (y % d == 0 ? y / d - 1 : y / d) : n - 1;
    a = y - q * d;
    for (int i = 0; i < n; i++) {
      cout << a + i * d << " ";
    }
    cout << endl;
  }
}
