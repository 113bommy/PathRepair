#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, p, r;
  double a, d, x, y, L, d1;
  cin >> a >> d1;
  cin >> n;
  x = 0, y = 0, p = 0;
  for (i = 1; i <= n; i++) {
    d = d1;
    if (p == 0) {
      L = a - x;
      if (L > d) {
        p = 0;
        x = x + d;
      } else if (L == d) {
        x = a;
        p = 1;
      } else {
        d = d - L;
        p = 1;
        r = d / a;
        p = (p + r) % 4;
        d = d - r * a;
        if (p == 0) {
          p = 0;
          x = d;
          y = 0;
        } else if (p == 1) {
          p = 1;
          x = a;
          y = d;
        } else if (p == 2) {
          p = 2;
          x = a - d;
          y = a;
        } else {
          p = 3;
          x = 0;
          y = a - d;
        }
      }
    } else if (p == 1) {
      L = a - y;
      if (L > d) {
        p = 1;
        y = y + d;
      } else if (L == d) {
        y = a;
        p = 2;
      } else {
        d = d - L;
        p = 2;
        r = d / a;
        p = (p + r) % 4;
        d = d - r * a;
        if (p == 0) {
          p = 0;
          x = d;
          y = 0;
        } else if (p == 1) {
          p = 1;
          x = a;
          y = d;
        } else if (p == 2) {
          p = 2;
          x = a - d;
          y = a;
        } else {
          p = 3;
          x = 0;
          y = a - d;
        }
      }
    } else if (p == 2) {
      L = x;
      if (L > d) {
        p = 2;
        x = x - d;
      } else if (L == d) {
        x = 0;
        p = 2;
      } else {
        d = d - L;
        p = 3;
        r = d / a;
        p = (p + r) % 4;
        d = d - r * a;
        if (p == 0) {
          p = 0;
          x = d;
          y = 0;
        } else if (p == 1) {
          p = 1;
          x = a;
          y = d;
        } else if (p == 2) {
          p = 2;
          x = a - d;
          y = a;
        } else {
          p = 3;
          x = 0;
          y = a - d;
        }
      }
    } else {
      L = y;
      if (L > d) {
        p = 3;
        y = y - d;
      } else if (L == d) {
        y = 0;
        p = 0;
      } else {
        d = d - L;
        p = 0;
        r = d / a;
        p = (p + r) % 4;
        d = d - r * a;
        if (p == 0) {
          p = 0;
          x = d;
          y = 0;
        } else if (p == 1) {
          p = 1;
          x = a;
          y = d;
        } else if (p == 2) {
          p = 2;
          x = a - d;
          y = a;
        } else {
          p = 3;
          x = 0;
          y = a - d;
        }
      }
    }
    cout << x << " " << y << endl;
  }
}
