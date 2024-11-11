#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const auto IO_ = [] { return ios::sync_with_stdio(false), cin.tie(nullptr); }();
signed main() {
  char a, aa, b, bb;
  cin >> a >> aa >> b >> bb;
  int x1 = a - 'a', y1 = aa - '1', x2 = b - 'a', y2 = bb - '1';
  string ans;
  while (abs(x1 - x2) && abs(x2 - y2)) {
    if (x1 < x2 && y1 < y2) {
      ans += "RU\n";
      x1++, y1++;
    } else if (x1 < x2 && y1 > y2) {
      ans += "RD\n";
      x1++, y1--;
    } else if (x1 > x2 && y1 > y2) {
      ans += "LD\n";
      x1--, y1--;
    } else if (x1 > x2 && y1 < y2) {
      ans += "LU\n";
      x1--, y1++;
    }
  }
  while (x1 != x2) {
    if (x1 < x2) {
      ans += "R\n";
      x1++;
    } else {
      ans += "L\n";
      x1--;
    }
  }
  while (y1 != y2) {
    if (y1 < y2) {
      ans += "U\n";
      y1++;
    } else {
      ans += "D\n";
      y1--;
    }
  }
  cout << count(ans.begin(), ans.end(), '\n') << '\n';
  cout << ans;
  return 0;
}
