#include <bits/stdc++.h>
using namespace std;
int a[5][5];
int main() {
  for (int i = 1; i <= 4; i++)
    for (int j = 1; j <= 4; j++) cin >> a[i][j];
  bool flag = 0;
  for (int i = 1; i <= 4; i++) {
    int x = (i + 3) % 4;
    if (x == 0) x = 4;
    int y = (i + 1) % 4;
    if (y == 0) y = 4;
    int z = (i + 2) % 4;
    if (z == 0) z = 4;
    if (a[i][4] &&
        (a[z][2] || a[x][3] || a[y][1] || a[i][1] || a[i][2] || a[i][3]))
      flag = 1;
  }
  if (flag)
    cout << "YES";
  else
    cout << "NO";
}
