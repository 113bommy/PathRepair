#include <bits/stdc++.h>
using namespace std;
string board[8];
int main() {
  for (int i = 0; i < 8; i++) cin >> board[i];
  int w = 0, b = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (board[i][j] == 'Q') w += 9;
      if (board[i][j] == 'R') w += 5;
      if (board[i][j] == 'B') w += 3;
      if (board[i][j] == 'N') w += 3;
      if (board[i][j] == 'P') w += 1;
      if (board[i][j] == 'q') b += 9;
      if (board[i][j] == 'r') b += 5;
      if (board[i][j] == 'b') b += 3;
      if (board[i][j] == 'b') b += 3;
      if (board[i][j] == 'p') b += 1;
    }
  }
  if (w > b)
    cout << "White" << endl;
  else if (w < b)
    cout << "Black" << endl;
  else
    cout << "Draw" << endl;
  return 0;
}
