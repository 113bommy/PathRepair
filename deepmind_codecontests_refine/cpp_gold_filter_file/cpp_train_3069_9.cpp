#include <bits/stdc++.h>
using namespace std;
int main() {
  int b = 0, w = 0;
  for (int i = 0; i < 8; i++) {
    char s[8];
    cin >> s;
    for (int j = 0; j < 8; j++) {
      switch (s[j]) {
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
          w += 1;
          break;
        case 'q':
          b += 9;
          break;
        case 'r':
          b += 5;
          break;
        case 'b':
          b += 3;
          break;
        case 'n':
          b += 3;
          break;
        case 'p':
          b += 1;
          break;
      }
    }
  }
  if (w == b)
    cout << "Draw";
  else if (w > b)
    cout << "White";
  else
    cout << "Black";
}
