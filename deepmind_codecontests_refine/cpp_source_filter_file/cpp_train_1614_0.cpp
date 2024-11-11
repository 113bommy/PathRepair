#include <bits/stdc++.h>
using namespace std;
void io() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(15);
}
template <typename T>
T abs(T &n) {
  return (n < 0 ? -n : n);
}
template <typename T>
T max(T &a, T &b) {
  return (!(a < b) ? a : b);
}
template <typename T>
T min(T &a, T &b) {
  return (a < b ? a : b);
}
template <typename T>
T mod(T a, T b) {
  return (a < b ? a : a % b);
}
long long mulmod(long long a, long long b, long long m) {
  long long q = (long long)(((long double)a * (long double)b) / (long double)m);
  long long r = a * b - q * m;
  if (r > m) r %= m;
  if (r < 0) r += m;
  return r;
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
  return (!b) ? a : gcd(b, a % b);
}
template <typename T>
T lcm(T a, T b) {
  return (a * (b / gcd(a, b)));
}
long long solve(long long a, long long b, long long c, long long l) {
  int x = min(a - b - c, l);
  if (x < 0) return 0;
  return ((x + 1) * (x + 2) / 2);
}
int main(int argc, char *argv[]) {
  io();
  long long l;
  long long a, b, c;
  cin >> a >> b >> c >> l;
  long long tot = (l + 3) * (l + 2) * (l + 1) / 6;
  long long cnt = 0;
  for (int i = 0; i <= l; i++) {
    tot -= solve(a + i, b, c, l - i);
    tot -= solve(b + i, c, a, l - i);
    tot -= solve(c + i, a, b, l - i);
  }
  cout << tot << '\n';
  return 0;
}
