#include <bits/stdc++.h>
using namespace std;
int main() {
  int mna = 20, mnb = 20;
  char a[8][8];
  bool b[8];
  bool c[8];
  bool thereb = false, therew = false;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'W')
        b[j] = true;
      else if (a[i][j] == 'B')
        c[j] = true;
    }
  }
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (a[i][j] == 'W') {
        if (!c[j])
          mna = min(mna, i);
        else if (c[j]) {
          for (int k = 0; k < i; k++)
            if (a[k][j] == 'B') thereb = true;
          if (!thereb) mna = min(mna, i);
          thereb = false;
        }
      } else if (a[i][j] == 'B') {
        if (!b[j])
          mnb = min(mnb, 8 - i - 1);
        else if (b[j]) {
          for (int k = 7; k > i; k--)
            if (a[k][j] == 'W') therew = true;
          if (!therew) mnb = min(mnb, 8 - i - 1);
          therew = false;
        }
      }
    }
  }
  mna < mnb ? cout << "A" << endl : cout << "B" << endl;
  return 0;
}
