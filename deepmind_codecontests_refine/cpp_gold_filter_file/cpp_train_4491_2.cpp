#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, n, l = 0, r = 1e9, sum = 0, ans = 0, x1 = 0, y1 = 0, h, w, x, y;
  char c;
  cin >> t;
  while (t--) {
    cin >> c;
    if (c == '+') {
      cin >> x >> y;
      x1 = max(x1, min(x, y));
      y1 = max(y1, max(x, y));
    } else {
      cin >> h >> w;
      if (x1 <= min(h, w) && y1 <= max(h, w)) {
        cout << "YES" << endl;
      } else
        cout << "NO" << endl;
    }
  }
  return 0;
}
