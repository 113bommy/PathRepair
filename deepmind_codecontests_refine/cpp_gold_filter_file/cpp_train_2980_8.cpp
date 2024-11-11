#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  ofstream out(".out");
  ifstream in(".in");
  long long int k, n = 0, m = 0, u[102] = {}, v[102] = {};
  int a[3][3] = {}, b[3][3] = {}, x, y, d[3][3] = {}, c = 0;
  cin >> k >> x >> y;
  x--;
  y--;
  for (int i = 0; i < 9; i++) cin >> a[i / 3][i % 3];
  for (int i = 0; i < 9; i++) cin >> b[i / 3][i % 3];
  for (int i = 0; i < 9; i++) a[i / 3][i % 3]--, b[i / 3][i % 3]--;
  for (int i = 0; i < 9; i++) d[i / 3][i % 3] = -1;
  d[x][y] = 0;
  for (int i = 1; i <= 100; i++) {
    if (x != y) {
      if (x > y) {
        if (x == 2 && y == 0)
          m++;
        else
          n++;
      } else {
        if (x == 0 && y == 2)
          n++;
        else
          m++;
      }
    }
    u[i] = n, v[i] = m;
    int x0 = x, y0 = y;
    x = a[x0][y0];
    y = b[x0][y0];
    if (d[x][y] != -1) c = i - d[x][y];
    d[x][y] = i;
  }
  if (k < 100) {
    cout << u[k] << ' ' << v[k];
    return 0;
  }
  long long int r = k / c, s = k % c;
  long long int g = u[99] - u[99 - c], h = v[99] - v[99 - c];
  cout << (r - 4) * g + u[s + c * 4] << ' ' << (r - 4) * h + v[s + c * 4];
}
