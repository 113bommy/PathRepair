#include <bits/stdc++.h>
using namespace std;
int main() {
  int wh = 0, ba = 0, i, j;
  char x;
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      cin >> x;
      if (x == 'Q')
        wh += 9;
      else if (x == 'q')
        ba += 9;
      else if (x == 'R')
        wh += 5;
      else if (x == 'r')
        ba += 5;
      else if (x == 'K')
        wh += 3;
      else if (x == 'k')
        ba += 3;
      else if (x == 'B')
        wh += 3;
      else if (x == 'b')
        ba += 3;
      else if (x == 'P')
        wh += 1;
      else if (x == 'p')
        ba += 1;
    }
  }
  if (wh > ba)
    cout << "White" << endl;
  else if (wh < ba)
    cout << "Black" << endl;
  else if (wh == ba)
    cout << "Draw" << endl;
  return 0;
}
