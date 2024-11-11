#include <bits/stdc++.h>
using namespace std;
int r1, r2, c1, c2, d1, d2, a = 1, b, c, d;
int main() {
  ios::sync_with_stdio(0);
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
  while (a <= 9) {
    b = 1;
    while (b <= 9) {
      if (a == b) {
        b++;
        continue;
      }
      c = 1;
      while (c <= 9) {
        if (c == b || c == a) {
          c++;
          continue;
        }
        d = 1;
        while (d <= 9) {
          if (c == d || d == b || d == a) {
            d++;
            continue;
          }
          if (a + b == r1 && c + d == r2 && a + c == c1 && b + d == c2 &&
              a + d == d1 && b + c == d2) {
            return cout << a << " " << b << endl << c << " " << d << endl, 0;
          }
          d++;
        }
        c++;
      }
      b++;
    }
    a++;
  }
  cout << -1 << endl;
  return 0;
}
