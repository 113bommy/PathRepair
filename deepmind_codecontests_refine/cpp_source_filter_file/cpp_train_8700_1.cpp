#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long num = 0, neg = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') neg = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    num = (num << 3) + (num << 1) + c - '0';
    c = getchar();
  }
  return num * neg;
}
long long n, maze[2][300010], a[300010], b[300010], c[300010], tmp[1000010],
    cnt;
long long pre[3][300010], used[1000010], dp[300010];
map<pair<long long, long long>, long long> f, vis;
inline long long get(long long x, long long y) {
  pair<long long, long long> u = make_pair(x, y);
  if (vis[u]) return f[u];
  f[u] = dp[min(x, y)];
  if (x >= y && pre[0][x] >= 0) f[u] = max(f[u], get(pre[0][x], y) + 1);
  if (y >= x && pre[1][y] >= 0) f[u] = max(f[u], get(x, pre[1][y]) + 1);
  vis[u] = 1;
  return f[u];
}
signed main() {
  n = read();
  for (long long i = 1; i <= n; i++) maze[0][i] = read();
  for (long long i = 1; i <= n; i++) maze[1][i] = read();
  for (long long i = 1; i <= n; i++)
    a[i] = a[i - 1] + maze[0][i], tmp[++cnt] = a[i];
  for (long long i = 1; i <= n; i++)
    b[i] = b[i - 1] + maze[1][i], tmp[++cnt] = b[i];
  for (long long i = 1; i <= n; i++)
    c[i] = c[i - 1] + maze[0][i] + maze[1][i], tmp[++cnt] = c[i];
  tmp[++cnt] = 0;
  sort(tmp + 1, tmp + cnt + 1);
  cnt = unique(tmp + 1, tmp + cnt + 1) - tmp - 1;
  pre[0][0] = pre[1][0] = pre[2][0] = -1;
  memset(used, -1, sizeof(used));
  used[lower_bound(tmp + 1, tmp + cnt + 1, 0) - tmp] = 0;
  for (long long i = 1; i <= n; i++) {
    a[i] = lower_bound(tmp + 1, tmp + cnt + 1, a[i]) - tmp;
    pre[0][i] = max(pre[0][i - 1], used[a[i]]);
    used[a[i]] = i;
  }
  memset(used, -1, sizeof(used));
  used[lower_bound(tmp + 1, tmp + cnt + 1, 0) - tmp] = 0;
  for (long long i = 1; i <= n; i++) {
    b[i] = lower_bound(tmp + 1, tmp + cnt + 1, b[i]) - tmp;
    pre[1][i] = max(used[b[i]], pre[1][i - 1]);
    used[b[i]] = i;
  }
  memset(used, -1, sizeof(used));
  used[lower_bound(tmp + 1, tmp + cnt + 1, 0) - tmp] = 0;
  for (long long i = 1; i <= n; i++) {
    c[i] = lower_bound(tmp + 1, tmp + cnt + 1, c[i]) - tmp;
    pre[2][i] = max(pre[2][i - 1], used[c[i]]);
    used[c[i]] = i;
  }
  f[make_pair(0, 0)] = 0;
  vis[make_pair(0, 0)] = 1;
  for (long long i = 1; i <= n; i++) {
    if (pre[2][i]) dp[i] = dp[pre[2][i]] + 1;
    dp[i] = max(dp[i], get(i, i));
  }
  printf("%lld\n", dp[n]);
  return 0;
}
