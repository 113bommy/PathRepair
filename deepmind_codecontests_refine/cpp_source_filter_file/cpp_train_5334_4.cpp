#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  cin >> test;
  while (test--) {
    long long int a, b, c, d;
    cin >> a >> b >> c >> d;
    long long int x, y, x1, x2, y1, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    x = b - a;
    y = d - c;
    if (x >= x1 && x <= x2 && y >= y1 && y <= y2 && (x2 > x1 || a + b == 0) &&
        (y2 > y1 || c + d == 0)) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}
