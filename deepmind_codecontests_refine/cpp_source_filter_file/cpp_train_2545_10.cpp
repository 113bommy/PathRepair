#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int x1, y1, x2, y2, a;
  cin >> x1 >> y1 >> x2 >> y2;
  if (x1 != x2 && y1 != y2 && abs(x1 - x2) != abs(y1 - y2))
    cout << -1 << '\n';
  else {
    if (x1 == x2) {
      a = abs(y1 - y2);
      cout << x1 + a << " " << y1 << " " << x1 + a << " " << y2 << '\n';
    } else if (y1 == y2) {
      a = abs(y1 - y2);
      cout << x1 << " " << y1 + a << " " << x2 << " " << y1 + a << '\n';
    } else {
      cout << x1 << " " << y2 << " " << x2 << " " << y1 << '\n';
    }
  }
}
