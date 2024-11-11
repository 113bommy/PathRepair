#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int mi = 99999999;
    int aa, bb, cc;
    for (int i = 1; i <= 10000; ++i) {
      int m1 = 0;
      int m2 = 0;
      int x = sqrt(i);
      for (int j = 1; j <= x; ++j) {
        if (i % j == 0) {
          m1 = m2 = abs(b - i);
          int a1 = j;
          m1 += abs(a1 - a);
          int a2 = i / j;
          m2 += abs(a2 - a);
          int num = c / i;
          if (num == 0) num = 1;
          int c1 = (num + 1) * i;
          int c2 = num * i;
          int mc = c2;
          if (abs(mc - c) > abs(c1 - c)) {
            mc = c1;
          }
          m1 += abs(mc - c);
          m2 += abs(mc - c);
          if (m1 < mi) {
            aa = a1;
            bb = i;
            cc = mc;
            mi = m1;
          }
          if (m2 < mi) {
            aa = a2;
            bb = i;
            cc = mc;
            mi = m2;
          }
        }
      }
    }
    cout << mi << endl;
    cout << aa << " " << bb << " " << cc << endl;
  }
}
