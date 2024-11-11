#include <bits/stdc++.h>
using namespace std;
char a[9];
int wo, wx, co, cx;
int main() {
  for (int i = 0; i < 9; i++) {
    cin >> a[i];
    if (a[i] == '0') co++;
    if (a[i] == 'X') cx++;
  }
  for (int i = 0; i < 3; i++) {
    if (a[3 * i] == '0' && a[3 * i + 1] == '0' && a[3 * i + 2] == '0' ||
        a[i] == '0' && a[i + 3] == '0' && a[i + 6] == '0' ||
        a[0] == '0' && a[4] == '0' && a[8] == '0' ||
        a[2] == '0' && a[4] == '0' && a[6] == '0')
      wo = 1;
    if (a[3 * i] == 'X' && a[3 * i + 1] == 'X' && a[3 * i + 2] == 'X' ||
        a[i] == 'X' && a[i + 3] == 'X' && a[i + 6] == 'X' ||
        a[0] == 'X' && a[4] == 'X' && a[8] == 'X' ||
        a[2] == 'X' && a[4] == 'X' && a[6] == 'X')
      wx = 1;
  }
  if ((wx && cx != co + 1) || (wo && cx != co) || (cx != co + 1 && cx != co))
    cout << "illegal";
  else if (wx)
    cout << "the first player won";
  else if (wo)
    cout << "the second player won";
  else if (cx + co == 9)
    cout << "draw";
  else if (cx == co)
    cout << "first";
  else
    cout << "second";
  return 0;
}
