#include <bits/stdc++.h>
using namespace std;
bool letters[125];
int main() {
  string s;
  int white = 0, black = 0;
  for (int i = 0; i < 8; i++) {
    cin >> s;
    for (int j = 0; j < 8; j++) {
      if (s[j] != '.') {
        if (s[j] == 'Q') white += 9;
        if (s[j] == 'R') white += 5;
        if (s[j] == 'B') white += 3;
        if (s[j] == 'K') white += 3;
        if (s[j] == 'P') white += 1;
        if (s[j] == 'q') black += 9;
        if (s[j] == 'r') black += 5;
        if (s[j] == 'b') black += 3;
        if (s[j] == 'k') black += 3;
        if (s[j] == 'p') black += 1;
      }
    }
  }
  if (white > black) cout << "White";
  if (white < black) cout << "Black";
  if (white == black) cout << "Draw";
  return 0;
}
