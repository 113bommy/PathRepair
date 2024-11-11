#include <bits/stdc++.h>
using namespace std;
const int maxN = 1000 * 1000 + 100;
long long n, x, y, x2, y2, d;
int main() {
  cin >> n >> x >> y >> x2 >> y2;
  if ((x == 0 || x == n) && (x2 == 0 || x2 == n)) {
    if (x == x2)
      d = abs(y - y2);
    else
      d = n + min((y + y2), (n - y + n - y2));
  } else if ((y == 0 || y == n) && (y2 == 0 || y2 == n)) {
    if (y == y2)
      d = abs(x - x2);
    else
      d = n + min((x + x2), (n - x + n - x2));
  } else {
    if (x == 0 && y2 == n) d = n - y + x2;
    if (x == 0 && y2 == 0) d = y + x2;
    if (x == n && y2 == n) d = n - y + n - x2;
    if (x == n && y2 == 0) d = n - x2 + y;
    if (y == 0 && x2 == n) d = n - x + y2;
    if (y == 0 && x2 == 0) d = x + y2;
    if (y == n && x2 == n) d = n - y2 + n - x;
    if (y == n && x2 == 0) d = x + n - y2;
  }
  cout << d << endl;
  return 0;
}
