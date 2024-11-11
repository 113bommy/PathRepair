#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char ch;
  long long f = 1, x;
  while (ch = getchar(), !isdigit(ch))
    if (ch == '-') f = -1;
  x = (ch ^ 48);
  while (ch = getchar(), isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48);
  return x * f;
}
inline void write(long long x) {
  if (x < 0) {
    putchar('-');
    write(-x);
    return;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 ^ 48);
}
inline void writ(long long x) {
  write(x);
  puts("");
}
long long n, k;
long long a[2010], dp[2010][2010];
signed main() {
  long long T = read();
  while (T--) {
    memset(dp, 0, sizeof(dp));
    n = read(), k = read();
    for (long long i = (1); i <= (n); ++i) a[i] = read();
    for (long long i = (1); i <= (n); ++i)
      for (long long j = (0); j <= (i); ++j) {
        if (j == 0)
          dp[i][j] = max(dp[i][j], dp[i - 1][j] + (a[i] == i - j));
        else
          dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j] + (a[i] == i - j));
      }
    long long pos;
    for (long long i = (0); i <= (n + 1); ++i)
      if (dp[n][i] >= k) {
        pos = i;
        break;
      }
    writ(pos <= n ? pos : -1);
  }
  return 0;
}
