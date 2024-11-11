#include <bits/stdc++.h>
using namespace std;
int main() {
  string s[8];
  for (int i = 0; i < 8; i++) cin >> s[i];
  int cntw = 0, cntb = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (s[i][j] >= 'A' && s[i][j] <= 'Z') {
        if (s[i][j] == 'Q') cntw += 9;
        if (s[i][j] == 'R') cntw += 5;
        if (s[i][j] == 'B' || s[i][j] == 'K') cntw += 3;
        if (s[i][j] == 'P') cntw += 1;
      }
      if (s[i][j] >= 'a' && s[i][j] <= 'z') {
        if (s[i][j] == 'q') cntb += 9;
        if (s[i][j] == 'r') cntb += 5;
        if (s[i][j] == 'b' || s[i][j] == 'k') cntb += 3;
        if (s[i][j] == 'p') cntb += 1;
      }
    }
  }
  if (cntb > cntw) {
    cout << "Black";
    return 0;
  }
  if (cntw > cntb) {
    cout << "White";
    return 0;
  }
  cout << "Draw";
  return 0;
}
