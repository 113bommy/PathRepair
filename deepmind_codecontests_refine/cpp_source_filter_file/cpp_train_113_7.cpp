#include <bits/stdc++.h>
using namespace std;
int main() {
  bool same[50];
  int k = 29, c = 0, d = 0, a = 0, b = 0;
  int s;
  cout << "?" << ' ' << c << ' ' << d << endl;
  fflush(stdout);
  cin >> s;
  int last = s;
  while (k >= 0) {
    if (last == 0) {
      while (k >= 0) {
        same[k] = true;
        k--;
      }
      break;
    }
    cout << "?" << ' ' << c + (1 << k) << ' ' << d + (1 << k) << endl;
    fflush(stdout);
    cin >> s;
    if (s == last) {
      same[k] = true;
    } else {
      same[k] = false;
      if (s == 1) {
        a += 0;
        b += (1 << k);
        c += 0;
        d += (1 << k);
      } else if (s == -1) {
        a += (1 << k);
        b += 0;
        c += (1 << k);
        d += 0;
      }
      cout << "?" << ' ' << c << ' ' << d << endl;
      fflush(stdout);
      cin >> last;
    }
    k--;
  }
  k = 29;
  while (k >= 0) {
    if (!same[k]) {
      k--;
      continue;
    }
    cout << "?" << ' ' << c + (1 << k) << ' ' << d << endl;
    fflush(stdout);
    cin >> s;
    if (s == 1) {
      a += 0;
      b += 0;
    } else {
      a += (1 << k);
      b += (1 << k);
    }
    k--;
  }
  cout << "?" << ' ' << a << ' ' << b << endl;
  fflush(stdout);
  return 0;
}
