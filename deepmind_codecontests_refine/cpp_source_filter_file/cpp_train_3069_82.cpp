#include <bits/stdc++.h>
using namespace std;
int main() {
  int b = 0, w = 0;
  char ch;
  char chess[9];
  for (int i = 0; i < 8; i++) {
    cin >> chess;
    for (int j = 0; j < 8; j++) {
      ch = chess[i];
      if (ch == 'p') b = b + 1;
      if (ch == 'q') b = b + 9;
      if (ch == 'b') b = b + 3;
      if (ch == 'n') b = b + 3;
      if (ch == 'r') b = b + 5;
      if (ch == 'P') w = w + 1;
      if (ch == 'Q') w = w + 9;
      if (ch == 'B') w = w + 3;
      if (ch == 'N') w = w + 3;
      if (ch == 'R') w = w + 5;
    }
  }
  if (w > b)
    cout << "White";
  else if (b > w)
    cout << "Black";
  else
    cout << "Draw";
  return 0;
}
