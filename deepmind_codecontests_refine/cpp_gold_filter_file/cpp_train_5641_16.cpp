#include <bits/stdc++.h>
using namespace std;
int main() {
  int b, p, f, i, t, profit = 0, minn = 0, h, c, maxx = 0;
  cin >> t;
  for (i = 1; i <= t; i++) {
    profit = 0;
    cin >> b >> p >> f;
    cin >> h >> c;
    if (b < 2) {
      cout << 0 << endl;
    } else if (h != c) {
      if (h > c) {
        if (b >= (2 * p)) {
          profit = p * h;
          b = (b - 2 * p);
          if (b >= 2) {
            if (b >= (2 * f)) {
              profit += f * c;
              cout << profit << endl;
            } else {
              profit += (b / 2) * c;
              cout << profit << endl;
            }
          } else {
            cout << profit << endl;
          }
        } else {
          profit += (b / 2) * h;
          cout << profit << endl;
        }
      } else if (h < c) {
        if (b >= (2 * f)) {
          profit = f * c;
          b = b - (2 * f);
          if (b >= 2) {
            if (b >= (2 * p)) {
              profit += p * h;
              cout << profit << endl;
            } else {
              profit += (b / 2) * h;
              cout << profit << endl;
            }
          } else {
            cout << profit << endl;
          }
        } else {
          profit += (b / 2) * c;
          cout << profit << endl;
        }
      }
    } else if (h == c) {
      if (b <= 2 * (p + f)) {
        profit = (b / 2) * c;
        cout << profit << endl;
      } else {
        profit = (p + f) * c;
        cout << profit << endl;
      }
    }
  }
}
