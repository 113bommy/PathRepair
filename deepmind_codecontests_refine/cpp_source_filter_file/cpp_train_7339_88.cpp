#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[9][9], ch;
  int i, j, k, l, p, q, ans1 = 1 << 30, ans2 = 1 << 30;
  for (i = 1; i <= 8; i++)
    for (j = 1; j <= 8; j++) {
      ch = getchar();
      while (ch != '.' && ch != 'B' && ch != 'W') ch = getchar();
      a[i][j] = ch;
    }
  for (i = 1; i <= 8; i++)
    for (j = 1; j <= 8; j++) {
      bool ok = 1;
      if (a[i][j] == 'W') {
        for (k = 1; k <= i - 1; k++) {
          if (a[k][j] != '.') ok = 0;
        }
        if (ok) ans1 = min(ans1, i - 1);
      } else if (a[i][j] == 'B') {
        for (k = i + 1; k <= 8; k++) {
          if (a[k][j] != '.') ok = 0;
        }
        if (ok) ans2 = min(ans2, 8 - i);
      }
    }
  if (ans1 < ans2)
    cout << "A";
  else
    cout << "B";
}
