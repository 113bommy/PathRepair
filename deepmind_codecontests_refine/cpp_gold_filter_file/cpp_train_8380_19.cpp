#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int x, y, x0, y0;
  cin >> x >> y >> x0 >> y0;
  string s;
  cin >> s;
  set<int> si;
  for (char ch : s) {
    int hash = x0 * 1000 + y0, ans = 1;
    if (si.count(hash) > 0) {
      ans = 0;
    } else {
      si.insert(hash);
    }
    cout << ans << ' ';
    if (ch == 'D')
      x0 = min(x0 + 1, x);
    else if (ch == 'U')
      x0 = max(x0 - 1, 1);
    else if (ch == 'L')
      y0 = max(y0 - 1, 1);
    else if (ch == 'R')
      y0 = min(y0 + 1, y);
  }
  cout << (x * y - si.size());
  return 0;
}
