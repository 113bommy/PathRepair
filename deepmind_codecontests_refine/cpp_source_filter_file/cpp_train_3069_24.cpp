#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, w = 0, b = 0;
  char s;
  map<char, int> let;
  let['Q'] = 9;
  let['q'] = 9;
  let['R'] = 5;
  let['r'] = 5;
  let['B'] = 3;
  let['b'] = 3;
  let['N'] = 3;
  let['n'] = 3;
  let['P'] = 3;
  let['p'] = 3;
  let['K'] = 0;
  let['k'] = 0;
  let['.'] = 0;
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      cin >> s;
      if (s >= 'a')
        b = b + let[s];
      else
        w = w + let[s];
    }
  }
  if (w > b)
    cout << "White\n";
  else {
    if (w == b)
      cout << "Draw\n";
    else
      cout << "Black\n";
  }
  return 0;
}
