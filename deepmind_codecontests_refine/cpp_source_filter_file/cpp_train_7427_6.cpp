#include <bits/stdc++.h>
using namespace std;
int n, m, k, y, x, a, b, d[2001][2001] = {0};
bool penuh[2001][2001] = {0};
bool cari(int x, int y, int z) {
  int l = max(x - z, l);
  int r = min(x + z, n);
  int i, t;
  for (int i = l; i <= r; i++) {
    t = z - abs(i - x);
    if (y - t > 0 && penuh[i][y - t] == 0) {
      a = i;
      b = y - t;
      return true;
    }
    if (y + t <= m && penuh[i][y + t] == 0) {
      a = i;
      b = y + t;
      return true;
    }
  }
  return 0;
}
int main() {
  cin >> n >> m >> k;
  while (k--) {
    cin >> x >> y;
    for (int i = -2; i < 3; i++) {
      for (int j = -2; j < 3; j++) {
        if (x + i < 1 || x + i > n || y + j < 1 || y + j > m) continue;
        d[x][y] = max(d[x][y], d[x + 1][y + j] - abs(i) - abs(j));
      }
    }
    while (cari(x, y, d[x][y]) == 0) {
      d[x][y]++;
    }
    cout << a << " " << b << endl;
    penuh[a][b] = 1;
  }
  return 0;
}
