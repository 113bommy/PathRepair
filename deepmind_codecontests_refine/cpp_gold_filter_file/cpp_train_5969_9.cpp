#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, m, x1, x2, y1, y2, dx, dy;
  long long s1, s2, s;
  cin >> t;
  while (t--) {
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    dx = abs(x1 - x2);
    dy = abs(y1 - y2);
    s1 = (n - dx) * (m - dy);
    x1 = 1 + dx;
    y1 = 1 + dy;
    x2 = n - dx;
    y2 = m - dy;
    if (x1 <= x2 and y1 <= y2)
      s2 = (x2 - x1 + 1) * (y2 - y1 + 1);
    else
      s2 = 0;
    s = n * m - s1 * 2 + s2;
    cout << s << endl;
  }
}
