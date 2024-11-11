#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, pos, l, r, d, e, c = 0;
  cin >> n >> pos >> l >> r;
  if (l == 1 && r == n)
    cout << 0;
  else {
    if (l == 1) {
      if (pos > r)
        c = c + pos - r;
      else
        c = c + r - pos;
      c++;
      cout << c;
      return 0;
    }
    if (r == n) {
      if (pos < l)
        c = c + l - pos;
      else
        c = c + pos - l;
      c++;
      cout << c;
      return 0;
    }
    if (pos > r) {
      c = c + pos - r;
      c++;
      c = c + r - l;
      c++;
      cout << c;
      return 0;
    }
    if (pos < l) {
      c = c + l - pos;
      c++;
      c = c + r - l;
      c++;
      cout << c;
      return 0;
    }
    if ((r - pos) > (pos - l)) {
      c = c + pos - l;
      c++;
      c = c + r - l;
      c++;
      cout << c;
    } else {
      c = c + r - pos;
      c++;
      c = c + r - l;
      c++;
      cout << c;
    }
  }
  return 0;
}
