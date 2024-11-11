#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long f = 1, ans = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ans = ans * 10 + c - '0';
    c = getchar();
  }
  return f * ans;
}
const long long N = 100001;
const long long K = 101;
long long dp[N][K], n, ans[N], cnt[K], del[K], a[N], k, len;
signed main() {
  n = read(), k = read(), len = read();
  if (k == 1) {
    cout << 0;
    return 0;
  }
  for (long long i = 1; i <= n; i++) a[i] = read();
  ans[0] = 1;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= k; j++) {
      if (a[i] == j || a[i] == -1) {
        dp[i][j] = (ans[i - 1] - del[j] + 2 * 998244353) % 998244353;
        cnt[j]++;
        if (cnt[j] >= len - 1)
          del[j] = ans[i - len + 1] - dp[i - len + 1][j],
          del[j] = (del[j] + 2 * 998244353) % 998244353;
        ans[i] += dp[i][j];
        ans[i] %= 998244353;
      } else {
        cnt[j] = 0;
        del[j] = 0;
      }
    }
  }
  printf("%lld\n", ans[n]);
}
