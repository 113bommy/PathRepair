#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void Int(T &n) {
  n = 0;
  int f = 1;
  register int ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) n = (n << 3) + (n << 1) + ch - '0';
  n = n * f;
}
template <typename T>
T gcd(T a, T b) {
  return !b ? a : gcd(b, a % b);
}
template <typename T>
inline void umin(T &a, T b) {
  a = a < b ? a : b;
}
template <typename T>
inline void umax(T &a, T b) {
  a = a > b ? a : b;
}
template <typename T, typename W>
inline void Int(T &x, W &y) {
  Int(x), Int(y);
}
template <typename T, typename W, typename Q>
inline void Int(T &x, W &y, Q &z) {
  Int(x, y), Int(z);
}
const int N = (int)1e5 + 5;
const int INF = (int)1e9 + 7;
const long long MOD = (long long)1e9 + 7;
int main() {
  int a, b, c, d;
  Int(a, b);
  Int(c, d);
  for (int i = d; i <= d * 2; ++i)
    if (i >= c and i <= c * 2 and b > d) {
      return !printf("%d\n%d\n%d\n", a * 2, b * 2, i);
    }
  cout << -1 << '\n';
  return 0;
}
