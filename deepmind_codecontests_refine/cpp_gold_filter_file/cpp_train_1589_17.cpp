#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, x, y, b, c;
  cin >> t;
  for (int a = 1; a <= t; a++) {
    cin >> n >> x >> y;
    b = y / n;
    c = b * n + x;
    if (c > y) {
      c = c - n;
    }
    if (n > y) {
      cout << x << "\n";
    } else
      cout << c << "\n";
  }
}
