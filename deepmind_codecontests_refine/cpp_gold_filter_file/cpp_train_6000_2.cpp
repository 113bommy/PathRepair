#include <bits/stdc++.h>
using namespace std;
int main() {
  int x[] = {1, -1, 0, 0, 1, -1, 1, -1};
  int y[] = {1, -1, -1, 1, 0, 0, -1, 1};
  int x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int s = abs(x1 - x2 + x[0]) + abs(y1 - y2 + y[0]);
  for (int i = 1; i < 8; i++) {
    s = min(s, abs(x1 - x2 + x[i]) + abs(y1 - y2 + y[i]));
  }
  cout << s * 2 + 8;
  return 0;
}
