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
  char ch[100][101];
  int cnt[7] = {};
  int n, m, k;
  bool f = false, s = false;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n;) scanf("%s", ch + i++);
  ++k;
  for (int i = 0; i < n; ++i) {
    int p1 = ~0, p2 = ~0, p3 = ~0;
    for (int j = 0; j < m; ++j)
      if (ch[i][j] == 'R')
        p1 = j;
      else if (ch[i][j] == 'G')
        p2 = j;
      else
        p3 = j;
    if (~p1 && p2 == ~0 && ~p3) f = true;
    if (p1 == ~0 && ~p2 && ~p3) s = true;
    if (~p1 && ~p2) {
      int d = abs(p1 - p2);
      --d;
      for (int j = 0; j < 7; ++j)
        if (d & (1 << j)) ++cnt[j] %= k;
    }
  }
  if (f && s)
    puts("Draw");
  else if (f)
    puts("First");
  else if (s)
    puts("Second");
  else {
    for (int i = 0; i < 7; ++i)
      if (cnt[i]) return (void)puts("First");
    puts("Second");
  }
}
int main() {
  FILE* input = stdin;
  FILE* output = stdout;
  while (!feof(input)) {
    run();
    break;
  }
  return 0;
}
