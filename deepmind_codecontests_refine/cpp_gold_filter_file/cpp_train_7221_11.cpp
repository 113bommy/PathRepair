#include <bits/stdc++.h>
using namespace std;
int main() {
  int board[5][5];
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      int x;
      cin >> x;
      board[j][i] = x;
    }
  }
  int y = 0;
  int z = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (board[i][j] == 1) {
        y = i;
        z = j;
      }
    }
  }
  cout << abs(2 - y) + abs(2 - z) << endl;
}
