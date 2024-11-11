#include <bits/stdc++.h>
using namespace std;
static char _buf[1 << 16];
int _pos = 1;
int _cap = 1;
inline char nextChar() {
  if (_cap == 0) return 0;
  if (_pos == _cap) {
    _cap = (int)fread(_buf, 1, 1 << 16, stdin);
    if (_cap == 0) return 0;
    _pos = 0;
  }
  return _buf[_pos++];
}
inline int nextInt() {
  char c = nextChar();
  while (isspace(c)) c = nextChar();
  int res = 0;
  while (isdigit(c)) {
    res = res * 10 + c - '0';
    c = nextChar();
  }
  return res;
}
unsigned a, b, c, d;
inline unsigned F(unsigned x) { return ((a * x + b) * x + c) * x + d; }
inline unsigned Count(unsigned n, unsigned p) {
  unsigned res = 0;
  while (n) {
    n /= p;
    res += n;
  }
  return res;
}
unsigned np[(100000000 + 31) / 32];
inline bool isprime(int x) {
  int q = (x / 6) * 2 + ((x % 6) == 5 ? 0 : 1);
  return (np[q >> 5] & (1 << (q & 31))) == 0;
}
inline void notprime(int x, int n) {
  if (x >= 30000) return;
  for (int j = x * x; j <= n; j += x) {
    int m = j % 6;
    if (m == 5 || m == 1) {
      int q = (j / 6) * 2 + (m == 5 ? 0 : 1);
      np[q >> 5] |= 1 << (q & 31);
    }
  }
}
int main() {
  unsigned n = nextInt();
  a = nextInt();
  b = nextInt();
  c = nextInt();
  d = nextInt();
  unsigned res = Count(n, 2) * F(2);
  res += Count(n, 3) * F(3);
  for (unsigned i = 5; i < n; i += 6) {
    if (isprime(i)) {
      res += Count(n, i) * F(i);
      notprime(i, n);
    }
    if (i + 2 < n)
      if (isprime(i + 2)) {
        res += Count(n, i + 2) * F(i + 2);
        notprime(i + 2, n);
      }
  }
  cout << res << endl;
  return 0;
}
