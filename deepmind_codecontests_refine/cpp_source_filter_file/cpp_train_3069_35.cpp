#include <bits/stdc++.h>
using namespace std;
int main() {
  char c[8][8];
  int w = 0, b = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> c[i][j];
      if (c[i][j] != '.' && islower(c[i][j])) {
        if (c[i][j] == 'q')
          b += 9;
        else if (c[i][j] == 'r')
          b += 5;
        else if (c[i][j] == 'b')
          b += 3;
        else if (c[i][j] == 'k')
          b += 3;
        else if (c[i][j] == 'p')
          b += 1;
      } else if (c[i][j] != '.' && isupper(c[i][j])) {
        if (c[i][j] == 'Q')
          w += 9;
        else if (c[i][j] == 'R')
          w += 5;
        else if (c[i][j] == 'B')
          w += 3;
        else if (c[i][j] == 'K')
          w += 3;
        else if (c[i][j] == 'P')
          w += 1;
      }
    }
  }
  if (b > w)
    cout << "Black\n";
  else if (w > b)
    cout << "White\n";
  else
    cout << "Draw\n";
  return 0;
}
