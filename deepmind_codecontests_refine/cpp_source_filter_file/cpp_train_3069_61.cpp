#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i, j, w = 0, b = 0, x;
  char ch;
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      cin >> ch;
      x = 0;
      if (ch >= 'a' && ch <= 'z') {
        if (ch == 'q')
          x = 9;
        else if (ch == 'r')
          x = 5;
        else if (ch == 'b')
          x = 3;
        else if (ch == 'k')
          x = 3;
        else if (ch == 'p')
          x = 1;
        b += x;
      } else if (ch >= 'A' && ch <= 'Z') {
        if (ch == 'Q')
          x = 9;
        else if (ch == 'R')
          x = 5;
        else if (ch == 'B')
          x = 3;
        else if (ch == 'K')
          x = 3;
        else if (ch == 'P')
          x = 1;
        w += x;
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
