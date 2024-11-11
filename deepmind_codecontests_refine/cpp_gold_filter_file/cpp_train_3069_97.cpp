#include <bits/stdc++.h>
using namespace std;
int main() {
  int black = 0, white = 0;
  for (int i = 1; i <= 64; i++) {
    char a;
    cin >> a;
    if (a == '.' || a == 'k' || a == 'K')
      continue;
    else if (a == 'q')
      black += 9;
    else if (a == 'r')
      black += 5;
    else if (a == 'b' || a == 'n')
      black += 3;
    else if (a == 'p')
      black += 1;
    else if (a == 'Q')
      white += 9;
    else if (a == 'R')
      white += 5;
    else if (a == 'B' || a == 'N')
      white += 3;
    else
      white += 1;
  }
  if (black > white)
    cout << "Black";
  else if (black == white)
    cout << "Draw";
  else
    cout << "White";
  return 0;
}
