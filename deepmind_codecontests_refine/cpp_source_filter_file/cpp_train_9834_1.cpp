#include <bits/stdc++.h>
using namespace std;
int main() {
  short int k;
  unsigned int i, j;
  char M[5][12];
  cin >> k;
  for (j = 0; j < 11; j++) {
    for (i = 0; i < 4; i++) {
      if (k > 0 && ((j == 0 && i == 2) || (i != 2))) {
        M[i][j] = 'O';
        k--;
      } else if (i == 2 && j != 0) {
        M[i][j] = '.';
      } else
        M[i][j] = '#';
    }
  }
  cout << "+------------------------+ \n";
  for (i = 0; i < 4; i++) {
    cout << "|";
    for (j = 0; j < 11; j++) {
      cout << M[i][j] << ".";
    }
    if (i == 0) cout << "|D|)\n";
    if (i == 1) cout << "|.|\n";
    if (i == 2) cout << "..|\n";
    if (i == 3) cout << "|.|)\n";
  }
  cout << "+------------------------+ \n";
  return 0;
}
