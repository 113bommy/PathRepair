#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  char ch[4][22];
  for (int i = 1; i < 22; i++) ch[2][i] = '.';
  ch[2][0] = '#';
  for (int i = 0; i < 4; i++) {
    if (i == 2) continue;
    for (int j = 0; j < 22; j++) {
      if (j & 1)
        ch[i][j] = '.';
      else
        ch[i][j] = '#';
    }
  }
  for (int j = 0; j < 22; j++) {
    for (int i = 0; i < 4; i++) {
      if (k == 0) break;
      if (ch[i][j] == '.')
        continue;
      else {
        ch[i][j] = 'O';
        k--;
      }
    }
  }
  cout << "+------------------------+\n";
  for (int i = 0; i < 4; i++) {
    cout << "|";
    for (int j = 0; j < 22; j++) cout << ch[i][j];
    if (i == 0)
      cout << "|D|)\n";
    else if (i == 1)
      cout << "|.|\n";
    else if (i == 2)
      cout << "..|\n";
    else
      cout << "|.|)\n";
  }
  cout << "+------------------------+";
  return 0;
}
