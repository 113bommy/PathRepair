#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, i, k, n, x[1005], y[1005];
int main() {
  for (cin >> n; ++i < n;) {
    cout << "? " << i + 1 << " " << 1 << " " << n << " " << n << endl;
    fflush(stdout);
    cin >> x[i + 1];
    cout << "? " << 1 << " " << i + 1 << " " << n << " " << n << endl;
    fflush(stdout);
    cin >> y[i + 1];
  }
  for (i = 0; i++ < n;) {
    if (x[i] + x[i + 1] & 1) {
      if (a)
        c = i;
      else
        a = i;
    }
    if (y[i] + y[i + 1] & 1) {
      if (b)
        d = i;
      else
        b = i;
    }
  }
  if (a && b) {
    cout << "? " << a << " " << b << " " << a << " " << b << endl;
    fflush(stdout);
    cin >> k;
    if (k)
      cout << "! " << a << " " << b << " " << c << " " << d;
    else
      cout << "! " << a << " " << d << " " << c << " " << b;
    fflush(stdout);
  } else if (a) {
    for (b = 1, d = n; b < d;) {
      cout << "? " << a << " " << b << " " << a << " " << (b + d) / 2 << endl;
      fflush(stdout);
      cin >> k;
      if (k % 2)
        d = (b + d) / 2;
      else
        b = (b + d) / 2 + 1;
    }
    cout << "! " << a << " " << b << " " << c << " " << b;
    fflush(stdout);
  } else {
    for (a = 1, c = n; a < c;) {
      cout << "? " << a << " " << b << " " << (a + c) / 2 << " " << b << endl;
      fflush(stdout);
      cin >> k;
      if (k % 2)
        c = (a + c) / 2;
      else
        a = (a + c) / 2 + 1;
    }
    cout << "! " << a << " " << b << " " << a << " " << d;
    fflush(stdout);
  }
}
