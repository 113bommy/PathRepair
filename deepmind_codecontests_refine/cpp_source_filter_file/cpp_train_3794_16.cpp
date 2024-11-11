#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void remax(T &A, T B) {
  if (A < B) A = B;
}
template <class T>
inline void remin(T &A, T B) {
  if (A > B) A = B;
}
string ToString(long long num) {
  string ret;
  do {
    ret += ((num % 10) + '0');
    num /= 10;
  } while (num);
  reverse(ret.begin(), ret.end());
  return ret;
}
long long ToNumber(string s) {
  long long r = 0, p = 1;
  for (int i = s.size() - 1; i >= 0; --i) r += (s[i] - '0') * p, p *= 10;
  return r;
}
long long Gcd(long long a, long long b) {
  while (a %= b ^= a ^= b ^= a)
    ;
  return b;
}
long long Power(long long base, long long power) {
  long long ret = 1;
  while (power) {
    if (power & 1) ret *= base;
    power >>= 1;
    base *= base;
  }
  return ret;
}
long long PowerMod(long long base, long long power, long long mod) {
  if (!power) return 1;
  if (power & 1) return (base * PowerMod(base, power - 1, mod)) % mod;
  return PowerMod((base * base) % mod, power >> 1, mod);
}
int Log(long long num, long long base) {
  int ret = 0;
  while (num) {
    ++ret;
    num /= base;
  }
  return ret;
}
int Count(long long mask) {
  int ret = 0;
  while (mask) {
    if (mask & 1) ++ret;
    mask >>= 1;
  }
  return ret;
}
long long memo[65][65][2];
bool bin[65];
long long m;
int k;
long long f(int bit, int rem, bool ok) {
  if (rem < 0) return 0;
  if (bit == ~0) return !rem;
  long long &ret = memo[bit][rem][ok];
  if (~ret) return ret;
  ++ret;
  for (int i = 0; i < 2; ++i) {
    if (!ok && i > bin[bit]) continue;
    ret += f(bit - 1, rem - i, ok | (i < bin[bit]));
  }
  return ret;
}
long long calc(long long m) {
  long long x = m * 2;
  long long ret;
  for (int i = 0; i < 65; ++i) {
    bin[i] = x & 1;
    x >>= 1;
  }
  memset(memo, ~0, sizeof memo);
  ret = f(64, k, false);
  x = m;
  for (int i = 0; i < 65; ++i) {
    bin[i] = x & 1;
    x >>= 1;
  }
  memset(memo, ~0, sizeof memo);
  return ret -= f(64, k, false);
}
long long bs(long long l, long long r) {
  while (r - l > 1) {
    long long m = (l + r) >> 1;
    if (calc(m) <= ::m)
      l = m;
    else
      r = m;
  }
  return l;
}
inline void run() {
  scanf("%I64d%d", &m, &k);
  printf("%I64d\n", bs(1, 100000000000000000));
}
int main() {
  FILE *input = stdin;
  FILE *output = stdout;
  while (!feof(input)) {
    run();
    break;
  }
  return 0;
}
