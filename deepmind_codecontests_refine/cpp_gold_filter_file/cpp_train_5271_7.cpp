#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5;
inline long long read() {
  long long s = 0;
  register bool neg = 0;
  register char c = getchar();
  for (; c < '0' || c > '9'; c = getchar()) neg |= (c == '-');
  for (; c >= '0' && c <= '9'; s = s * 10 + (c ^ 48), c = getchar())
    ;
  s = (neg ? -s : s);
  return s;
}
long long a, b, s[N + 10], ans;
bool dp[N + 10];
inline bool check(long long n) {
  memset(dp, 0, sizeof(dp));
  if (s[b] - s[1] > n) return false;
  long long l = 1, r = 1;
  dp[0] = dp[b] = 1;
  long long sum = 1;
  for (long long i = b + 1; i <= a; i++) {
    while (s[i] - s[l] > n) {
      sum -= dp[l - 1];
      l++;
    }
    r++;
    sum += dp[r - 1];
    dp[i] = (sum > 0);
  }
  return dp[a];
}
signed main() {
  a = read();
  b = read();
  for (long long i = 1; i <= a; i++) s[i] = read();
  sort(s + 1, s + a + 1);
  long long l = 0, r = s[a] - s[1];
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (check(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%lld", ans);
  return 0;
}
