#include <bits/stdc++.h>
using namespace std;
int main(int argv, char** argc) {
  vector<string> board(8);
  string tmp;
  int black = 0;
  int white = 0;
  for (int i = 0; i < 8; i++) {
    cin >> tmp;
    for (int j = 0; j < 8; j++) {
      switch (tmp[j]) {
        case 'q':
          black += 9;
          break;
        case 'Q':
          white += 9;
          break;
        case 'r':
          black += 5;
          break;
        case 'R':
          white += 5;
          break;
        case 'b':
          black += 3;
          break;
        case 'B':
          white += 3;
          break;
        case 'k':
          black += 3;
          break;
        case 'K':
          white += 3;
          break;
        case 'p':
          black += 1;
          break;
        case 'P':
          white += 1;
          break;
        default:
          break;
      }
    }
  }
  if (black > white)
    cout << "Black";
  else if (white > black)
    cout << "White";
  else
    cout << "Draw";
}
