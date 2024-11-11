#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long INF = 2e16;
const long long maxn = 1e6 + 5;
const double Pi = acos(-1.0);
double Exp = 1e-6;
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
long long n;
long long a[maxn];
long long cnt1 = 0, cnt2 = 0;
long long ans = 1;
long long dp[maxn];
signed main() {
  n = read();
  for (long long i = 1; i <= n; i++) {
    a[i] = read();
    if (a[i] == 1)
      cnt1++;
    else
      cnt2++;
  }
  dp[0] = 1;
  dp[1] = 1, dp[2] = 2;
  for (long long i = 3; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2] * (i - 1);
  }
  for (long long i = 1; i <= cnt2; i++) {
    ans = ans * (n - i + 1) % mod;
  }
  ans = ans * dp[cnt1] % mod;
  printf("%lld\n", ans);
  return 0;
}
