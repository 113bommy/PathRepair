#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, x, y, f = 0, d = 3, l, a, b, c;
  a = b = c = 0;
  cin >> n;
  while (n--) {
    cin >> x;
    if (d == x) f = 1;
    if (x == 1) {
      if (d == 3)
        d = 2;
      else
        d = 3;
    } else if (x == 2) {
      if (d == 1)
        d = 3;
      else
        d = 1;
    } else {
      if (d == 1)
        d = 2;
      else
        d = 3;
    }
  }
  if (f == 1)
    cout << "NO";
  else
    cout << "YES";
}
