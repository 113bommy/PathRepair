#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, c, x = 0, y = 0, z = 0;
  cin >> r >> c;
  char a[r][c];
  for (int i = 0; i < r; i++) {
    x = 0;
    for (int j = 0; j < c; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'S' || a[i][j] == 's') x = 1;
    }
    if (x == 0) y++;
  }
  for (int j = 0; j < c; j++) {
    x = 0;
    for (int i = 0; i < r; i++) {
      if (a[i][j] == 'S' || a[i][j] == 's') x = 1;
    }
    if (x == 0) z++;
  }
  cout << (y * c) + (z * r) - (y * z);
}
