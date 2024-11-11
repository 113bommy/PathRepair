#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x1, x2, y1, y2, x, y;
  cin >> n >> m >> x1 >> y1 >> x2 >> y2;
  x = x1 - x2;
  y = y1 - y2;
  if (x < 0) x = -x;
  if (y < 0) y = -y;
  if ((x <= 2 && y <= 4) || (x <= 2 && y <= 4) || (x == 3 && y == 3)) {
    cout << "First\n";
  } else
    cout << "Second\n";
  scanf(" ");
}
