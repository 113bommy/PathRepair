#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, q;
  cin >> n >> q;
  int a[3][n + 1];
  int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j <= n; j++) a[i][j] = 0;
  }
  int c = 0;
  int x, y;
  for (i = 0; i < q; i++) {
    cin >> x >> y;
    if (a[x][y] == 1) {
      a[x][y] = 0;
      if (x == 1) {
        if (a[2][y] == 1) c--;
        if (a[2][y - 1] == 1 && y - 1 >= 1) c--;
        if (a[2][y + 1] == 1 && y + 1 <= n) c--;
      } else {
        if (a[1][y] == 1) c--;
        if (a[1][y - 1] == 1 && y - 1 >= 1) c--;
        if (a[1][y + 1] == 1 && y + 1 <= n) c--;
      }
    } else {
      a[x][y] = 1;
      if (x == 1) {
        if (a[2][y] == 1) c++;
        if (a[2][y - 1] == 1 && y - 1 >= 1) c++;
        if (a[2][y + 1] == 1 && y + 1 <= n) c++;
      } else {
        if (a[1][y] == 1) c++;
        if (a[1][y - 1] == 1 && y - 1 >= 1) c++;
        if (a[1][y + 1] == 1 && y + 1 <= n) c++;
      }
    }
    if (c >= 1)
      cout << "No\n";
    else {
      if (a[2][n] == 0 && a[1][1] == 0)
        cout << "Yes\n";
      else
        cout << "No\n";
    }
  }
}
