#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:64000000")
const double pi = 3.14159265358979323846;
const double eps = 1e-6;
const long long maxn = 501;
const long long inf = 1000000007;
const long long mod = 1000000007;
long long n, x;
long long a1, a2, b1, b2, ans11, ans12, ans21, ans22, ans31, ans32, ans41,
    ans42;
bool check(long long a3, long long b3, long long a4, long long b4) {
  if (ans11 >= a3 && ans21 <= a4 && ans21 >= b3 && ans22 <= b4) return true;
  return false;
}
int main() {
  cin >> n;
  long long l = 0, r = n, c;
  while (r - l > 1) {
    c = (r + l) / 2;
    cout << "? " << 1 << ' ' << 1 << ' ' << c << ' ' << n << endl;
    cout.flush();
    cin >> x;
    if (x > 0) {
      r = c;
    } else {
      l = c;
    }
  }
  a2 = r;
  l = 1, r = a2 + 1;
  while (r - l > 1) {
    c = (r + l) / 2;
    cout << "? " << c << ' ' << 1 << ' ' << a2 << ' ' << n << endl;
    cout.flush();
    cin >> x;
    if (x > 0) {
      l = c;
    } else {
      r = c;
    }
  }
  a1 = l;
  l = 0, r = n;
  while (r - l > 1) {
    c = (r + l) / 2;
    cout << "? " << a1 << ' ' << 1 << ' ' << a2 << ' ' << c << endl;
    cout.flush();
    cin >> x;
    if (x > 0) {
      r = c;
    } else {
      l = c;
    }
  }
  b2 = r;
  l = 1, r = b2 + 1;
  while (r - l > 1) {
    c = (r + l) / 2;
    cout << "? " << a1 << ' ' << c << ' ' << a2 << ' ' << b2 << endl;
    cout.flush();
    cin >> x;
    if (x > 0) {
      l = c;
    } else {
      r = c;
    }
  }
  b1 = l;
  ans11 = a1;
  ans12 = b1;
  ans21 = a2;
  ans22 = b2;
  l = 0, r = n;
  while (r - l > 1) {
    c = (r + l) / 2;
    cout << "? " << 1 << ' ' << 1 << ' ' << c << ' ' << n << endl;
    cout.flush();
    cin >> x;
    if (check(1, 1, c, n)) {
      x--;
    }
    if (x > 0) {
      r = c;
    } else {
      l = c;
    }
  }
  a2 = r;
  l = 1, r = a2 + 1;
  while (r - l > 1) {
    c = (r + l) / 2;
    cout << "? " << c << ' ' << 1 << ' ' << a2 << ' ' << n << endl;
    cout.flush();
    cin >> x;
    if (check(c, 1, a2, n)) {
      x--;
    }
    if (x > 0) {
      l = c;
    } else {
      r = c;
    }
  }
  a1 = l;
  l = 0, r = n;
  while (r - l > 1) {
    c = (r + l) / 2;
    cout << "? " << a1 << ' ' << 1 << ' ' << a2 << ' ' << c << endl;
    cout.flush();
    cin >> x;
    if (check(a1, 1, a2, c)) {
      x--;
    }
    if (x > 0) {
      r = c;
    } else {
      l = c;
    }
  }
  b2 = r;
  l = 1, r = b2 + 1;
  while (r - l > 1) {
    c = (r + l) / 2;
    cout << "? " << a1 << ' ' << c << ' ' << a2 << ' ' << b2 << endl;
    cout.flush();
    cin >> x;
    if (check(a1, c, a2, b2)) {
      x--;
    }
    if (x > 0) {
      l = c;
    } else {
      r = c;
    }
  }
  b1 = l;
  cout << "! " << ans11 << ' ' << ans12 << ' ' << ans21 << ' ' << ans22 << ' '
       << a1 << ' ' << b1 << ' ' << a2 << ' ' << b2;
  return 0;
}
