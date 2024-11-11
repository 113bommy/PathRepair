#include <bits/stdc++.h>
using namespace std;
int main() {
  string x, y;
  int t;
  cin >> t;
  for (int j = 0; j < t; ++j) {
    cin >> x >> y;
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    int pos_x = 0, pos_y = 0;
    while (pos_y < y.length() && y[pos_y] == '0') pos_y++;
    if (pos_y == y.length() - 1 && y[0] == '0') {
      cout << 0 << "\n";
    } else {
      while (pos_x < x.length() && x[pos_x] == '0' || pos_x < pos_y) pos_x++;
      if (pos_y > pos_x)
        cout << 0 << "\n";
      else if (x[pos_x] == '1' && pos_x == pos_y) {
        cout << 0 << "\n";
      } else {
        cout << pos_x - pos_y << "\n";
      }
    }
  }
  return 0;
}
