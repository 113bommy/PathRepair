#include <bits/stdc++.h>
using namespace std;
long long n, m, ans;
long long dis[2010][2010], c[2010][2010];
char s[2010][2010];
inline void solve(long long row, long long tl, long long tr, long long l,
                  long long r) {
  if (l > r) return;
  long long mid = (l + r) >> 1;
  dis[row][mid] = 1000000000;
  long long t = tl;
  for (long long i = tl; i <= tr; i++) {
    long long val = c[row][i] + (i - mid) * (i - mid);
    if (val < dis[row][mid]) {
      dis[row][mid] = val;
      t = i;
    }
  }
  solve(row, tl, t, l, mid - 1);
  solve(row, t, tr, mid + 1, r);
}
signed main() {
  scanf("%lld%lld", &n, &m);
  for (long long i = 0; i <= n; i++) scanf("%s", s[i]);
  for (long long i = 0; i <= n; i++) {
    for (long long j = 0; j <= m; j++) c[i][j] = 1000000000;
  }
  for (long long j = 0; j <= m; j++) {
    long long res = 1000;
    for (long long i = 0; i <= n; i++) {
      if (s[i][j] == '1') res = i;
      c[i][j] = min(c[i][j], (i - res) * (i - res));
    }
    res = 10000;
    for (long long i = n; ~i; i--) {
      if (s[i][j] == '1') res = i;
      c[i][j] = min(c[i][j], (i - res) * (i - res));
    }
  }
  for (long long i = 0; i <= n; i++) {
    solve(i, 0, m, 0, m);
    for (long long j = 0; j <= m; j++) ans += dis[i][j];
  }
  printf("%lld\n", ans);
  return 0;
}
