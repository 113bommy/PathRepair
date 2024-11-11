#include <bits/stdc++.h>
using namespace std;
int main() {
  char x[8][8];
  int i, j, w = 0, b = 0;
  for (i = 0; i < 8; i++)
    for (j = 0; j < 8; j++) {
      cin >> x[i][j];
      if (x[i][j] == 'q')
        b += 9;
      else if (x[i][j] == 'r')
        b += 5;
      else if (x[i][j] == 'n' || x[i][j] == 'b')
        b += 3;
      else if (x[i][j] == 'p')
        w++;
      else if (x[i][j] == 'Q')
        w += 9;
      else if (x[i][j] == 'R')
        w += 5;
      else if (x[i][j] == 'N' || x[i][j] == 'B')
        w += 3;
      else if (x[i][j] == 'P')
        w++;
    }
  if (w > b)
    cout << "White";
  else if (b > w)
    cout << "Black";
  else
    cout << "Draw";
}
