#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T bigmod(T p, T e, T M) {
  long long ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
template <class T>
inline T lcm(T a, T b) {
  a = abs(a);
  b = abs(b);
  return (a / gcd(a, b)) * b;
}
template <class T, class X>
inline bool getbit(T a, X i) {
  T t = 1;
  return ((a & (t << i)) > 0);
}
template <class T, class X>
inline T setbit(T a, X i) {
  T t = 1;
  return (a | (t << i));
}
template <class T, class X>
inline T resetbit(T a, X i) {
  T t = 1;
  return (a & (~(t << i)));
}
inline long long getnum() {
  char c = getchar();
  long long num, sign = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') sign = -1;
  for (num = 0; c >= '0' && c <= '9';) {
    c -= '0';
    num = num * 10 + c;
    c = getchar();
  }
  return num * sign;
}
inline long long power(long long a, long long b) {
  long long multiply = 1;
  for (int i = (0); i < (b); i++) {
    multiply *= a;
  }
  return multiply;
}
long long a, b;
int main() {
  int test, cases = 1;
  cin >> test;
  while (test--) {
    cin >> a >> b;
    double ans = 0;
    cout << setprecision(10) << fixed;
    if (b == 0)
      cout << 1 << "\n";
    else if (a == 0)
      cout << 0.5 << "\n";
    else {
      if (a / 4.0 > b) {
        double area = 2 * b * a;
        double valid = area - 0.5 * 4 * b * b;
        ans = valid / area;
      } else {
        double area = 2 * b * a;
        double valid = 0.5 * a * 0.25 * a + b * a;
        ans = valid / area;
      }
      cout << ans << "\n";
    }
  }
  return 0;
}
