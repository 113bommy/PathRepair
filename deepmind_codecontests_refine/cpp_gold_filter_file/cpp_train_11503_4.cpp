#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, ans = 0;
  cin >> n >> m;
  int x = 0, y = 0, x1 = 0, y1 = 0;
  cin >> x1 >> y1;
  ans = y1 + (x1 - 1);
  for (int i = 1; i < m; i++) {
    cin >> x >> y;
    if (abs(y - y1) > abs(x - x1)) return cout << "IMPOSSIBLE", 0;
    ans = max(ans, (((x - x1) + (y1 + y)) / 2));
    x1 = x;
    y1 = y;
  }
  if (x1 != n) {
    ans = max(ans, y1 + (n - x1));
  }
  cout << ans;
}
