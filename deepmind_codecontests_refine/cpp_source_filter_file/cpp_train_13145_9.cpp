#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int t;
  int INF = 1000228;
  cin >> t;
  while (t--) {
    long long x, y;
    cin >> x >> y;
    long long c1, c2, c3, c4, c5, c6;
    cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;
    c1 = min(c1, c2 + c6);
    c2 = min(c2, c3 + c1);
    c3 = min(c3, c4 + c2);
    c4 = min(c4, c5 + c3);
    c5 = min(c5, c6 + c4);
    c6 = min(c6, c1 + c5);
    if (x < 0) {
      swap(c1, c3);
      swap(c2, c5);
      swap(c4, c6);
      x = -x;
      y = -y;
    }
    if (x <= y) {
      cout << c1 * x + c2 * (y - x) << "\n";
    } else if (y <= 0) {
      cout << c1 * x + abs(y) * c5 << "\n";
    } else {
      cout << y * c1 + (x - y) * c6 << "\n";
    }
  }
  return 0;
}
