#include <bits/stdc++.h>
using namespace std;
int n, m, sx, sy;
struct coord {
  int l;
  int u;
};
coord fillCol(int posx, int posy) {
  int orx = posx;
  int ory = posy;
  cout << posx << " " << posy << endl;
  while (posx > 1) {
    posx--;
    cout << posx << " " << posy << endl;
  }
  posx = orx;
  while (posx < n) {
    posx++;
    cout << posx << " " << posy << endl;
  }
  return {posx, posy + 1};
}
int main() {
  cin >> n >> m >> sx >> sy;
  coord prev = fillCol(sx, sy);
  int i;
  for (i = 1; i < m; i++) {
    if (i + sy == m + 1) {
      break;
    }
    if (i % 2 == 1) fillCol(n, i + sy);
    if (i % 2 == 0) fillCol(1, i + sy);
  }
  int j = i;
  int cntr = 1;
  while (true) {
    j++;
    if (j % 2 == 0) {
      prev = fillCol(n, cntr);
    } else {
      prev = fillCol(1, cntr);
    }
    if (cntr == sx - 1) break;
    cntr++;
  }
}
