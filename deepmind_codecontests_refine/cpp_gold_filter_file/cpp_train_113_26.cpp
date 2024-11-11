#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cout << "? 0 0\n";
  cin >> x;
  int a = 0, b = 0;
  int c = 0, d = 0;
  if (x == 0) {
    for (int i = 29; i >= 0; --i) {
      cout << "? " << (a ^ (1 << i)) << ' ' << b << "\n";
      cin >> x;
      if (x == -1) {
        a ^= (1 << i);
        b ^= (1 << i);
      }
    }
    cout << "! " << a << ' ' << b;
  } else {
    int y;
    int q = x;
    for (int i = 29; i >= 0; --i) {
      if (q == 1) {
        cout << "? " << a << ' ' << (b ^ (1 << i)) << "\n";
        cin >> x;
        cout << "? " << (a ^ (1 << i)) << ' ' << (b ^ (1 << i)) << "\n";
        cin >> y;
        if (x == -1) {
          if (y == -1) {
            q = -1;
            a ^= (1 << i);
          }
        } else if (x == 1) {
          if (y == -1) {
            a ^= (1 << i);
          } else if (y == 1) {
            a ^= (1 << i);
            b ^= (1 << i);
          }
        } else {
          a ^= (1 << i);
          q = 0;
        }
      } else if (q == 0) {
        cout << "? " << a << ' ' << (b ^ (1 << i)) << "\n";
        cin >> x;
        if (x == 1) {
          a ^= (1 << i);
          b ^= (1 << i);
        }
      } else {
        cout << "? " << (a ^ (1 << i)) << ' ' << b << "\n";
        cin >> x;
        cout << "? " << (a ^ (1 << i)) << ' ' << (b ^ (1 << i)) << "\n";
        cin >> y;
        if (x == 1) {
          if (y == 1) {
            q = 1;
            b ^= (1 << i);
          }
        } else if (x == -1) {
          if (y == 1) {
            b ^= (1 << i);
          } else if (y == -1) {
            a ^= (1 << i);
            b ^= (1 << i);
          }
        } else {
          b ^= (1 << i);
          q = 0;
        }
      }
    }
    cout << "! " << a << ' ' << b;
  }
}
