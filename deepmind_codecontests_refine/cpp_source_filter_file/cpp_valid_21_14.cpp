#include <bits/stdc++.h>
namespace FastRead {
char __buff[5000];
long long __lg = 0, __p = 0;
char nc() {
  if (__lg == __p) {
    __lg = fread(__buff, 1, 5000, stdin);
    __p = 0;
    if (!__lg) return EOF;
  }
  return __buff[__p++];
}
template <class T>
void read(T& __x) {
  T __sgn = 1;
  char __c;
  while (!isdigit(__c = nc()))
    if (__c == '-') __sgn = -1;
  __x = __c - '0';
  while (isdigit(__c = nc())) __x = __x * 10 + __c - '0';
  __x *= __sgn;
}
}  // namespace FastRead
using namespace FastRead;
using namespace std;
const long long N = 2e5 + 10;
const long long M = 998244353;
const long double PI = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long n;
struct portal {
  long long x, y;
  bool state;
} a[N];
long long dp[N], Time[N];
long long bs(long long x) {
  long long l = 1, r = n, mid = 0, ans = 0;
  while (l <= r) {
    mid = (l + r) / 2;
    if (a[mid].x > x)
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  return ans;
}
signed main() {
  long long i;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i].x >> a[i].y >> a[i].state;
  for (i = 1; i <= n; i++) {
    long long np = bs(a[i].y);
    long long period = (dp[i - 1] - dp[np - 1] + M) % M;
    dp[i] = (period + a[np].x - a[i].y + a[i].x - a[np].x) % M;
    Time[i] = (Time[i - 1] + dp[i] + a[i].x - a[i - 1].x) % M;
    dp[i] = (dp[i] + dp[i - 1]) % M;
  }
  long long ans = 0;
  for (i = 1; i <= n; i++)
    if (a[i].state)
      ans = (ans + Time[i] - Time[i - 1] + M) % M;
    else
      ans = (ans + a[i].x - a[i - 1].x) % M;
  cout << ans + 1;
  return 0;
}
