#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, v = 0;
  bool b = 0;
  cin >> x;
  for (int i = 0; i < x; i++) {
    if (!(x % 2)) b = !b;
    for (int a = 0; a < x; a++) {
      if (b) {
        b = 0;
      } else {
        v++;
        b = 1;
      }
    }
  }
  cout << v << endl;
  for (int i = 0; i < x; i++) {
    if (!(x % 2)) b = !b;
    for (int a = 0; a < x; a++) {
      if (b) {
        cout << '.';
        b = 0;
      } else {
        cout << 'C';
        b = 1;
      }
    }
    cout << endl;
  }
  return 0;
}
