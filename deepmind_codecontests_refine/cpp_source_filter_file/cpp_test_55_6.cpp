#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[1000000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
long long read() {
  long long pos = 1, num = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') pos = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    num = num * 10 + (long long)(ch - '0');
    ch = getchar();
  }
  return pos * num;
}
void write(long long x) {
  if (x < 0) {
    putchar('-');
    write(-x);
    return;
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
void writesp(long long x) {
  write(x);
  putchar(' ');
}
void writeln(long long x) {
  write(x);
  putchar('\n');
}
const long long mod = 1e9 + 7;
inline long long quickpower(long long a, long long b) {
  long long res = 1;
  a %= mod;
  while (b) {
    if (b & 1) (res *= a) %= mod;
    b >>= 1;
    (a *= a) %= mod;
  }
  return res;
}
signed main() {
  long long k = read();
  writeln(6 * quickpower(4, (1 << k) - 2) % mod);
}
