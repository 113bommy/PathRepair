#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n, x[2], y[2];
  cin >> n >> x[0] >> y[0] >> x[1] >> y[1];
  int w = 100000;
  int ile = 0;
  int x1 = x[0], y1 = y[0];
  for (int ii = 0; ii <= (int)(4 * n + 5) - 1; ii++) {
    if (x1 == x[1] && y1 == y[1]) break;
    if (y1 == 0 && x1 < n - 1)
      x1++;
    else if (x1 == n && y1 < n)
      y1++;
    else if (x1 > 0 && y1 == n)
      x1--;
    else if (x1 == 0 && y1 > 0)
      y1--;
    ile++;
  }
  w = ile;
  ile = 0;
  x1 = x[0];
  y1 = y[0];
  for (int ii = 0; ii <= (int)(4 * n + 5) - 1; ii++) {
    if (x1 == x[1] && y1 == y[1]) break;
    if (y1 == 0 && x1 > 0)
      x1--;
    else if (y1 > 0 && x1 == n)
      y1--;
    else if (y1 == n && x1 < n)
      x1++;
    else if (x1 == 0 && y1 < n)
      y1++;
    ile++;
  }
  w = min(ile, w);
  cout << w << endl;
  return 0;
}
