#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  long long a, b, m, i, max, min, c, p;
  cin >> q;
  while (q--) {
    cin >> a >> b >> m;
    if (a == b) {
      cout << "1 " << a << "\n";
      continue;
    }
    i = 2;
    min = a + 1;
    max = a + m;
    while (b > max) {
      ++i;
      min *= 2;
      max *= 2;
    }
    if (b < min) {
      cout << "-1\n";
    } else {
      cout << i << " " << a << " ";
      p = a;
      --i;
      while (--i) {
        a = p + 1;
        c = (max + min) / 2;
        if (b > c) {
          a += m - 1;
          min = c;
        } else
          max = c;
        cout << a << " ";
        p += a;
      }
      cout << b << "\n";
    }
  }
  return 0;
}
