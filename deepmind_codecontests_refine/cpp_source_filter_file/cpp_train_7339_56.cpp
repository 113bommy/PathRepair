#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, c, i, j, d = 0, e = 0, m, f, b;
  char a[8][8];
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      cin >> a[i][j];
    }
  }
  for (i = 1; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      if (a[i][j] == 'W') {
        f = 0;
        for (int k = i - 1; k >= 0; k--) {
          if (a[k][j] == 'B' || a[k][j] == 'W') f = 1;
        }
        if (f == 0) {
          d = i;
          break;
        }
      }
    }
    if (d > 0) break;
  }
  for (i = 1; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      if (a[7 - i][j] == 'B') {
        b = 0;
        for (int k = 7 - i + 1; k <= 0; k++) {
          if (a[k][j] == 'W' || a[k][j] == 'B') b = 1;
        }
        if (b == 0) {
          e = i;
          break;
        }
      }
    }
    if (e > 0) break;
  }
  if (e == d)
    cout << "A" << endl;
  else {
    if (e > 0 && d > 0)
      m = min(e, d);
    else if (e == 0 || d == 0)
      m = max(e, d);
    if (m == d)
      cout << "A" << endl;
    else if (m == e)
      cout << "B" << endl;
  }
}
