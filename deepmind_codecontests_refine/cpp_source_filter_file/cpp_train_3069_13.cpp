#include <bits/stdc++.h>
using namespace std;
int sc[26];
int main() {
  string s[8];
  for (int i = 0; i < 8; i++) cin >> s[i];
  sc['q' - 'a'] = 9;
  sc['r' - 'a'] = 5;
  sc['b' - 'a'] = 3;
  sc['n' - 'a'] = 3;
  sc['p' - 'a'] = 1;
  int sumw = 0, sumb = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (s[i][j] != '.' and s[i][j] != 'k' and s[i][j] != 'K') {
        if (s[i][j] < 'Z')
          sumw += sc[s[i][j] - 'A'];
        else
          sumb += sc[s[i][j] - 'a'];
      }
    }
  }
  if (sumw > sumb)
    cout << "White";
  else if (sumb < sumw)
    cout << "Black";
  else
    cout << "Draw";
}
