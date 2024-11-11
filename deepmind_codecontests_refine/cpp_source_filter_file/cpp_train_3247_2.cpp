#include <bits/stdc++.h>
using namespace std;
int main() {
  long long q;
  cin >> q;
  bool *otw = new bool[q];
  for (long long qw = 0; qw < q; qw++) {
    otw[qw] = true;
  }
  for (long long qw = 0; qw < q; qw++) {
    long long n;
    cin >> n;
    bool *mas1 = new bool[n];
    bool *mas2 = new bool[n];
    for (long long i = 0; i < n; i++) {
      char c;
      cin >> c;
      (c == '1' || c == '2') ? mas1[i] = true : mas1[i] = false;
    }
    for (long long i = 0; i < n; i++) {
      char c;
      cin >> c;
      (c == '1' || c == '2') ? mas2[i] = true : mas2[i] = false;
    }
    long long x = 1;
    long long y = 1;
    long long last = 0;
    while (1) {
      if (y == 1) {
        if (mas1[x - 1]) {
          if (x == n) {
            otw[qw] = false;
            break;
          }
          if (last == x) {
            otw[qw] = false;
            break;
          } else {
            last = x;
            x++;
          }
        } else {
          if (last == x) {
            last = x;
            x++;
          } else {
            last = x;
            y = 2;
          }
        }
      } else {
        if (mas2[x - 1]) {
          if (last == x) {
            otw[qw] = false;
            break;
          } else {
            if (x = n) break;
            last = x;
            x++;
          }
        } else {
          if (last == x) {
            if (x == n) break;
            last = x;
            x++;
          } else {
            if (x == n) {
              otw[qw] = false;
              break;
            }
            last = x;
            y = 1;
          }
        }
      }
    }
  }
  for (long long qw = 0; qw < q; qw++) {
    cout << (otw[qw] ? "YES" : "NO") << endl;
  }
}
