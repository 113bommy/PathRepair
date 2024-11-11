#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  int st, it, exp;
  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> st >> it >> exp;
    if (st == it) {
      cout << (exp + 1) / 2 << endl;
      continue;
    }
    if (exp == 0) {
      if (st > it)
        cout << 1 << endl;
      else
        cout << 0 << endl;
    } else {
      if (st > it) {
        int y;
        if (it + exp - st >= 0) {
          y = (it + exp - st) / 2 + 1;
        } else
          y = 0;
        cout << exp - (y) + 1 << endl;
      } else {
        if (st + exp <= it)
          cout << 0 << endl;
        else {
          exp = st + exp - it - 1;
          st = it + 1;
          if (exp == 0)
            cout << 1 << endl;
          else {
            int y;
            if (it + exp - st >= 0) {
              y = (it + exp - st) / 2 + 1;
            } else
              y = 0;
            cout << exp - (y) + 1 << endl;
          }
        }
      }
    }
  }
  return 0;
}
