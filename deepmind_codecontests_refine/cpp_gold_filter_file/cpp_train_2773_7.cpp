#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, h, h1, h2, m, m1, m2, s;
  while (cin >> x) {
    cin >> h >> m;
    s = 0;
    h1 = h / 10;
    h2 = h % 10;
    m1 = m / 10;
    m2 = m % 10;
    while (!(h1 == 7 || h2 == 7 || m1 == 7 || m2 == 7)) {
      s++;
      m = m - x;
      if (m < 0) {
        m += 60;
        h--;
        h1 = h / 10;
        h2 = h % 10;
      }
      m1 = m / 10;
      m2 = m % 10;
      if (h < 0) {
        h += 24;
        h1 = h / 10;
        h2 = h % 10;
      }
    }
    cout << s << endl;
  }
}
