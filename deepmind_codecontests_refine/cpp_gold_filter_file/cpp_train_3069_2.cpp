#include <bits/stdc++.h>
using namespace std;
int main() {
  int a = 0, b = 0;
  char c;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      c = getchar();
      if (c == 'q')
        a += 9;
      else if (c == 'r')
        a += 5;
      else if (c == 'b')
        a += 3;
      else if (c == 'n')
        a += 3;
      else if (c == 'p')
        a += 1;
      else if (c == 'Q')
        b += 9;
      else if (c == 'R')
        b += 5;
      else if (c == 'B')
        b += 3;
      else if (c == 'N')
        b += 3;
      else if (c == 'P')
        b += 1;
    }
    getchar();
  }
  if (a < b)
    cout << "White";
  else if (b < a)
    cout << "Black";
  else
    cout << "Draw";
}
