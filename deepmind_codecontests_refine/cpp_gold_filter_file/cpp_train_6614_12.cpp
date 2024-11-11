#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int inf = 1e9;
const int mod = 1e9;
const int base = 1000 * 1000 * 1000;
struct tp {
  int a, b, c, d;
};
int n, m, a[105][105], x, y, t, z, k;
tp f[10005];
int main() {
  cin >> n >> m >> x;
  for (int i = 1; i <= x; i++) {
    cin >> y;
    if (y == 1 || y == 2) {
      cin >> z;
      f[i].a = y;
      f[i].b = z;
    } else {
      cin >> t >> z >> k;
      f[i].a = y;
      f[i].b = t;
      f[i].c = z;
      f[i].d = k;
    }
  }
  for (int i = x; i >= 1; i--) {
    if (f[i].a == 3) a[f[i].b][f[i].c] = f[i].d;
    if (f[i].a == 1) {
      int ty = a[f[i].b][m];
      for (int j = m; j >= 2; j--) {
        a[f[i].b][j] = a[f[i].b][j - 1];
      }
      a[f[i].b][1] = ty;
    }
    if (f[i].a == 2) {
      int ty = a[n][f[i].b];
      for (int j = n; j >= 2; j--) {
        a[j][f[i].b] = a[j - 1][f[i].b];
      }
      a[1][f[i].b] = ty;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
