#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n;
  cin >> n >> m;
  int x1 = -1, y1 = -1, x2 = -1, y2 = -1, x3 = -1, y3 = -1, x4 = -1, y4 = -1;
  string array[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> array[i][j];
      if (array[i][j] == "*") {
        if (x1 == -1) {
          x1 = i;
          y1 = j;
        } else if (x2 == -1) {
          x2 = i;
          y2 = j;
        } else if (x3 == -1) {
          x3 = i;
          y3 = j;
        }
      }
    }
  }
  if (x1 == x2)
    x4 = x3;
  else if (x2 == x3)
    x4 = x1;
  else if (x1 == x3)
    x4 = x2;
  if (y1 == y2)
    y4 = y3;
  else if (y2 == y3)
    y4 = y1;
  else if (y1 == y3)
    y4 = y2;
  x4 = x4 + 1;
  y4 = y4 + 1;
  cout << x4 << " " << y4;
  return 0;
}
