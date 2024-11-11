#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, x, j;
  char str[10], a[10][10];
  for (i = 0; i < 8; i++) {
    cin >> str;
    x = strlen(str);
    for (j = 0; j < x; j++) a[i][j] = str[j];
  }
  int sum1 = 0, sum2 = 0;
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      if (a[i][j] == 'Q')
        sum1 += 9;
      else if (a[i][j] == 'q')
        sum2 += 9;
      else if (a[i][j] == 'R')
        sum1 += 5;
      else if (a[i][j] == 'r')
        sum2 += 5;
      else if (a[i][j] == 'B')
        sum1 += 3;
      else if (a[i][j] == 'b')
        sum2 += 3;
      else if (a[i][j] == 'K')
        sum1 += 3;
      else if (a[i][j] == 'k')
        sum2 += 3;
      else if (a[i][j] == 'P')
        sum1 += 1;
      else if (a[i][j] == 'p')
        sum2 += 1;
    }
  }
  if (sum1 > sum2)
    cout << "White\n";
  else if (sum1 < sum2)
    cout << "Black\n";
  else if (sum1 == sum2)
    cout << "Draw\n";
  return 0;
}
