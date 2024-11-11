#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  register char ch = getchar();
  register bool f = false;
  x = 0;
  while (!isdigit(ch)) {
    if (ch == '-') {
      f = true;
    }
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  x = f ? -x : x;
  return;
}
long long const N = 2e2 + 5;
long long dp[N][10000], a[N], fi[N], tw[N];
long long getf(long long x) {
  long long ans = 0;
  while (x % 5 == 0) x /= 5, ans++;
  return ans;
}
long long get(long long x) {
  long long ans = 0;
  while (x % 2 == 0) x /= 2, ans++;
  return ans;
}
signed main() {
  long long n;
  read(n);
  long long cnt;
  read(cnt);
  for (long long i = 1; i <= n; i++) {
    read(a[i]);
    fi[i] = getf(a[i]), tw[i] = get(a[i]);
  }
  memset(dp, -0x3f, sizeof(dp));
  dp[0][0] = 0;
  for (long long i = 1; i <= n; i++) {
    for (long long j = min(i, cnt); j >= 1; j--) {
      for (long long k = 10000; k >= fi[i]; k--) {
        dp[j][k] = max(dp[j][k], dp[j - 1][k - fi[i]] + tw[i]);
      }
    }
  }
  long long ans = 0;
  for (long long i = 1; i <= 10000; i++) {
    ans = max(ans, min(i, dp[cnt][i]));
  }
  cout << ans << endl;
  return 0;
}
