#include <bits/stdc++.h>
using namespace std;
char c[118][118];
int main() {
  int n, m;
  cin >> n >> m;
  int bx, by;
  bool f = false;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> c[i][j];
      if (!f && c[i][j] == 'B') {
        bx = i;
        by = j;
        f = true;
      }
    }
  }
  int ex, ey;
  for (ex = bx + 2; ex <= n; ex += 2)
    if (c[ex][by] != 'B') break;
  for (ey = by + 2; ey <= m; ey += 2)
    if (c[bx][ey] != 'B') break;
  ex -= 2;
  ey -= 2;
  cout << (bx + ex) / 2 << " " << (by + ey) / 2 << endl;
  return 0;
}
