#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  x = 0;
  char ch = getchar();
  bool f = false;
  while (!isdigit(ch)) {
    if (ch == '-') {
      f = true;
    }
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  x = f ? -x : x;
  return;
}
template <typename T>
inline void write(T x) {
  if (x < 0) putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 ^ 48);
  return;
}
const int N = 1000005, M = 1e5 + 5, MOD = 1e8 + 7;
long long n, c, a[N], que[N], hh, tt, sum, dp[N];
int main() {
  read(n), read(c);
  for (int i = 1; i <= n; i++) read(a[i]), sum += a[i];
  hh = 1;
  for (int i = 1; i <= n; i++) {
    while (hh <= tt && que[hh] + c <= i) hh++;
    while (hh <= tt && a[que[tt]] >= a[i]) tt--;
    que[++tt] = i;
    if (i >= c) dp[i] = max(dp[i - 1], dp[i - c] + a[que[hh]]);
  }
  write(sum - dp[n]);
  return 0;
}
