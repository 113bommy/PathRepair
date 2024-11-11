#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  ;
  int n, i;
  cin >> n;
  int t1 = 0, t2 = 1023;
  for (i = 0; i < n; i++) {
    char op;
    int con;
    cin >> con;
    cin >> op;
    if (op == '&') {
      t1 &= con;
      t2 &= con;
    }
    if (op == '|') {
      t1 |= con;
      t2 |= con;
    }
    if (op == '^') {
      t1 ^= con;
      t2 ^= con;
    }
  }
  if (t1 == 0 && t2 == 1023) {
    cout << 0 << endl;
  } else {
    int an = 1023, o = 0, x = 0;
    for (i = 0; i < 10; i++) {
      int b1 = ((t1 >> i) & 1);
      int b2 = ((t2 >> i) & 1);
      if (b1 == 0 && b2 == 0) {
        an -= (1 << i) - 1;
      }
      if (b1 == 1 && b2 == 1) {
        o += (1 << i);
      }
      if (b1 == 1 && b2 == 0) {
        x += (1 << i);
      }
    }
    cout << 3 << endl;
    cout << "& " << an << endl;
    cout << "| " << o << endl;
    cout << "^ " << x << endl;
  }
  return 0;
}
