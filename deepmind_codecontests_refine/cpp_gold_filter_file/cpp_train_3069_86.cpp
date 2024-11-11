#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[8][8];
  int sumw = 0, sumb = 0;
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      if (a[i][j] == 'Q')
        sumw = sumw + 9;
      else if (a[i][j] == 'R')
        sumw = sumw + 5;
      else if (a[i][j] == 'B')
        sumw = sumw + 3;
      else if (a[i][j] == 'N')
        sumw = sumw + 3;
      else if (a[i][j] == 'P')
        sumw = sumw + 1;
      else if (a[i][j] == 'K')
        sumw = sumw + 0;
      else if (a[i][j] == 'q')
        sumb = sumb + 9;
      else if (a[i][j] == 'r')
        sumb = sumb + 5;
      else if (a[i][j] == 'b')
        sumb = sumb + 3;
      else if (a[i][j] == 'n')
        sumb = sumb + 3;
      else if (a[i][j] == 'p')
        sumb = sumb + 1;
      else if (a[i][j] == 'k')
        sumb = sumb + 0;
    }
  }
  if (sumw > sumb)
    cout << "White";
  else if (sumb > sumw)
    cout << "Black";
  else if (sumb == sumw)
    cout << "Draw";
  return 0;
}
