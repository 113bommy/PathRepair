#include <bits/stdc++.h>
using namespace std;
int main() {
  int x1, x2, y1, y2, edge;
  cin >> x1 >> y1 >> x2 >> y2;
  if (x1 == x2 || y1 == y2 || abs(float(y2 - y1) / (x2 - x1)) == 1) {
    if (x1 == x2 || y2 == y1) {
      edge = abs(x2 - x1 + y2 - y1);
      if (x1 == x2) {
        cout << x1 + edge << " " << y1 << " " << x2 + edge << " " << y2;
      } else {
        cout << x1 << " " << y1 + edge << " " << x2 << " " << y2 + edge;
      }
    } else {
      cout << x2 << " " << y1 << " " << x1 << " " << y2;
    }
  } else
    cout << -1;
  return 0;
}
