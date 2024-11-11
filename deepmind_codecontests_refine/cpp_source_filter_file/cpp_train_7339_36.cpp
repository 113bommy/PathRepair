#include <bits/stdc++.h>
using namespace std;
string s[8];
int main() {
  for (int i = 0; i < 8; i++) cin >> s[i];
  int x = 8, y = 0;
  for (int j = 0; j < 8; j++) {
    for (int i = 0; i < 8; i++)
      if (s[i][j] != '.') {
        if (s[i][j] == 'W') x = min(x, i);
        break;
      }
    for (int i = 7; i >= 0; i--)
      if (s[i][j] != '.') {
        if (s[i][j] == 'B') y = max(y, i);
        break;
      }
  }
  if (x <= 8 - y)
    cout << "A\n";
  else
    cout << "B\n";
  return 0;
}
