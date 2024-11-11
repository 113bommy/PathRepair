#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  if (x1 + y1 < max(x2, y2)) {
    cout << "Polycarp";
    return 0;
  }
  if (x1 <= x2 && y1 <= y2) {
    cout << "Polycarp";
    return 0;
  }
  cout << "Vasiliy";
}
