#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
inline long long read() {
  register long long x = 0, f = 1;
  register char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  return x * f;
}
void write(long long x) {
  if (x < 0) x = -x, putchar('-');
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
void writeln(long long x) {
  write(x);
  puts("");
}
const long long mod1 = 10000000000ll;
const long long mod2 = 10000000009ll;
long long mul(long long x, long long y, long long mod) {
  long long ans = x * y - (long long)((long double)x / mod * y) * mod;
  return (ans % mod + mod) % mod;
}
inline long long S1(long long x, long long y, long long mod) {
  long long v1 = y - x + 1;
  long long v2 = x + y;
  long long v3 = 1;
  v1 % 2 == 0 ? v1 /= 2 : v2 % 2 == 0 ? v2 /= 2 : v3 /= 2;
  ;
  return mul(v1, v2, mod);
}
inline long long S2(long long n, long long mod) {
  long long v1 = n;
  long long v2 = n + 1;
  long long v3 = 2 * n + 1;
  v1 % 2 == 0 ? v1 /= 2 : v2 % 2 == 0 ? v2 /= 2 : v3 /= 2;
  ;
  v1 % 3 == 0 ? v1 /= 3 : v2 % 3 == 0 ? v2 /= 3 : v3 /= 3;
  ;
  return mul(mul(v1 % mod, v2 % mod, mod), v3 % mod, mod);
}
long long solve(long long x, long long mod) {
  return S1(1, mul(x, x, mod * 2), mod);
}
long long calc(long long x, long long y, long long mod) {
  if (!x || !y) return 0;
  long long ans1 = solve(min(x, y), mod), ans2, ans3;
  if (x > y) {
    ans2 = mul(S1(y * y + y + 2, y * y + 2 * y + 1, mod), x - y, mod);
    ans3 = mul(((S2(x, mod) - S2(y, mod) + mod) % mod) -
                   mul(x - y, mul(y + 1, y + 1, mod), mod) + mod,
               y, mod);
  } else {
    ans2 = mul(S1(x * x + 1, x * x + x, mod), y - x, mod);
    ans3 = mul(((S2(y - 1, mod) - S2(x - 1, mod) + mod) % mod) -
                   mul(y - x, mul(x, x, mod), mod) + mod,
               x, mod);
  }
  return ((ans1 + ans2) % mod + ans3) % mod;
}
void solve() {
  long long x, y, X, Y;
  x = read(), y = read(), X = read(), Y = read();
  long long ans1 = calc(X, Y, mod1) - calc(X, y - 1, mod1) -
                   calc(x - 1, Y, mod1) + calc(x - 1, y - 1, mod1);
  long long ans2 = calc(X, Y, mod2) - calc(X, y - 1, mod2) -
                   calc(x - 1, Y, mod2) + calc(x - 1, y - 1, mod2);
  ans1 = (ans1 % mod1 + mod1) % mod1;
  ans2 = (ans2 % mod2 + mod2) % mod2;
  if (ans1 == ans2) {
    writeln(ans1);
  } else if (ans1 > 10000000000) {
    putchar('.'), putchar('.'), putchar('.');
    writeln(ans1);
  } else {
    putchar('.'), putchar('.'), putchar('.');
    for (int i = 1000000000; i >= 1; i /= 10)
      if (ans1 <= i) putchar('0');
    writeln(ans1);
  }
}
int main() {
  int T = read();
  while (T--) solve();
}
