#include <bits/stdc++.h>
using namespace std;
inline void Swap(long long &x, long long &y) {
  long long Temp = x;
  x = y;
  y = Temp;
}
inline long long Min(long long x, long long y) { return x < y ? x : y; }
inline long long Max(long long x, long long y) { return x > y ? x : y; }
inline void read(long long &x) {
  x = 0;
  long long f = 1;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = (x << 3) + (x << 1) + (s ^ 48);
    s = getchar();
  }
  x *= f;
}
long long dp[205][205 * 30], a[205], Five[205], Two[205];
inline long long Count(long long x, long long y) {
  long long Res = 0;
  while (x % y == 0) {
    Res++;
    x /= y;
  }
  return Res;
}
int main() {
  long long n, k;
  read(n);
  read(k);
  for (register int i = 1; i <= n; ++i) {
    read(a[i]);
    Five[i] = Count(a[i], 5);
    Two[i] = Count(a[i], 2);
  }
  memset(dp, -1, sizeof dp);
  dp[0][0] = 0;
  for (register int i = 1; i <= n; ++i)
    for (register int j = i; j >= 1; --j)
      for (register int k = i * 30; k >= Five[i]; --k)
        if (~dp[j - 1][k - Five[i]])
          dp[j][k] = Max(dp[j][k], dp[j - 1][k - Five[i]] + Two[i]);
  long long Ans = 0;
  for (register int i = 1; i <= 30 * n; ++i) Ans = Max(Ans, Min(i, dp[k][i]));
  printf("%lld", Ans);
  return 0;
}
