#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y, s = 0, l;
  string t;
  cin >> n >> t;
  int a[2 * n + 1][2 * n + 1];
  for (int i = 0; i < 2 * n + 1; i++) {
    for (int j = 0; j < 2 * n + 1; j++) {
      a[i][j] = 0;
    }
  }
  x = n;
  y = n;
  for (int i = 0; i <= n; i++) {
    a[x][y]++;
    if (t[i] == 'U') y++;
    if (t[i] == 'D') y--;
    if (t[i] == 'L') x++;
    if (t[i] == 'R') x--;
  }
  for (int i = 0; i < 2 * n + 1; i++) {
    for (int j = 0; j < 2 * n + 1; j++) {
      s = s + (a[i][j] - 1) * a[i][j] / 2;
    }
  }
  cout << s;
  return 0;
}
