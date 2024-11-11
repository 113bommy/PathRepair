#include <bits/stdc++.h>
using namespace std;
int main() {
  char t[8][8];
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> t[i][j];
    }
  }
  int b = 0, w = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      switch (t[i][j]) {
        case 'q':
          w += 9;
          break;
        case 'r':
          w += 5;
          break;
        case 'b':
          w += 3;
          break;
        case 'k':
          w += 3;
          break;
        case 'p':
          w += 1;
          break;
        case 'Q':
          b += 9;
          break;
        case 'R':
          b += 5;
          break;
        case 'B':
          b += 3;
          break;
        case 'K':
          b += 3;
          break;
        case 'P':
          b += 1;
          break;
      }
    }
  }
  if (w > b) {
    cout << "Black" << endl;
  } else if (b > w) {
    cout << "White" << endl;
  } else {
    cout << "Draw" << endl;
  }
}
