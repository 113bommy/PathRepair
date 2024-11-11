#include <bits/stdc++.h>
using namespace std;
bool func(long long a, long long b, long long c, long long d) {
  if (a > b && a > c) {
    d = d - (a - b);
    d = d - (a - c);
    if (d < 0 || d % 3 != 0)
      return false;
    else
      return true;
  } else if (b > a && b > c) {
    d = d - (b - a);
    d = d - (b - c);
    if (d < 0 || d % 3 != 0)
      return false;
    else
      return true;
  } else if (c > a && c > b) {
    d = d - (c - a);
    d = d - (c - b);
    if (d < 0 || d % 3 != 0)
      return false;
    else
      return true;
  } else
    return false;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, c, a, b;
    bool p;
    cin >> n >> c >> a >> b;
    long long x = -1, y = -1, z = -1;
    if (n % 3 != 0) {
      cout << "no" << endl;
      continue;
    }
    if ((2 * a + b + c) % 3 == 0) {
      x = (2 * a + b + c) / 3;
      y = x - a;
      z = y - b;
      if (!(x > c || y < 0 || z < 0)) {
        p = func(x, y, z, n - c);
        if (p == true) {
          cout << "yes" << endl;
          continue;
        }
      }
    }
    if ((a + b + c) % 3 == 0) {
      y = (a + b + c) / 3;
      x = y - a;
      z = y - b;
      if (!(y > c || x < 0 || z < 0)) {
        p = func(x, y, z, n - c);
        if (p == true) {
          cout << "yes" << endl;
          continue;
        }
      }
    }
    if ((2 * b + c - a) % 3 == 0) {
      z = (2 * b + c - a) / 3;
      y = z - b;
      x = y + a;
      if (!(z > c || y < 0 || x < 0 || x > c || z < 0)) {
        p = func(x, y, z, n - c);
        if (p == true) {
          cout << "yes" << endl;
          continue;
        }
      }
    }
    if ((c - b - 2 * a) % 3 == 0) {
      x = (c - b - 2 * a) / 3;
      y = x + a;
      z = y + b;
      if (!(x < 0 || y > c || z > c)) {
        p = func(x, y, z, n - c);
        if (p == true) {
          cout << "yes" << endl;
          continue;
        }
      }
    }
    cout << "no" << endl;
  }
}
