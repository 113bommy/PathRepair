#include <bits/stdc++.h>
using namespace std;
const unsigned long long mod = 1000000007;
unsigned long long powmod(unsigned long long a, unsigned long long b) {
  unsigned long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
unsigned long long getGCD(unsigned long long a, unsigned long long b) {
  if (b == 0) return a;
  if (a < b) return getGCD(b, a);
  if (a % b == 0) return b;
  return getGCD(b, a % b);
}
unsigned long long t, w, b, a;
int main() {
  cin >> t >> w >> b;
  unsigned long long g = getGCD(w, b);
  unsigned long long w1 = w / g, b1 = b / g, temp;
  bool flag = __builtin_umulll_overflow(w1, b1 * g, &temp);
  if (flag || t < temp) {
    a = 0;
  } else {
    a = t / temp;
  }
  unsigned long long p = a * min(w, b);
  if (p) p--;
  if (a)
    p += min(min(w, b), t % (w1 * b1 * g) + 1);
  else
    p += min(min(w - 1, b - 1), t);
  unsigned long long q = t;
  g = getGCD(p, q);
  p /= g;
  q /= g;
  cout << p << '/' << q << endl;
  return 0;
}
