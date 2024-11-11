#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int a, b, x, y, r, j;
    cin >> a >> b >> x >> y;
    r = max(a - 1 - x, x);
    j = max(b - 1 - y, y);
    if (r * y > x * j)
      cout << r * y << "\n";
    else
      cout << x * j << "\n";
  }
}
