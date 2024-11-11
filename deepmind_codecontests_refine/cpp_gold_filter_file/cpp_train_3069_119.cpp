#include <bits/stdc++.h>
using namespace std;
int main() {
  int w, b;
  string s;
  w = b = 0;
  for (int t = 0; t < 8; t++) {
    cin >> s;
    for (int i = 0; i < 8; i++) {
      if (s[i] == 'Q')
        w = w + 9;
      else if (s[i] == 'R')
        w = w + 5;
      else if (s[i] == 'B' || s[i] == 'N')
        w = w + 3;
      else if (s[i] == 'P')
        w = w + 1;
      else if (s[i] == 'q')
        b = b + 9;
      else if (s[i] == 'r')
        b = b + 5;
      else if (s[i] == 'b' || s[i] == 'n')
        b = b + 3;
      else if (s[i] == 'p')
        b = b + 1;
    }
  }
  if (w > b)
    cout << "White" << endl;
  else if (w < b)
    cout << "Black" << endl;
  else
    cout << "Draw" << endl;
  return 0;
}
