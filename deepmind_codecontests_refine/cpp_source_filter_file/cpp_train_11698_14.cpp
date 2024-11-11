#include <bits/stdc++.h>
using namespace std;
int a, b, x, y, op, ta, tb;
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> op >> x >> y;
    if (op == 1) {
      ta += 10;
      a += y;
    } else {
      tb += 10;
      b += x;
    }
  }
  if (a >= (ta >> 1))
    puts("LIVE");
  else
    puts("DEAD");
  if (b >= (tb >> 1))
    puts("LIVE");
  else
    puts("DEAD");
  return 0;
}
