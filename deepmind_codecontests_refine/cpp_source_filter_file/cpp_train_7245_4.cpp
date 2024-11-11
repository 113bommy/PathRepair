#include <bits/stdc++.h>
using namespace std;
char a[11][11];
int main() {
  int i, j, x, y, ok = 0, da, unul;
  for (i = 1; i <= 10; i++)
    for (j = 1; j <= 10; j++) cin >> a[i][j];
  for (i = 1; (i <= 10) && (!ok); i++)
    for (j = 1; (j <= 10) && (!ok); j++) {
      unul = 0;
      da = 1;
      x = i;
      for (y = j; y <= j + 4; y++)
        if ((y > 10) || (a[x][y] != 'X')) {
          if ((!unul) && (a[x][y] == '.'))
            unul++;
          else {
            da = 0;
            break;
          }
        }
      if (da) {
        ok = 1;
        break;
      }
      unul = 0;
      da = 1;
      y = j;
      for (x = i; x <= i + 4; x++)
        if ((x > 10) || (a[x][y] != 'X')) {
          if ((!unul) && (a[x][y] == '.'))
            unul++;
          else {
            da = 0;
            break;
          }
        }
      if (da) {
        ok = 1;
        break;
      }
      unul = 0;
      int k;
      da = 1;
      x = i;
      y = j;
      for (k = 1; k <= 4; k++)
        if ((x - k < 1) || (y + k > 10) || (a[x - k][y + k] != 'X')) {
          if ((!unul) && (a[x - k][y + k] == '.'))
            unul++;
          else {
            da = 0;
            break;
          }
        }
      if (da) {
        ok = 1;
        break;
      }
      unul = 0;
      da = 1;
      x = i;
      y = j;
      for (k = 1; k <= 4; k++)
        if ((x + k > 10) || (y + k > 10) || (a[x + k][y + k] != 'X')) {
          if ((!unul) && (a[x + k][y + k] == '.'))
            unul++;
          else {
            da = 0;
            break;
          }
        }
      if (da) {
        ok = 1;
        break;
      }
    }
  if (ok)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
