#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool upmin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
inline bool upmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
const long double eps = 1e-11;
const long double pi = acos(-1);
const long long oo = 1 << 30;
const long long loo = 1ll << 62;
const long long mods = 998244353;
const long long MAXN = 200005;
const long long INF = 0x3f3f3f3f;
inline long long read() {
  long long f = 1, x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
long long Ans[1005], num = 0;
long long solve(long long x, long long y) {
  if (!y) return x;
  Ans[++num] = x / y;
  long long t = solve(y, x % y);
  return t;
}
signed main() {
  long long x = read(), y = read();
  if (solve(x, y) != 1) {
    puts("Impossible");
    return 0;
  }
  Ans[num]--;
  for (long long i = 1; i <= num; i++)
    if (Ans[i] > 0) printf("%d", Ans[i]), putchar(66 - (i & 1));
  return 0;
}
