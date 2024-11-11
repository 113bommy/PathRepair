#include <bits/stdc++.h>
using namespace std;
long long mulmod(long long a, long long b, long long m) {
  long long q = (long long)(((long double)a * (long double)b) / (long double)m);
  long long r = a * b - q * m;
  if (r > m) r %= m;
  if (r < 0) r += m;
  return r;
}
template <typename T, typename S>
T expo(T e, S n) {
  T x = 1, p = e;
  while (n) {
    if (n & 1) x = x * p;
    p = p * p;
    n >>= 1;
  }
  return x;
}
template <typename T>
T mod(T a, T b) {
  return (a < b ? (b - a) : (a - b));
}
template <typename T>
T power(T e, T n, T m) {
  T x = 1, p = e;
  while (n) {
    if (n & 1) x = mod(x * p, m);
    p = mod(p * p, m);
    n >>= 1;
  }
  return x;
}
template <typename T>
T powerL(T e, T n, T m) {
  T x = 1, p = e;
  while (n) {
    if (n & 1) x = mulmod(x, p, m);
    p = mulmod(p, p, m);
    n >>= 1;
  }
  return x;
}
template <typename T>
T InverseEuler(T a, T m) {
  return (a == 1 ? 1 : power(a, m - 2, m));
}
template <typename T>
T gcd(T a, T b) {
  return __gcd(a, b);
}
template <typename T>
T lcm(T a, T b) {
  return (a * (b / gcd(a, b)));
}
int main() {
  int n, k, i, a, b, c, d;
  cin >> n >> k >> a >> b >> c >> d;
  if (n < 6 || k <= n) {
    cout << "-1";
    return 0;
  }
  cout << a << " " << c << " ";
  for (i = 1; i <= n; i++)
    if (i != a && i != b && i != c && i != d) cout << i << " ";
  cout << d << " " << b;
  cout << "\n";
  cout << c << " " << a << " ";
  for (i = 1; i <= n; i++)
    if (i != a && i != b && i != c && i != d) cout << i << " ";
  cout << b << " " << d;
  cout << "\n";
  return 0;
}
