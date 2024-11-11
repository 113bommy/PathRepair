#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
template <class T>
T gcd(T a, T b) {
  return a ? gcd(b % a, a) : b;
}
template <class T>
T sqr(T a) {
  return a * a;
}
template <class T>
T sgn(T a) {
  return a > 0 ? 1 : (a < 0 ? -1 : 0);
}
const double pi = acos(-1.0);
int n;
int m;
const int inf = 2e9;
int query(int x, int y) {
  cout << "? " << x << " " << y << endl;
  fflush(stdout);
  string s;
  cin >> s;
  return s == "y";
}
int solve() {
  if (!query(0, 1)) {
    return 1;
  }
  int x = 1, z = 0;
  while ((long long)2 * x <= inf) {
    if (!query(x, 2 * x)) {
      break;
    }
    z++;
    x *= 2;
  }
  int l = x, r = 2 * x;
  while (r - l > 1) {
    int m = (r + l) / 2;
    if (query(x, m))
      l = m;
    else
      r = m;
  }
  return r;
}
int main() {
  string s;
  while (cin >> s) {
    if (s == "start") {
      int x = solve();
      cout << "!" << x << endl;
      fflush(stdout);
    } else if (s == "mistake") {
      return 0;
    } else if (s == "end") {
      return 0;
    }
  }
  return 0;
}
