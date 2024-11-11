#include <bits/stdc++.h>
using namespace std;
int main() {
  string s[8];
  for (int i = 0; i < 8; i++) cin >> s[i];
  int mx = 0, mn = 8;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      int k;
      if (s[i][j] == 'B') {
        for (k = i; k < 8 && s[k][j] != 'W'; k++)
          ;
        if (k == 8 && i > mx) mx = i;
      } else if (s[i][j] == 'W') {
        for (k = 0; k < i && s[k][j] != 'B'; k++)
          ;
        if (k == i && i < mn) mn = i;
      }
    }
  }
  if (7 - mx < mn)
    cout << "B";
  else
    cout << "A";
  return 0;
}
