#include <bits/stdc++.h>
using namespace std;
string grid[8];
int get_weight(char c) {
  switch (c) {
    case 'q':
      return 9;
    case 'r':
      return 5;
    case 'b':
    case 'n':
      return 3;
    case 'p':
      return 1;
    default:
      return 0;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  for (int i = 0; i < 8; ++i) cin >> grid[i];
  int black = 0, white = 0;
  for (int i = 0; i < 8; ++i)
    for (int j = 0; j < 8; ++j) {
      bool play1 = isupper(grid[i][j]);
      int score = get_weight(tolower(grid[i][j]));
      if (play1)
        black += score;
      else
        white += score;
    }
  if (black == white)
    cout << "Draw";
  else if (black > white)
    cout << "White";
  else
    cout << "Black";
  return 0;
}
