#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, l, r, c, pl, pr, cl, cr;
  cin >> a >> b >> l >> r;
  c = a + b;
  cl = --l / c;
  cr = --r / c;
  pl = l % c;
  pr = r % c;
  if (cl == cr) {
    if (pl < a && pr < a) {
      cout << pr - pl + 1 << endl;
    } else if (pl < a && pr >= a) {
      cout << a - pl << endl;
    } else {
      cout << 1 << endl;
    }
  } else if (a <= b) {
    if (cl < cr - 1) {
      cout << a + 1 << endl;
    } else {
      if (pr >= a) {
        cout << a + 1 << endl;
      } else {
        if (pl >= a) {
          cout << pr + 1 + 1 << endl;
        } else {
          int x = a - pl;
          int y = pr + 1;
          cout << min(a, x + y) + (y == a);
        }
      }
    }
  } else {
    int d = a - b;
    if (cl == cr - 1) {
      cout << max(1, min(d, a - pl)) + min(a, pr + 1);
    } else if (cl == cr - 2) {
      cout << a + max(1, d + min(0, pr - a + 1 + max(0, a - pl)));
    } else {
      cout << a + d;
    }
  }
}
