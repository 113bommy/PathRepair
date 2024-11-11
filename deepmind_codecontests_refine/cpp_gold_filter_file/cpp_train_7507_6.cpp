#include <bits/stdc++.h>
using namespace std;
int n, p, i, j, x, y, z, m, t;
int a[1010][1010], b[1010], c[1010], d[1010][3];
void s(int l, int r) {
  int i = l, j = r, b = d[(l + r) / 2][0], k;
  while (i <= j) {
    while (d[i][0] < b) i++;
    while (d[j][0] > b) j--;
    if (i <= j) {
      for (k = 0; k < 3; ++k) swap(d[i][k], d[j][k]);
      i++;
      j--;
    }
  }
  if (i < r) s(i, r);
  if (j > l) s(l, j);
}
int main() {
  cin >> n >> p;
  for (i = 0; i < p; ++i) {
    cin >> x >> y >> z;
    a[x][y] = z;
    b[x] = y;
    c[y] = 1;
  }
  for (i = 1; i <= n; ++i) {
    if (c[i] || !b[i]) continue;
    y = b[i];
    t = a[i][y];
    while (b[y]) {
      t = (((t) < (a[y][b[y]])) ? (t) : (a[y][b[y]]));
      y = b[y];
    }
    d[m][0] = i;
    d[m][1] = y;
    d[m++][2] = t;
  }
  s(0, m - 1);
  cout << m << endl;
  for (i = 0; i < m; cout << endl, ++i)
    for (j = 0; j < 3; ++j) cout << d[i][j] << " ";
  return 0;
}
