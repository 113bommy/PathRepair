#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:512000000")
using namespace std;
int xy[2000][2000];
char qq[2000][2000];
int yo = 1000, xo = 1000;
int op;
int n, t;
void tbfs(int x, int y) {
  qq[x][y] = 1;
  while (xy[x][y] >= 4) {
    int j = xy[x][y] / 4;
    xy[x][y] %= 4;
    xy[x + 1][y] += j;
    xy[x - 1][y] += j;
    xy[x][y - 1] += j;
    xy[x][y + 1] += j;
    if (!qq[x + 1][y]) tbfs(x + 1, y);
    if (!qq[x - 1][y]) tbfs(x - 1, y);
    if (!qq[x][y + 1]) tbfs(x, y + 1);
    if (!qq[x][y - 1]) tbfs(x, y - 1);
  }
  qq[x][y] = 0;
}
int main() {
  cin >> n >> t;
  xy[xo][yo] = n;
  tbfs(xo, yo);
  for (int i = 0; i < t; ++i) {
    int y, x;
    cin >> x >> y;
    if (abs(y) > 1000 || abs(x) > 1000) {
      cout << "0";
    } else {
      cout << xy[xo + x][yo + y];
    }
    cout << endl;
  }
}
