#include <bits/stdc++.h>
using namespace std;
const double PI = 2.0 * acos(0.0);
const double eps = 1e-9;
template <class T>
T Abs(T x) {
  return x > 0 ? x : -x;
}
template <class T>
string toString(T n) {
  ostringstream ost;
  ost << n;
  ost.flush();
  return ost.str();
}
template <class T>
inline T gcd(T a, T b) {
  if (a < 0) return gcd(-a, b);
  if (b < 0) return gcd(a, -b);
  return (b == 0) ? a : gcd(b, a % b);
}
template <class T>
inline T lcm(T a, T b) {
  if (a < 0) return lcm(-a, b);
  if (b < 0) return lcm(a, -b);
  return a * (b / gcd(a, b));
}
template <class T>
inline T sqr(T n) {
  return n * n;
}
template <class T>
T power(T n, int p) {
  if (!p)
    return 1;
  else {
    T sum = sqr(power(n, p >> 1));
    if (p & 1) sum = n;
    return sum;
  }
}
int main() {
  int n, k, te;
  cin >> n >> k;
  te = n - k;
  if (!k)
    cout << -1 << endl;
  else {
    cout << te << " ";
    for (int i = 1; i < te; ++i) cout << i << " ";
    for (int i = te + 1; i <= n; ++i) cout << i << " ";
  }
  return 0;
}
