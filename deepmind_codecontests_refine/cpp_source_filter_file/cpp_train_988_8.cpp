#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:600000000")
using namespace std;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
const int INF = (int)1e9;
const long long INFLL = (long long)1e18;
const double PI = acos(-1.0);
template <typename T>
T swop(T &a, T &b) {
  a ^= b;
  b ^= a;
  a ^= b;
}
template <typename T>
T sqr(T x) {
  return x * x;
}
template <typename T>
T GCD(T x, T y) {
  return y ? GCD<T>(y, x % y) : x;
}
template <typename T>
T LCM(T x, T y) {
  return x / GCD<T>(x, y) * y;
}
const int N = (int)1e5 + 5;
int n, bx, by, a1 = 0, a2 = 0;
int main() {
  ios::sync_with_stdio(false);
  cout.setf(ios ::fixed | ios ::showpoint);
  cout.precision(15);
  cin >> n >> bx;
  while (n--) {
    int x;
    cin >> x;
    a1 = a1 * bx + x;
  }
  cin >> n >> by;
  while (n--) {
    int x;
    cin >> x;
    a2 = a2 * by + x;
  }
  if (a2 > a1)
    cout << "<";
  else if (a2 < a1)
    cout << ">";
  else
    cout << "=";
  return 0;
}
