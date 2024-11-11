#include <bits/stdc++.h>
using namespace std;
int main() {
  int w = 0, b = 0;
  string s;
  for (int i = 1; i <= 8; i++) {
    cin >> s;
    for (int j = 1; j <= 8; j++) {
      if (s[j] == 'Q')
        w += 9;
      else if (s[j] == 'R')
        w += 5;
      else if (s[j] == 'P')
        w += 1;
      else if (s[j] == 'N')
        w += 3;
      else if (s[j] == 'B')
        w += 3;
      else if (s[j] == 'q')
        b += 9;
      else if (s[j] == 'r')
        b += 5;
      else if (s[j] == 'p')
        b += 1;
      else if (s[j] == 'n')
        b += 3;
      else if (s[j] == 'b')
        b += 3;
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
