#include <bits/stdc++.h>
using namespace std;
int main() {
  map<char, int> mk;
  mk['q'] = 9;
  mk['Q'] = 9;
  mk['r'] = 5;
  mk['R'] = 5;
  mk['b'] = 3;
  mk['B'] = 3;
  mk['k'] = 3;
  mk['K'] = 3;
  mk['p'] = 1;
  mk['P'] = 1;
  int w = 0, b = 0;
  char var;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> var;
      if (var >= 'a' && var <= 'z') {
        b += mk[var];
      } else if (var >= 'A' && var <= 'Z') {
        w += mk[var];
      }
    }
  }
  if (w > b) {
    cout << "White\n";
  } else if (b > w) {
    cout << "Black\n";
  } else {
    cout << "Draw\n";
  }
  return 0;
}
