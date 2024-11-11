#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, c, x = 0, y = 0, z = 0;
  cin >> r >> c;
  char a[r][c];
  for (int i = 0; i < c; i++) {
    x = 0;
    for (int j = 0; j < r; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'S' || a[i][j] == 's') x = 1;
    }
    if (x == 0) y++;
  }
  for (int j = 0; j < r; j++) {
    x = 0;
    for (int i = 0; i < c; i++) {
      if (a[i][j] == 'S' || a[i][j] == 's') x = 1;
    }
    if (x == 0) z++;
  }
  cout << (y * r) + (z * c) - (y * z);
}
