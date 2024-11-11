#include <bits/stdc++.h>
using namespace std;
int main() {
  char ch, white = 0, black = 0;
  for (int i = 0; i < 64; i++) {
    cin >> ch;
    if (ch >= 'a' && ch <= 'z') {
      if (ch == 'q') black += 9;
      if (ch == 'r') black += 5;
      if (ch == 'b' || ch == 'n') black += 3;
      if (ch == 'p') black += 1;
    }
    if (ch >= 'A' && ch <= 'Z') {
      if (ch == 'Q') white += 9;
      if (ch == 'R') white += 5;
      if (ch == 'B' || ch == 'N') white += 3;
      if (ch == 'P') white += 1;
    }
  }
  if (black > white)
    cout << "Black";
  else if (black < white)
    cout << "White";
  else
    cout << "Draw";
  return 0;
}
