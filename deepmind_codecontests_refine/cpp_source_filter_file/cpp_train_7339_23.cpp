#include <bits/stdc++.h>
using namespace std;
int main() {
  char chess[8][8];
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) cin >> chess[i][j];
  }
  int movesA = 8;
  int movesB = 8;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (chess[j][i] == 'B') break;
      if (chess[j][i] == 'W') {
        if (movesA > j) movesA = j;
        break;
      }
    }
    for (int j = 7; j >= 0; j--) {
      if (chess[j][i] == 'W') break;
      if (chess[j][i] == 'B') {
        if (movesB > 7 - j) movesB = 7 - j;
        break;
      }
    }
  }
  if (movesA < movesB)
    cout << "A" << endl;
  else
    cout << "B" << endl;
}
