#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, x1, y1, x2, y2;
  cin >> t >> x1 >> y1 >> x2 >> y2;
  char a, b;
  int x = 0, y = 0;
  if (x1 - x2 <= 0)
    a = 'E';
  else
    a = 'W';
  if (y1 - y2 <= 0)
    b = 'N';
  else
    b = 'S';
  string s;
  cin >> s;
  a = abs(x1 - x2);
  y = abs(y1 - y2);
  if (x == 0 && y == 0) {
    cout << 0;
    return 0;
  }
  for (int i = 1; i <= t; i++) {
    if (s[i - 1] == a && x != 0) {
      x--;
    } else if (s[i - 1] == b && y != 0)
      y--;
    if (x == 0 && y == 0) {
      cout << i;
      return 0;
    }
  }
  cout << -1;
}
