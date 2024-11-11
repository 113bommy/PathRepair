#include <bits/stdc++.h>
using namespace std;
template <typename T>
T abs(T a) {
  return a < 0 ? -a : a;
}
template <typename T>
T sqr(T a) {
  return a * a;
}
const int INF = (int)1e9;
const long double EPS = 1e-9;
const long double PI = 3.1415926535897932384626433832795;
int main() {
  int n, R, r;
  cin >> n >> R >> r;
  if (n == 1) {
    if (r <= R)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  } else if (n == 2) {
    if (2 * r <= R)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  } else {
    double alpha = 3.1415926535897932384626433 / double(n);
    if ((R - r) * sin(alpha) > (r))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
