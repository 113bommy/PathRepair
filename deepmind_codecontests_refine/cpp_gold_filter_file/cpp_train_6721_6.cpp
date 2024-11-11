#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void remax(T& A, T B) {
  if (A < B) A = B;
}
template <class T>
inline void remin(T& A, T B) {
  if (A > B) A = B;
}
string ToString(long long num) {
  string ret;
  bool neg = false;
  if (num < 0) num *= ~0, neg = true;
  do {
    ret += ((num % 10) + '0');
    num /= 10;
  } while (num);
  if (neg) ret += '-';
  reverse(ret.begin(), ret.end());
  return ret;
}
long long ToNumber(string s) {
  long long r = 0, p = 1;
  int e = (s[0] == '-');
  for (int i = (int)s.size() - 1; i >= e; --i) r += (s[i] - '0') * p, p *= 10;
  if (e) r *= ~0;
  return r;
}
long long Gcd(long long a, long long b) {
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
int Log(long long num, long long base) {
  int ret = 0;
  while (num) {
    ++ret;
    num /= base;
  }
  return ret;
}
inline void run() {
  char ch[200001];
  bool ok[200000] = {};
  int n, p = 0;
  scanf("%d%s", &n, ch);
  while (p < n - 1) {
    if (ch[p] == '>' && ch[p + 1] == '<') {
      for (int i = p; ~i; --i)
        if (ch[i] == '>')
          ok[i] = true;
        else
          break;
      for (int i = p + 1; i < n; ++i)
        if (ch[i] == '<')
          ok[i] = true;
        else
          break;
    }
    ++p;
  }
  p = 0;
  for (int i = 0; i < n; ++i)
    if (!ok[i]) ++p;
  printf("%d\n", p);
}
int main() {
  FILE* inut = stdin;
  FILE* outut = stdout;
  while (!feof(inut)) {
    run();
    break;
  }
  return 0;
}
