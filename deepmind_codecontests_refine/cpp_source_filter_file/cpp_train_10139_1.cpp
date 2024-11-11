#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, i, p, q, a, t;
  int b[2];
  for (i = 0; i < 2; i++) cin >> b[i];
  p = b[0];
  q = b[1];
  if (p % q == 0) {
    s = p / q;
    for (i = 0; i < s; i++) {
      cout << s;
      cout << ' ';
    }
  } else {
    while (p % q != 0) {
      a = p / q;
      p = p - a;
      q = q - 1;
      cout << a << ' ';
    }
    t = p / q;
    for (i = 0; i < q; i++) cout << t << " ";
  }
  return (0);
}
