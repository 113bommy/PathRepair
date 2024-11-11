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
          int left = a - pl;
          int right = pr + 1;
          if (left + right > a) {
            cout << a + (right == a) << endl;
          } else {
            cout << left + right + (right == a) << endl;
          }
        }
      }
    }
  } else {
    int d = a - b;
    if (cl == cr - 1) {
      if (pr >= a && pl >= a) {
        cout << a + 1 << endl;
      } else if (pr < a && pl >= a) {
        cout << pr + 1 + 1 << endl;
      } else if (pr >= a && pl < a) {
        cout << min((a + a - pl), a + a - b) << endl;
      } else if (pr < a && pl < a) {
        if (pl > b) {
          cout << pr + 1 + a - pl << endl;
        } else {
          cout << pr + 1 + a - b << endl;
        }
      }
    } else if (cl == cr - 2) {
      if (pr >= a && pl >= a) {
        cout << a + a - b << endl;
      } else if (pr < a && pl >= a) {
        cout << a + a - b << endl;
      } else {
        cout << a + max(1, d + min(0, pr - a + 1 + max(0, a - pl)));
      }
    } else {
      cout << a + d;
    }
  }
}
