#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if (n == 2) {
    cout << 2 << ' ' << 1 << ' ' << 2;
    fflush(stdout);
    return 0;
  }
  int x1 = 1;
  int x2 = n;
  int h;
  while (x1 < x2) {
    cout << 1 << ' ' << (x1 + x2) / 2 << ' ' << (x1 + x2) / 2 + 1 << endl;
    fflush(stdout);
    string t;
    cin >> t;
    if (t == "NIE") {
      x1 = (x1 + x2) / 2 + 1;
    } else {
      x2 = (x1 + x2) / 2;
    }
  }
  h = x2;
  x1 = 1;
  x2 = h;
  while (x1 < x2) {
    cout << 1 << ' ' << (x1 + x2 - 1) / 2 << ' ' << (x1 + x2 - 1) / 2 + 1
         << endl;
    fflush(stdout);
    string t;
    cin >> t;
    if (t == "NIE") {
      x1 = (x1 + x2 - 1) / 2 + 1;
    } else {
      x2 = (x1 + x2 - 1) / 2;
    }
  }
  if (x2 != h) {
    cout << 2 << ' ' << x2 << ' ' << h << endl;
    fflush(stdout);
    return 0;
  }
  x1 = h + 1;
  x2 = n;
  while (x1 < x2) {
    cout << 1 << ' ' << (x1 + x2) / 2 + 1 << ' ' << (x1 + x2) / 2 << endl;
    fflush(stdout);
    string t;
    cin >> t;
    if (t == "NIE") {
      x2 = (x1 + x2) / 2;
    } else {
      x1 = (x1 + x2) / 2 + 1;
    }
  }
  cout << 2 << ' ' << x2 << ' ' << h << endl;
  fflush(stdout);
}
