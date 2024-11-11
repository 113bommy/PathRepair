#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(T a) {
  return a >= 0 ? a : -a;
}
template <class T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <class T>
T mod(T a, T b) {
  T ret = a % b;
  if (ret < 0) ret += b;
  return ret;
}
long long mulmod(long long a, long long b, long long c) {
  if (b == 0LL) return 0LL;
  long long ret = mulmod(a, b >> 1, c);
  ret = (ret + ret) % c;
  if (b & 1LL) ret = (ret + a) % c;
  return ret;
}
long long powmod(long long a, long long b, long long c) {
  if (b == 0LL) return 1LL;
  long long ret = powmod(a, b >> 1, c);
  ret = ret * ret % c;
  if (b & 1LL) ret = ret * a % c;
  return ret;
}
template <class T>
inline void write(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x < 10)
    putchar(x + '0');
  else
    write(x / 10), putchar(x % 10 + '0');
}
template <class T>
inline void read(T& x) {
  bool f = 0;
  char ch;
  for (ch = getchar(); ch <= 32; ch = getchar())
    ;
  if (ch == '-') f = 1, ch = getchar();
  for (x = 0; ch > 32; ch = getchar()) x = (x << 3) + (x << 1) + ch - '0';
  if (f) x = -x;
}
int main() {
  int n;
  read(n);
  string s;
  int a, b;
  while (n--) {
    cin >> s >> a >> b;
    if (a >= 2400 && b > a) return puts("YES"), 0;
  }
  puts("NO");
  return 0;
}
