#include <bits/stdc++.h>
using namespace std;
template <class T>
T sq(T x) {
  return x * x;
}
const long long inf = 2147383647;
const double pi = 2 * acos(0.0);
const double eps = 1e-9;
const long long maxint = 2147483647;
const long long minint = -2147483648;
int n, m, q;
int grid[1010][1010];
int up[1010][1010], down[1010][1010], lft[1010][1010], rgt[1010][1010];
void dpCalc() {
  int i, j;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (grid[i][j] == 0)
        up[i][j] = 0;
      else
        up[i][j] = up[i - 1][j] + 1;
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (grid[i][j] == 0)
        down[i][j] = 0;
      else
        down[i][j] = down[i + 1][j] + 1;
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (grid[i][j] == 0)
        lft[i][j] = 0;
      else
        lft[i][j] = lft[i][j - 1] + 1;
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = m; j >= 1; j--) {
      if (grid[i][j] == 0)
        rgt[i][j] = 0;
      else
        rgt[i][j] = rgt[i][j + 1] + 1;
    }
  }
}
void toggle(int x, int y) {
  int t = grid[x][y];
  int i;
  if (t) {
    grid[x][y] = 0;
    down[x][y] = 0;
    for (i = x - 1; i >= 1; i--) {
      if (grid[i][y] == 0)
        down[i][y] = 0;
      else
        down[i][y] = down[i + 1][y] + 1;
    }
    up[x][y] = 0;
    for (i = x + 1; i <= n; i++) {
      if (up[i][y] == 0)
        up[i][y] = 0;
      else
        up[i][y] = up[i - 1][y] + 1;
    }
    rgt[x][y] = 0;
    for (i = y - 1; i >= 1; i--) {
      if (grid[x][i] == 0)
        rgt[x][i] = 0;
      else
        rgt[x][i] = rgt[x][i + 1] + 1;
    }
    lft[x][y] = 0;
    for (i = y + 1; i <= m; i++) {
      if (grid[x][i] == 0)
        lft[x][i] = 0;
      else
        lft[x][i] = lft[x][i - 1] + 1;
    }
  } else {
    grid[x][y] = 1;
    down[x][y] = down[x + 1][y] + 1;
    for (i = x - 1; i >= 1; i--) {
      if (grid[i][y] == 0)
        down[i][y] = 0;
      else
        down[i][y] = down[i + 1][y] + 1;
    }
    up[x][y] = up[x - 1][y] + 1;
    for (i = x + 1; i <= n; i++) {
      if (up[i][y] == 0)
        up[i][y] = 0;
      else
        up[i][y] = up[i - 1][y] + 1;
    }
    rgt[x][y] = rgt[x][y + 1] + 1;
    for (i = y - 1; i >= 1; i--) {
      if (grid[x][i] == 0)
        rgt[x][i] = 0;
      else
        rgt[x][i] = rgt[x][i + 1] + 1;
    }
    lft[x][y] = 1 + lft[x][y - 1];
    for (i = y + 1; i <= m; i++) {
      if (grid[x][i] == 0)
        lft[x][i] = 0;
      else
        lft[x][i] = lft[x][i - 1] + 1;
    }
  }
}
vector<pair<int, int> > uleft, uright, dleft, dright;
long long query(int x, int y) {
  long long l, r;
  long long h, res = 0;
  l = y;
  r = y;
  for (h = up[x][y]; h >= 1; h--) {
    while (up[x][l - 1] >= h) l--;
    while (up[x][r + 1] >= h) r++;
    if ((r - l + 1) * h > res) res = (r - l + 1) * h;
  }
  l = x;
  r = x;
  for (h = rgt[x][y]; h >= 1; h--) {
    while (rgt[l - 1][y] >= h) l--;
    while (rgt[r + 1][y] >= h) r++;
    if ((r - l + 1) * h > res) res = (r - l + 1) * h;
  }
  l = y;
  r = y;
  for (h = down[x][y]; h >= 1; h--) {
    while (down[x][l - 1] >= h) l--;
    while (down[x][r + 1] >= h) r++;
    if ((r - l + 1) * h > res) res = (r - l + 1) * h;
  }
  l = x;
  r = x;
  for (h = rgt[x][y]; h >= 1; h--) {
    while (lft[l - 1][y] >= h) l--;
    while (lft[r + 1][y] >= h) r++;
    if ((r - l + 1) * h > res) res = (r - l + 1) * h;
  }
  return res;
}
int main() {
  scanf("%d %d %d", &n, &m, &q);
  int i, j;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      scanf("%d", &grid[i][j]);
    }
  }
  dpCalc();
  while (q--) {
    int t, x, y;
    scanf("%d %d %d", &t, &x, &y);
    if (t == 1) {
      toggle(x, y);
    } else {
      long long res = query(x, y);
      printf("%lld\n", res);
    }
  }
  return 0;
}
