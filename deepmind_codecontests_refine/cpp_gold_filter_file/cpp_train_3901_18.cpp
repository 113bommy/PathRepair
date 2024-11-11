#include <bits/stdc++.h>
using namespace std;
long long n, l, s, tot, dp[100005], stx[100005][25], stn[100005][25];
inline long long read() {
  long long q = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = 0;
    ch = getchar();
  }
  while (isdigit(ch)) {
    q = (q << 3) + (q << 1) + (ch ^ 48);
    ch = getchar();
  }
  return f ? q : -q;
}
inline void print(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) print(x / 10);
  putchar(x % 10 + 48);
}
inline long long query(long long ll, long long rr) {
  long long anss = 0;
  while (1 << (anss + 1) <= rr - ll + 1) ++anss;
  return max(stx[ll][anss], stx[rr - (1 << anss) + 1][anss]) -
         min(stn[ll][anss], stn[rr - (1 << anss) + 1][anss]);
}
signed main() {
  n = read(), s = read(), l = read(), memset(dp, 0x3f, sizeof(dp)), dp[0] = 0;
  for (register long long i = 1; i <= n; ++i) stx[i][0] = stn[i][0] = read();
  for (register long long j = 1; (1 << j) <= n; ++j)
    for (register long long i = 1; i + (1 << j) - 1 <= n; ++i)
      stx[i][j] = max(stx[i][j - 1], stx[i + (1 << (j - 1))][j - 1]),
      stn[i][j] = min(stn[i][j - 1], stn[i + (1 << (j - 1))][j - 1]);
  for (register long long i = l; i <= n; ++i) {
    while (i - tot >= l && (query(tot + 1, i) > s || dp[tot] > 1e9)) ++tot;
    if (i - tot >= l) dp[i] = min(dp[i], dp[tot] + 1);
  }
  if (dp[n] < 1e9)
    print(dp[n]);
  else
    putchar('-'), putchar('1');
  return 0;
}
