#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, m;
  int x, y, z;
  bool flag = true;
  cin >> t;
  while (t--) {
    flag = true;
    cin >> n >> m;
    int l = m, r = m;
    int tmp = 0;
    for (int i = 0; i < n; i++) {
      cin >> x >> y >> z;
      l -= (x - tmp), r += (x - tmp), tmp = x;
      if (z < l || y > r) {
        flag = false;
      }
      if (l < y) l = y;
      if (r > z) r = z;
    }
    if (flag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
