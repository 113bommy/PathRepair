#include <bits/stdc++.h>
using namespace std;
int main() {
  string str[8];
  int w = 0, b = 0;
  for (int i = 0; i < 8; i++) cin >> str[i];
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < str[i].size(); j++) {
      if (str[i][j] >= 'a' && str[i][j] <= 'z') {
        switch (str[i][j]) {
          case 'q':
            b += 9;
            break;
          case 'r':
            b += 5;
            break;
          case 'b':
            b += '3';
            break;
          case 'n':
            b += 3;
            break;
          case 'p':
            b += 1;
            break;
        }
      } else if (str[i][j] >= 'A' && str[i][j] <= 'Z') {
        switch (str[i][j]) {
          case 'Q':
            w += 9;
            break;
          case 'R':
            w += 5;
            break;
          case 'B':
            w += '3';
            break;
          case 'N':
            w += 3;
            break;
          case 'P':
            w += 1;
            break;
        }
      }
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
