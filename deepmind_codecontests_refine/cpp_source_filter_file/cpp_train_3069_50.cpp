#include <bits/stdc++.h>
using namespace std;
int main() {
  map<char, int> cn;
  cn['q'] = cn['Q'] = 9;
  cn['r'] = cn['R'] = 8;
  cn['B'] = cn['b'] = 3;
  cn['N'] = cn['n'] = 3;
  cn['p'] = cn['P'] = 1;
  int w = 0, b = 0;
  char x;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> x;
      if (x >= 65 && x <= 90) {
        w += cn[x];
      } else if (x >= 97 && x <= 122) {
        b += cn[x];
      }
    }
  }
  if (b > w) {
    cout << "Black";
  } else if (b == w) {
    cout << "Draw";
  } else {
    cout << "White";
  }
  return 0;
}
