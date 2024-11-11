#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, p;
  while (cin >> n >> k >> p) {
    bool nono = false;
    if (k == 0) {
      nono = true;
    }
    if (n & 1) {
      n--;
      if (k) k--;
    }
    for (int i = 0; i < p; i++) {
      long long x;
      cin >> x;
      if (nono) {
        cout << '.';
      } else {
        if (x == n + 1) {
          cout << 'X';
        } else {
          if (((n - x) & 1) == 0) {
            if ((n - x) / 2 + 1 <= k) {
              cout << 'X';
            } else {
              cout << '.';
            }
          } else {
            if (k > n / 2) {
              if ((k - n / 2) <= (n - x + 1) / 2) {
                cout << 'X';
              } else {
                cout << '.';
              }
            } else {
              cout << '.';
            }
          }
        }
      }
    }
    cout << endl;
  }
  return 0;
}
