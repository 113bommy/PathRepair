#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  long long n, m, x1, y1, x2, y2;
  cin >> T;
  while (T--) {
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    if (x1 > x2) swap(x1, x2);
    if (y1 > y1) swap(y1, y2);
    x2 -= (x1 - 1);
    x1 = 1;
    y2 -= (y1 - 1);
    y1 = 1;
    long long ret = n * m;
    long long rx = n - x2 + 1;
    long long ry = m - y2 + 1;
    ret -= 2 * rx * ry;
    if (x1 + rx - 1 >= x2 && y1 + ry - 1 >= y2) {
      ret += (x1 + rx - x2) * (y1 + ry - y2);
    }
    cout << ret << endl;
  }
}
