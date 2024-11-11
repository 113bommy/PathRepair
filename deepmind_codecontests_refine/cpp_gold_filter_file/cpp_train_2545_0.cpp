#include <bits/stdc++.h>
using namespace std;
int main() {
  string s = " ";
  int x1, y1, x2, y2, l;
  cin >> x1 >> y1 >> x2 >> y2;
  if (x1 == x2) {
    l = y2 - y1;
    cout << x1 + l << s << y1 << s << x2 + l << s << y2;
  } else if (y1 == y2) {
    l = x1 - x2;
    cout << x1 << s << y1 + l << s << x2 << s << y2 + l;
  } else if (abs(y1 - y2) == abs(x1 - x2)) {
    cout << x1 << s << y2 << s << x2 << s << y1 << s;
  } else
    cout << "-1";
  return 0;
}
