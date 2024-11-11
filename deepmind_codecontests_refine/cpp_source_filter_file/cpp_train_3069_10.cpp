#include <bits/stdc++.h>
using namespace std;
char arr[8][8];
int i, j;
int tetri, shavi;
int main() {
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      cin >> arr[i][j];
    }
  }
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      if (arr[i][j] == 'Q') tetri += 9;
      if (arr[i][j] == 'q') shavi += 9;
      if (arr[i][j] == 'R') tetri += 5;
      if (arr[i][j] == 'r') shavi += 5;
      if (arr[i][j] == 'B') tetri += 3;
      if (arr[i][j] == 'b') shavi += 3;
      if (arr[i][j] == 'N') tetri += 3;
      if (arr[i][j] == 'n') shavi += 3;
      if (arr[i][j] == 'P') tetri += 1;
      if (arr[i][j] == 'p') shavi += 1;
    }
  }
  if (tetri > shavi) cout << "White" << endl;
  if (tetri < shavi) cout << "Black" << endl;
  if (tetri = shavi) cout << "Draw" << endl;
  return 0;
}
