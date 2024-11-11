#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
inline void remax(T1& A, T2 B) {
  if (A < B) A = B;
}
template <class T1, class T2>
inline void remin(T1& A, T2 B) {
  if (A > B) A = B;
}
long long Gcd(long long a, long long b) {
  if (!a || !b) return a + b;
  while (a %= b ^= a ^= b ^= a)
    ;
  return b;
}
long long Power(long long base, unsigned long long power) {
  long long ret = 1;
  while (power) {
    if (power & 1) ret *= base;
    power >>= 1;
    base *= base;
  }
  return ret;
}
long long PowerMod(long long base, unsigned long long power, long long mod) {
  if (!power) return 1 % mod;
  if (power & 1) return (base * PowerMod(base, power - 1, mod)) % mod;
  return PowerMod((base * base) % mod, power >> 1, mod);
}
int n;
int f(int x, int y) {
  if (!x) return y;
  if (x == n) return n + n + n - y;
  if (!y) return n + n + n + n - x;
  return n + n - x;
}
inline void run() {
  int x1, y1, x2, y2, ans;
  scanf("%d%d%d%d%d", &n, &x1, &y1, &x2, &y2);
  ans = abs(f(x1, y1) - f(x2, y2));
  remin(ans, n + n + n + n - ans);
  printf("%d\n", ans);
}
int main() {
  run();
  return 0;
}
