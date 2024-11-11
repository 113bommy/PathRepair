#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, st, res = 0, flag = 0;
  cin >> n >> m >> st;
  int a[n][m];
  memset(a, 0, n * m);
  for (int i = 1; i <= st; i++) {
    int x, y;
    cin >> y >> x;
    a[x][y] = 1;
    if (a[x + 1][y] == 1 && a[x + 1][y + 1] == 1 && a[x][y + 1] == 1 &&
        flag != 1) {
      res = i;
      flag = 1;
    } else if (a[x - 1][y] == 1 && a[x - 1][y - 1] == 1 && a[x][y - 1] == 1 &&
               flag != 1) {
      res = i;
      flag = 1;
    } else if (a[x + 1][y] == 1 && a[x + 1][y - 1] == 1 && a[x][y - 1] == 1 &&
               flag != 1) {
      res = i;
      flag = 1;
    } else if (a[x - 1][y] == 1 && a[x - 1][y + 1] == 1 && a[x][y + 1] == 1 &&
               flag != 1) {
      res = i;
      flag = 1;
    }
  }
  cout << res;
}
