#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, x, y, a, b;
  cin >> t;
  while (t > 0) {
    t--;
    cin >> x >> y >> a >> b;
    if (2 * a <= b) {
      cout << a * x + a * y << '\n';
    } else {
      cout << a * abs(x - y) + b * min(x, y) << '\n';
    }
  }
}
