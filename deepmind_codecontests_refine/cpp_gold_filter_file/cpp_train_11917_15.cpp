#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n, i, h, c, s;
  c = 0;
  s = 0;
  h = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    h = h + i;
    s = s + h;
    if (s <= n) {
      c = c + 1;
    } else {
      break;
    }
  }
  if (c == 1) {
    cout << c;
  } else {
    c = c - 1;
    cout << c;
  }
}
