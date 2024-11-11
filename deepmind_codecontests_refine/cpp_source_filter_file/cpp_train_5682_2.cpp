#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void wrote(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) wrote(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(long long x) {
  wrote(x);
  puts("");
}
const long long N = 60;
long long answ, n;
long long dp(long long one, long long la, long long lb, long long remain) {
  static long long f[N][2], las[N][2];
  memset(f, 0, sizeof f);
  f[0][0] = 1;
  for (long long i = 0; (1ll << i) <= remain; ++i) {
    memcpy(las, f, sizeof f);
    memset(f, 0, sizeof f);
    for (long long ca = 0; ca <= (i < la); ++ca)
      for (long long cb = 0; cb <= (i < lb); ++cb)
        for (long long re = 0; re <= 1; ++re) {
          long long now = ca + cb + re;
          if ((now & 1) ^ ((remain >> i) & 1)) continue;
          for (long long al = 0; al <= one - ca - cb; ++al)
            f[al + ca + cb][now >> 1] += las[al][re];
        }
  }
  return f[one][0];
}
int main() {
  n = read();
  for (long long len_a = 0; len_a <= 58; ++len_a)
    for (long long len_b = 0; len_b <= 58; ++len_b) {
      long long t = (1ll << len_a + 1) + (1ll << len_b + 1) - 3;
      long long lca = n / t;
      if (!lca) continue;
      long long res = n - lca * t - ((1ll << len_b) - 1);
      for (long long one = 0; one <= len_a + len_b; ++one) {
        long long remain = res + one;
        if (remain < 0 || remain % 2 == 1) continue;
        remain >>= 1;
        answ += dp(one, max(len_a - 1, 0LL), max(len_b - 1, 0LL), remain);
      }
    }
  writeln(answ);
}
