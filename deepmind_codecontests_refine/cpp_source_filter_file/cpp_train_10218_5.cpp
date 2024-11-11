#include <bits/stdc++.h>
using namespace std;
namespace mine {
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3fll;
long long qread() {
  long long ans = 0;
  char c = getchar();
  int f = 1;
  while (c < '0' or c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while ('0' <= c and c <= '9') ans = ans * 10 + c - '0', c = getchar();
  return ans * f;
}
void write(long long num) {
  if (num < 0) {
    num = -num;
    putchar('-');
  }
  if (num > 9) write(num / 10);
  putchar('0' + num % 10);
}
void write1(long long num) {
  write(num);
  putchar(' ');
}
void write2(long long num) {
  write(num);
  puts("");
}
void chmax(long long &x, const long long y) { x = x > y ? x : y; }
void chmin(long long &x, const long long y) { x = x < y ? x : y; }
const int MAX_N = 2e5 + 10;
const long long MOD = 1e9 + 7;
void add(long long &x, long long y) {
  x += y;
  if (x >= MOD) x -= MOD;
  if (x < 0) x += MOD;
}
long long gcd(long long x, long long y) { return y == 0 ? x : gcd(y, x % y); }
long long n, k;
long long mi = INF, mx = 0;
void check(long long x, long long y) {
  if (x > y) y += n * k;
  long long tmp = y - x;
  chmin(mi, n * k / gcd(n * k, tmp));
  chmax(mx, n * k / gcd(n * k, tmp));
}
long long gg(long long x) { return (x + n * k) % (n * k); }
void main() {
  n = qread(), k = qread();
  long long a = qread(), b = qread();
  for (long long t = 0; t <= n * k - 1; t += k) {
    check(a, gg(t - b));
    check(k - a, gg(t - b));
    check(a, gg(t + b));
    check(k - a, gg(t + b));
  }
  printf("%lld %lld", mi, mx);
}
};  // namespace mine
int main() {
  srand(time(0));
  mine::main();
}
