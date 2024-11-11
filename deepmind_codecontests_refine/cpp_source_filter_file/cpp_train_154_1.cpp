#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int INF = 0x3f3f3f3f;
long long mod = 1e9 + 7;
int main() {
  string s[13] = {
      "",        "x^y^z",   "x^z^y", "(x^y)^z", "(x^z)^y", "y^x^z",   "y^z^x",
      "(y^x)^z", "(y^z)^x", "z^x^y", "z^y^x",   "(z^x)^y", "(z^y)^x",
  };
  int ans = 1;
  long double x, y, z;
  long double mx = -100, t;
  cin >> x >> y >> z;
  if (x < 1 && y < 1 && z < 1) {
    ans = 1;
    mx = pow(x, pow(y, z));
    t = pow(x, pow(z, y));
    if (t > mx) {
      mx = t;
      ans = 2;
    }
    t = pow(pow(x, y), z);
    if (t > mx) {
      mx = t;
      ans = 3;
    }
    t = pow(y, pow(x, z));
    if (t > mx) {
      mx = t;
      ans = 5;
    }
    t = pow(y, pow(z, x));
    if (t > mx) {
      mx = t;
      ans = 6;
    }
    t = pow(pow(y, x), z);
    if (t > mx) {
      mx = t;
      ans = 7;
    }
    t = pow(z, pow(x, y));
    if (t > mx) {
      mx = t;
      ans = 9;
    }
    t = pow(z, pow(y, x));
    if (t > mx) {
      mx = t;
      ans = 10;
    }
    t = pow(pow(z, x), y);
    if (t > mx) {
      mx = t;
      ans = 11;
    }
  } else {
    if (x >= 1) {
      t = z * log(y) + log(log(x));
      if (t > mx) {
        mx = t;
        ans = 1;
      }
      t = y * log(z) + log(log(x));
      if (t > mx) {
        mx = t;
        ans = 2;
      }
      t = log(y) + log(z) + log(log(x));
      if (t > mx) {
        mx = t;
        ans = 3;
      }
    }
    if (y >= 1) {
      t = z * log(x) + log(log(y));
      if (t > mx) {
        mx = t;
        ans = 5;
      }
      t = x * log(z) + log(log(y));
      if (t > mx) {
        mx = t;
        ans = 6;
      }
      t = log(x) + log(z) + log(log(y));
      if (t > mx) {
        mx = t;
        ans = 7;
      }
    }
    if (z >= 1) {
      t = y * log(x) + log(log(z));
      if (t > mx) {
        mx = t;
        ans = 9;
      }
      t = x * log(y) + log(log(z));
      if (t > mx) {
        mx = t;
        ans = 10;
      }
      t = log(x) + log(y) + log(log(z));
      if (t > mx) {
        mx = t;
        ans = 11;
      }
    }
  }
  cout << s[ans] << endl;
  return 0;
}
