#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int x1, x2, y1, y2, m, t = 0;
  cin >> x1 >> y1 >> x2 >> y2;
  int a[x1 + 2][y1 + 2];
  cin >> s;
  for (int i = 1; i <= x1; i++)
    for (int j = 1; j <= y1; j++) a[i][j] = 0;
  a[x2][y2] = 1;
  cout << 1 << ' ';
  m = s.length();
  if (m > 1)
    for (int k = 0; k < m - 1; k++) {
      int n = x2, m = y2;
      if (s[k] == 'D' && x2 < x1) {
        x2++;
        if (a[x2][y2] == 1)
          cout << 0 << ' ';
        else {
          a[x2][y2] = 1;
          cout << 1 << ' ';
        }
      }
      if (s[k] == 'U' && x2 > 1) {
        x2--;
        if (a[x2][y2] == 1)
          cout << 0 << ' ';
        else {
          a[x2][y2] = 1;
          cout << 1 << ' ';
        }
      }
      if (s[k] == 'R' && y2 < y1) {
        y2++;
        if (a[x2][y2] == 1)
          cout << 0 << ' ';
        else {
          a[x2][y2] = 1;
          cout << 1 << ' ';
        }
      }
      if (s[k] == 'L' && y2 > 1) {
        y2--;
        if (a[x2][y2] == 1)
          cout << 0 << ' ';
        else {
          a[x2][y2] = 1;
          cout << 1 << ' ';
        }
      }
      if (n == x2 && m == y2) cout << 0 << ' ';
    }
  for (int i = 1; i <= x1; i++) {
    for (int j = 1; j <= y1; j++)
      if (a[i][j] == 0) t++;
  }
  cout << t << ' ';
  return 0;
}
