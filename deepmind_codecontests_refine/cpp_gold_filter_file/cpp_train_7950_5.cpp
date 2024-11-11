#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x, y, n;
  cin >> x >> y >> n;
  long long t;
  if (n < y)
    t = abs(y - n);
  else
    t = 0;
  double m = INT_MAX;
  long long p, q;
  if (x < y) {
    while (y - t > 0) {
      long long i = t * x / y;
      double a;
      long long u, l;
      if (abs(double(x - i - 1) / (y - t) - double(x) / y) <=
          abs(double(x - i) / (y - t) - double(x) / y)) {
        a = abs(double(x - i - 1) / (y - t) - double(x) / y);
        u = x - i - 1;
        l = y - t;
      } else {
        a = abs(double(x - i) / (y - t) - double(x) / y);
        u = x - i;
        l = y - t;
      }
      if (a < m) {
        m = a;
        p = u;
        q = l;
      } else if (a == m) {
        if (q > l) {
          p = u;
          q = l;
        }
      }
      t++;
    }
  } else {
    while (y - t > 0) {
      long long i = ceil(double(t * x) / y);
      double a;
      long long u, l;
      if (abs(double(x - i + 1) / (y - t) - double(x) / y) >=
          abs(double(x - i) / (y - t) - double(x) / y)) {
        a = abs(double(x - i) / (y - t) - double(x) / y);
        u = x - i;
        l = y - t;
      } else {
        a = abs(double(x - i + 1) / (y - t) - double(x) / y);
        u = x - i + 1;
        l = y - t;
      }
      if (a < m) {
        m = a;
        p = u;
        q = l;
      } else if (a == m) {
        if (q > l) {
          p = u;
          q = l;
        }
      }
      t++;
    }
  }
  cout << p << "/" << q << endl;
}
