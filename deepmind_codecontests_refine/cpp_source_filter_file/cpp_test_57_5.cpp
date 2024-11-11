#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = '.';
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return f * x;
}
inline void chmax(long long &x, long long y) { x = max(x, y); }
inline void chmin(long long &x, long long y) { x = min(x, y); }
const long long MOD = 998244353;
inline long long add(long long x, long long y) {
  return (x + y >= MOD) ? (x + y - MOD)
                        : ((x + y < 0) ? (x + y + MOD) : (x + y));
}
long long s, n, k;
signed main() {
  long long test_case = read();
  while (test_case--) {
    s = read(), n = read(), k = read();
    if (s < k)
      puts("NO");
    else if (s == k)
      puts("YES");
    else {
      long long t = s / (2 * k) * k, c = t + min(s % (2 * k), k);
      if (c > n)
        puts("NO");
      else
        puts("YES");
    }
  }
  return 0;
}
