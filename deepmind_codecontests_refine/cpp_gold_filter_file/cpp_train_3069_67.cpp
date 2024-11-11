#include <bits/stdc++.h>
using namespace std;
int main() {
  int black, white, i, j;
  char input;
  black = white = 0;
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      cin >> input;
      if (input == 'Q') white = white + 9;
      if (input == 'q') black = black + 9;
      if (input == 'R') white = white + 5;
      if (input == 'r') black = black + 5;
      if (input == 'B' || input == 'N') white = white + 3;
      if (input == 'b' || input == 'n') black = black + 3;
      if (input == 'P') white++;
      if (input == 'p') black++;
    }
  }
  if (black > white)
    cout << "Black";
  else if (white > black)
    cout << "White";
  else
    cout << "Draw";
  return 0;
}
