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
int memo[10000 + 1250][5];
int n;
int f(int a, int b) {
  int &ret = memo[a][b];
  if (~ret) return ret;
  long long apb = 1;
  for (int i = 0; i < b && apb < n; ++i) apb *= a;
  if (apb >= n)
    ret = 1;
  else if (b == 1 && (long long)a * a >= n)
    ret = 1 - ((n - a) & 1);
  else if (a == 1 && (1LL << b) >= n)
    ret = 2;
  else if (!f(a + 1, b) || !f(a, b + 1))
    ret = 1;
  else
    ret = 0;
  return ret;
}
inline void run() {
  int a, b, ans;
  scanf("%d%d%d", &a, &b, &n);
  memset(memo, ~0, sizeof memo);
  ans = f(a, b);
  if (!ans)
    puts("Stas");
  else if (ans == 1)
    puts("Masha");
  else
    puts("Missing");
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
