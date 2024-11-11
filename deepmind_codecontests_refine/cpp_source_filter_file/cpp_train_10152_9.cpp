#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long l, r, x, s, d = 0;
  cin >> l >> r >> x;
  s = 1;
  do {
    if (l <= s) {
      d++;
      cout << s << " ";
    }
    if (s / r < x) break;
    s *= x;
  } while (s <= r);
  if (d == 0) cout << -1;
}
