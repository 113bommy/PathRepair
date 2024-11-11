#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, c = 0, b = 0;
  char a[8][8];
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      cin >> a[i][j];
    }
  }
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      if (a[i][j] == 'Q') c = c + 8;
      if (a[i][j] == 'R') c = c + 5;
      if (a[i][j] == 'B') c = c + 3;
      if (a[i][j] == 'N') c = c + 3;
      if (a[i][j] == 'P') c = c + 1;
      if (a[i][j] == 'q') b = b + 8;
      if (a[i][j] == 'r') b = b + 5;
      if (a[i][j] == 'b') b = b + 3;
      if (a[i][j] == 'n') b = b + 3;
      if (a[i][j] == 'p') b = b + 1;
    }
  }
  if (c > b) cout << "White";
  if (c < b) cout << "Black";
  if (c == b) cout << "Draw";
}
