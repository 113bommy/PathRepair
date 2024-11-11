#include <bits/stdc++.h>
using namespace std;
string s[8];
int main() {
  for (int i = 0; i < 8; i++) cin >> s[i];
  int w = 9, b = 9;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (s[j][i] != '.') {
        if (s[j][i] == 'W') {
          if (j < w) w = j;
        }
        break;
      }
    }
    for (int j = 7; j >= 0; j--) {
      if (s[j][i] != '.') {
        if (s[j][i] == 'B') {
          if (7 - j < b) b = 7 - j;
        }
        break;
      }
    }
  }
  if (w < b)
    cout << "A";
  else
    cout << "B";
  return 0;
}
