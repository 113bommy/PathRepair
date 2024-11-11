#include <bits/stdc++.h>
using namespace std;
int main() {
  char Chess_Board[64];
  for (size_t i = 0; i < 64; ++i) {
    cin >> Chess_Board[i];
  }
  int white_Pieces = 0, black_Pieces = 0;
  for (size_t i = 0; i < 64; ++i) {
    if (Chess_Board[i] != '.' && Chess_Board[i] != '\0') {
      if (Chess_Board[i] == 'Q') {
        white_Pieces += 9;
      } else if (Chess_Board[i] == 'q') {
        black_Pieces += 9;
      } else if (Chess_Board[i] == 'r') {
        black_Pieces += 5;
      } else if (Chess_Board[i] == 'R') {
        white_Pieces += 5;
      } else if (Chess_Board[i] == 'B' || Chess_Board[i] == 'N') {
        white_Pieces += 3;
      } else if (Chess_Board[i] == 'b' || Chess_Board[i] == 'n') {
        black_Pieces += 3;
      } else if (Chess_Board[i] == 'p') {
        black_Pieces++;
      } else if (Chess_Board[i] == 'P') {
        white_Pieces++;
      } else {
      }
    } else {
    }
  }
  if (white_Pieces == black_Pieces) {
    cout << "Draw" << endl;
  } else if (white_Pieces > black_Pieces) {
    cout << "White" << endl;
  } else {
    cout << "Black" << endl;
  }
  return 0;
}
