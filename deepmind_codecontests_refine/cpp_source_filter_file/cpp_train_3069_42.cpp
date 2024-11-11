#include <bits/stdc++.h>
using namespace std;
int main() {
  string s[8];
  int w = 0;
  int b = 0;
  for (int i = 0; i < 8; i++) {
    cin >> s[i];
    for (int j = 0; j < s[i].length(); j++) {
      if (s[i][j] <= 'Z' && s[i][j] >= 'A') {
        switch (s[i][j]) {
          case 'Q':
            w += 9;
            break;
          case 'R':
            w += 5;
            break;
          case 'B':
            w += 3;
            break;
          case 'N':
            w += 3;
            break;
          case 'P':
            w++;
            break;
        }
      }
      if (s[i][j] >= 'a' && s[i][j] <= 'z') {
        switch (s[i][j]) {
          case 'q':
            w += 9;
            break;
          case 'r':
            w += 5;
            break;
          case 'b':
            w += 3;
            break;
          case 'n':
            w += 3;
            break;
          case 'p':
            w++;
            break;
        }
      }
    }
  }
  if (w > b) {
    cout << "White";
  } else {
    if (b > w) {
      cout << "Black";
    } else {
      cout << "Draw";
    }
  }
}
