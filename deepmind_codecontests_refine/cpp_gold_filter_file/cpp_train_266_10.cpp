#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, w = 0;
  char ch = getchar();
  while (!isdigit(ch)) w |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
  return w ? -x : x;
}
long long cnt[1 << 20], f[1 << 20], dis[310000], l[310000], d[40][40], n, m, k,
    vis[310000], loc[310000], tot;
void bfs(long long s) {
  memset(dis, 0x3f, sizeof(dis));
  queue<long long> q;
  q.push(loc[s]);
  dis[loc[s]] = 0;
  while (!q.empty()) {
    long long u = q.front();
    q.pop();
    for (long long i = 1; i <= k; ++i) {
      long long v = u + l[i];
      if (v <= n + 1 && dis[v] > dis[u] + 1) {
        dis[v] = dis[u] + 1;
        q.push(v);
      }
      v = u - l[i];
      if (v >= 1 && dis[v] > dis[u] + 1) {
        dis[v] = dis[u] + 1;
        q.push(v);
      }
    }
  }
  for (long long i = 1; i <= tot; ++i) d[s][i] = dis[loc[i]];
}
signed main() {
  n = read(), m = read(), k = read();
  for (long long i = 1; i <= m; ++i) {
    long long d = read();
    vis[d] = 1;
  }
  for (long long i = 1; i <= n + 1; ++i)
    if (vis[i] ^ vis[i - 1]) loc[++tot] = i;
  if (tot == 0) {
    puts("0");
    return 0;
  }
  for (long long i = 1; i <= k; ++i) l[i] = read();
  for (long long i = 1; i <= tot; ++i) bfs(i);
  for (long long s = 1; s < (1 << tot); ++s) cnt[s] = cnt[s ^ (s & (-s))] + 1;
  memset(f, 0x3f, sizeof(f));
  f[0] = 0;
  for (long long s = 0; s < (1 << tot); ++s)
    if (!(cnt[s] & 1)) {
      long long k = ((1 << tot) - 1) ^ s;
      if (k == 0) continue;
      k = log2(k & (-k)) + 1;
      for (long long i = k + 1; i <= tot; ++i)
        if (!(s & (1 << i - 1))) {
          long long ns = (s | (1 << k - 1) | (1 << i - 1));
          f[ns] = min(f[ns], f[s] + d[i][k]);
        }
    }
  printf("%d\n", f[(1 << tot) - 1] >= 0x3f3f3f3f ? -1 : f[(1 << tot) - 1]);
  return 0;
}
