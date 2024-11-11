#include <bits/stdc++.h>
using namespace std;
const int inf = 111111111;
void io() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(15);
}
long long mulmod(long long a, long long b, long long m) {
  long long q = (long long)(((long double)a * (long double)b) / (long double)m);
  long long r = a * b - q * m;
  if (r > m) r %= m;
  if (r < 0) r += m;
  return r;
}
template <typename T>
T mod(T a, T b) {
  while (a < 0) a += b;
  return a % b;
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
T power(T e, T n) {
  T x = 1, p = e;
  while (n) {
    if (n & 1) x = x * p;
    p = p * p;
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
int exEuclid(int a, int b, int &x, int &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int x1, y1;
  int g = exEuclid(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return g;
}
bool isok(int a, int b, int n) {
  int cnt = 0;
  while (n >= 0) {
    if (n % b == 0) return 1;
    if (n < a) break;
    n -= a;
  }
  return 0;
}
int main(int argc, char *argv[]) {
  io();
  int n;
  cin >> n;
  int a = 1234567, b = 123456, c = 1234;
  bool f = 0;
  int tmp = n;
  int cnt = 0;
  while (tmp) {
    if (isok(b, c, tmp)) f = 1;
    if (tmp < a) break;
    tmp -= a;
  }
  f = isok(b, c, tmp);
  if (f)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
