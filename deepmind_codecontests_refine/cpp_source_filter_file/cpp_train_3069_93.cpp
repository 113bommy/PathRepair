#include <bits/stdc++.h>
using namespace std;
int main() {
  char a;
  int white = 0, black = 0;
  for (int i = 0; i < 64; i++) {
    cin >> a;
    switch (a) {
      case 81:
        white += 9;
        break;
      case 82:
        white += 5;
        break;
      case 66:
        white += 3;
        break;
      case 75:
        white += 3;
        break;
      case 80:
        white += 1;
        break;
      case 113:
        black += 9;
        break;
      case 114:
        black += 5;
        break;
      case 98:
        black += 3;
        break;
      case 107:
        black += 3;
        break;
      case 112:
        black += 1;
        break;
      default:
        break;
    }
  }
  if (white > black)
    cout << "White";
  else if (black > white)
    cout << "Black";
  else
    cout << "Draw";
  return 0;
}
