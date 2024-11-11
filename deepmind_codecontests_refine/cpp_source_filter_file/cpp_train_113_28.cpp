#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, x = 0, y = 0, res1, res2, nxt;
  cout << "? 0 0" << endl;
  cin >> nxt;
  for (i = 2; i >= 0; i--) {
    cout << "? " << x + (1 << i) << ' ' << y << endl;
    cin >> res1;
    cout << "? " << x << ' ' << y + (1 << i) << endl;
    cin >> res2;
    if (res1 == res2) {
      if (nxt == 1)
        x += 1 << i;
      else
        y += 1 << i;
      nxt = res1;
    }
    if (res1 < res2) {
      x += 1 << i;
      y += 1 << i;
    }
  }
  cout << "! " << x << ' ' << y;
  return 0;
}
