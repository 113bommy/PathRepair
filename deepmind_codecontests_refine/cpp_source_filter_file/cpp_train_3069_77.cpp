#include <bits/stdc++.h>
using namespace std;
int main() {
  unordered_map<char, int> m;
  m['q'] = 9;
  m['r'] = 5;
  m['b'] = 3;
  m['k'] = 3;
  m['p'] = 1;
  m['Q'] = 9;
  m['R'] = 5;
  m['B'] = 3;
  m['K'] = 3;
  m['P'] = 1;
  long long cw = 0, cb = 0;
  string s[8];
  for (int i = 0; i < 8; i++) cin >> s[i];
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (s[i][j] != '.') {
        if (s[i][j] >= 'A' && s[i][j] <= 'Z')
          cw += m[s[i][j]];
        else
          cb += m[s[i][j]];
      }
    }
  }
  if (cw > cb)
    cout << "White";
  else if (cb > cw)
    cout << "Black";
  else
    cout << "Draw";
}
