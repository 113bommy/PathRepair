#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[10][10];
  int i, j, x = 0, y = 0;
  for (i = 0; i < 8; i++) cin >> a[i];
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      if (a[i][j] == 'B') {
        x++;
      }
    }
    if (x == 8) y++;
    x = 0;
  }
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      if (a[j][i] == 'B') {
        x++;
      }
    }
    if (x == 8) y++;
    x = 0;
  }
  if (y > 8)
    cout << 8;
  else
    cout << y;
  return 0;
}
