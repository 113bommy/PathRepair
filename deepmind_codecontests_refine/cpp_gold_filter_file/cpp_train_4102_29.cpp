#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0;
  char ch = getchar();
  bool pos = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') pos = -1;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return pos * x;
}
void write(long long x) {
  if (x < 0) {
    putchar('-'), x = -x;
  }
  if (x >= 10) write(x / 10);
  putchar('0' + x % 10);
}
inline void writeln(long long x) {
  write(x);
  puts("");
}
inline void writespace(long long x) {
  write(x);
  putchar(' ');
}
const string taskname = "ez";
const long long mod = 1e9 + 7;
long long n, k, ans = 1, one, two;
long long num[1000010], f[1000010];
inline long long mul(long long a, long long b) { return (a * b) % mod; }
inline long long add(long long a, long long b) { return (a + b) % mod; }
signed main() {
  srand(20050210);
  n = read();
  for (register long long i = 1; i <= n; ++i) {
    num[i] = read();
    (num[i] == 1) ? ++one : ++two;
  }
  f[1] = f[0] = 1;
  for (register long long i = 2; i <= one; ++i)
    f[i] = add(mul(f[i - 2], i - 1), f[i - 1]);
  for (register long long i = n; i > one; --i) ans = mul(ans, i);
  write(mul(ans, f[one]));
  return 0;
}
