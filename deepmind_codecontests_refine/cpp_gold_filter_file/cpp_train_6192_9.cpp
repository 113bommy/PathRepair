#include <bits/stdc++.h>
using namespace std;
const int N = 310;
const int inf = 0x3f3f3f3f;
int n;
int l[N], c[N], b[N], a[N];
int dp[N * 10];
int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }
signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &l[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
  int ans = l[1];
  for (int i = 2; i <= n; i++) ans = gcd(ans, l[i]);
  if (ans != 1) {
    puts("-1");
    return 0;
  }
  ans = inf;
  for (int i = 1; i <= n; i++) {
    b[i] = 0;
    int p = l[i];
    int cnt = 0;
    for (int j = 2; j * j <= p; j++) {
      if (p % j == 0) {
        a[++cnt] = j;
        b[i] += (1 << (cnt - 1));
        while (p % j == 0) p /= j;
      }
    }
    if (p > 1) {
      a[++cnt] = p;
      b[i] += (1 << (cnt - 1));
    }
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      b[j] = 0;
      for (int k = 1; k <= cnt; k++) {
        if (l[j] % a[k] == 0) {
          b[j] += (1 << (k - 1));
        }
      }
    }
    memset(dp, inf, sizeof dp);
    dp[b[i]] = c[i];
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      for (int k = 0; k <= b[i]; k++) {
        dp[k & b[j]] = min(dp[k & b[j]], dp[k] + c[j]);
      }
    }
    ans = min(ans, dp[0]);
  }
  cout << ans << endl;
  return 0;
}
