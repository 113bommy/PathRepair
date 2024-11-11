#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[65];
  while (cin >> a) {
    for (int j = 8; j < 64; j++) cin >> a[j];
    int white, black;
    white = black = 0;
    int i;
    for (i = 0; i < 64; i++) {
      if (a[i] == 'Q') white += 9;
      if (a[i] == 'R') white += 5;
      if (a[i] == 'B') white += 3;
      if (a[i] == 'K') white += 3;
      if (a[i] == 'P') white += 1;
      if (a[i] == 'q') black += 9;
      if (a[i] == 'r') black += 5;
      if (a[i] == 'b') black += 3;
      if (a[i] == 'k') black += 3;
      if (a[i] == 'p') black += 1;
    }
    if (black == white)
      cout << "Draw" << endl;
    else if (black > white)
      cout << "Black" << endl;
    else
      cout << "White" << endl;
  }
  return 0;
}
