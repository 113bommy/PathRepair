#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t > 0) {
    int a, b, c, d, x, y, x1, x2, y1, y2;
    cin >> a >> b >> c >> d;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    string ans;
    int h = b - a;
    int v = d - c;
    if (x + h >= x1 && x + h <= x2 && y + v >= y1 && y + v <= y2)
      ans = "YES";
    else
      ans = "NO";
    if ((abs(x1 - x) < min(a, 1) && abs(x2 - x) < min(b, 1)) ||
        (abs(y1 - y) < min(c, 1) && abs(y2 - y) < min(d, 1)))
      ans = "NO";
    cout << ans << endl;
    t--;
  }
  return 0;
}
