#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T checkmin(T &a, T b) {
  return (a < b) ? a : a = b;
}
template <class T>
inline T checkmax(T &a, T b) {
  return (a > b) ? a : a = b;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
inline T Lowbit(T x) {
  return x & (-x);
}
template <class T>
T GCD(T a, T b) {
  if (a < 0) return GCD(-a, b);
  if (b < 0) return GCD(a, -b);
  return (a == 0) ? b : GCD(b % a, a);
}
template <class T>
T LCM(T a, T b) {
  if (a < 0) return LCM(-a, b);
  if (b < 0) return LCM(a, -b);
  return (a == 0 || b == 0) ? 0 : a / GCD(a, b) * b;
}
template <class T>
T ExtGCD(T a, T b, T &x, T &y) {
  if (a < 0) {
    T c = ExtGCD(-a, b, x, y);
    x = -x;
    return c;
  }
  if (b < 0) {
    T c = ExtGCD(a, -b, x, y);
    y = -y;
    return c;
  }
  if (a == 0) {
    x = 0, y = 1;
    return b;
  } else {
    T c = ExtGCD(b % a, a, y, x);
    x -= b / a * y;
    return c;
  }
}
long long Ans, L, R;
int main() {
  cin >> L >> R;
  for (long long i = 9, j = 1; i <= 9999999999LL;
       i = i * 10LL + 9LL, j *= 10LL) {
    long long l = max(j, L), r = min(i, R);
    if (l > r) continue;
    if (l <= i / 2 && i / 2 <= r)
      checkmax(Ans, i / 2 * (i - i / 2));
    else
      checkmax(Ans, max(l * (i - l), r * (i - r)));
  }
  cout << Ans << endl;
  return 0;
}
