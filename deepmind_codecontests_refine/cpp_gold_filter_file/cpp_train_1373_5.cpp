#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
long long x1, y;
long long x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
int main() {
  cin >> x1 >> y >> x2 >> y2;
  cin >> x3 >> y3 >> x4 >> y4;
  cin >> x5 >> y5 >> x6 >> y6;
  if (x3 <= x1 && y3 <= y && x2 <= x4 && y2 <= y4) {
    cout << "NO" << endl;
    return 0;
  }
  if (x5 <= x1 && y5 <= y && x2 <= x6 && y2 <= y6) {
    return cout << "NO" << endl, 0;
  }
  if (y3 <= y && y4 >= y2 && y5 <= y && y6 >= y2) {
    long long l1 = min(x3, x5), r1 = max(x4, x6);
    long long l2 = max(x3, x5), r2 = min(x4, x6);
    if (l1 <= x1 && r1 >= x2 && l2 <= r2) return cout << "NO" << endl, 0;
  }
  if (x3 <= x1 && x4 >= x2 && x5 <= x1 && x6 >= x2) {
    long long l1 = min(y3, y5), h1 = max(y4, y6);
    long long l2 = max(y3, y5), h2 = min(y4, y6);
    if (l1 <= y && h1 >= y2 && l2 <= h2) return cout << "NO" << endl, 0;
  }
  cout << "YES" << endl;
  return 0;
}
