#include <bits/stdc++.h>
using namespace std;
int a[10][10] = {0};
int main() {
  int i, j, min = 10, min1 = 10, l;
  char c;
  for (i = 1; i <= 8; i++)
    for (j = 1; j <= 8; j++) {
      cin >> c;
      if (c == 'W')
        a[i][j] = 1;
      else if (c == 'B')
        a[i][j] = 2;
    }
  for (i = 1; i <= 8; i++)
    for (i = 1; i <= 8; i++) {
      if (a[i][j] == 1) {
        for (l = i - 1; l >= 1; l--)
          if (a[l][j] != 0) break;
        if (l == 0 && min >= i - 1) min = i - 1;
      } else if (a[i][j] == 2) {
        for (l = i + 1; l <= 8; l++)
          if (a[l][j] != 0) break;
        if (l == 9 && min1 >= 8 - i) min1 = 8 - i;
      }
    }
  if (min > min1)
    cout << "B";
  else
    cout << "A";
}
