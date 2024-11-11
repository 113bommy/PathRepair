#include <bits/stdc++.h>
using namespace std;
int main() {
  string s[8];
  int x = 0, y = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> s[i][j];
      if (s[i][j] == 'q') x += 9;
      if (s[i][j] == 'r') x += 5;
      if (s[i][j] == 'b') x += 3;
      if (s[i][j] == 'n') x += 3;
      if (s[i][j] == 'p') x += 1;
      if (s[i][j] == 'Q') y += 9;
      if (s[i][j] == 'R') y += 5;
      if (s[i][j] == 'B') y += 3;
      if (s[i][j] == 'N') y += 3;
      if (s[i][j] == 'P') y += 1;
    }
  }
  if (x == y)
    cout << "Draw";
  else if (x > y)
    cout << "Black";
  else
    cout << "White";
  return 0;
}
