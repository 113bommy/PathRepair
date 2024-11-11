#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t1, t2, x1, x2, t0;
  cin >> t1 >> t2 >> x1 >> x2 >> t0;
  long long int dt = t2 - t0;
  if (dt == 0) {
    if (t1 != t2)
      cout << 0 << " " << x2 << "\n";
    else
      cout << x1 << " " << x2 << "\n";
    return 0;
  }
  pair<long long int, long long int> best = make_pair(-1, -1);
  pair<long long int, long long int> ans = make_pair(-1, -1);
  for (long long int y1 = 1; y1 <= x1; y1++) {
    long long int y2 = (y1 * (t0 - t1) + (dt - 1)) / dt;
    y2 = min(y2, x2);
    long long int bottom = y1 + y2;
    if (t0 * bottom > t1 * y1 + t2 * y2) continue;
    long long int top = t1 * y1 + t2 * y2 - t0 * bottom;
    if (best.first == -1) {
      best = make_pair(top, bottom);
      ans = make_pair(y1, y2);
    } else if (top * best.second < bottom * best.first) {
      best = make_pair(top, bottom);
      ans = make_pair(y1, y2);
    } else if (top * best.second == bottom * best.first) {
      if (top + bottom > best.first + best.second) {
        best = make_pair(top, bottom);
        ans = make_pair(y1, y2);
      }
    }
  }
  if (ans.first == -1) ans = make_pair(0, x2);
  cout << ans.first << " " << ans.second << "\n";
  return 0;
}
