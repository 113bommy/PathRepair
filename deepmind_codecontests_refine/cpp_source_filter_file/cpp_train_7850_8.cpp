#include <bits/stdc++.h>
using namespace std;
int a[500005];
bool v[1001][1001];
int b[500005][2];
int c[500005];
int n, m, tot;
void add(int x, int y) {
  v[x][y] = 1;
  v[y][x] = 1;
}
void Solve() {
  int i, j, t, len, x, y, tx, ty, last;
  cin >> n;
  memset(v, 0, sizeof(v));
  a[1] = 1;
  m = 31;
  for (i = 2; i <= m; ++i) a[i] = a[i - 1] * 2;
  x = 3;
  y = 4;
  b[m][0] = x;
  b[m][1] = y;
  x = 5;
  y = 6;
  for (i = m - 1; i >= 2; --i) {
    add(b[i + 1][0], x);
    add(b[i + 1][1], x);
    add(b[i + 1][0], y);
    add(b[i + 1][1], y);
    b[i][0] = x;
    b[i][1] = y;
    x += 2;
    y += 2;
  }
  add(b[2][0], x);
  add(b[2][1], x);
  b[1][0] = b[1][1] = x;
  add(2, x);
  ++x;
  for (i = 1; i <= m; ++i) add(x, x + 1), c[i] = x++;
  for (i = m; i >= 1; --i) {
    if (n >= a[i]) {
      n -= a[i];
      t = m - i;
      x = 1;
      if (t > 0) {
        x = c[i];
        add(1, x);
      }
      add(x, b[i][0]);
      add(x, b[i][1]);
    }
  }
  cout << 100 << endl;
  for (i = 1; i <= 100; ++i) {
    for (j = 1; j <= 100; ++j)
      if (v[i][j])
        cout << "Y";
      else
        cout << "N";
    cout << endl;
  }
}
int main() {
  Solve();
  cin >> n;
  return 0;
}
