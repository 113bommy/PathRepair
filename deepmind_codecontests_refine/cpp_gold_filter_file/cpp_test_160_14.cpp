#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t != 0) {
    int n, m, r, c, b, d;
    cin >> n >> m >> r >> c >> b >> d;
    if (r <= b && c <= d) {
      cout << min(b - r, d - c) << endl;
    } else if (r <= b && c > d) {
      cout << min(2 * m - c - d, b - r) << endl;
    } else if (c <= d && r > b) {
      cout << min(d - c, 2 * n - r - b) << endl;
    } else if (b < r && d < c) {
      cout << min(2 * n - r - b, 2 * m - c - d) << endl;
    }
    t--;
  }
  return 0;
}
