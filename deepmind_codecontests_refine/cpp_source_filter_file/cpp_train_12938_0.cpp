#include <bits/stdc++.h>
#pragma GCC optimize("-Ofast", "-funroll-all-loops")
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const long long N = 1010, M = 1e6 + 10, base = 1e12;
long long n, m, h[N], s, t, a[N], b[N], c[N], val[N], vis[N], res[N], ans[N][N];
long long head[N], nex[M], to[M], w[M], tot = 1;
inline void ade(long long a, long long b, long long c) {
  to[++tot] = b;
  nex[tot] = head[a];
  w[tot] = c;
  head[a] = tot;
}
inline void add(long long a, long long b, long long c) {
  ade(a, b, c);
  ade(b, a, 0);
}
inline long long bfs() {
  queue<long long> q;
  q.push(s);
  memset(h, 0, sizeof h);
  h[s] = 1;
  while (q.size()) {
    long long u = q.front();
    q.pop();
    for (long long i = head[u]; i; i = nex[i])
      if (w[i] && !h[to[i]]) h[to[i]] = h[u] + 1, q.push(to[i]);
  }
  return h[t];
}
long long dfs(long long x, long long f) {
  if (x == t) return f;
  long long fl = 0;
  for (long long i = head[x]; i && f; i = nex[i]) {
    if (w[i] && h[to[i]] == h[x] + 1) {
      long long mi = dfs(to[i], min(w[i], f));
      w[i] -= mi, w[i ^ 1] += mi, fl += mi, f -= mi;
    }
  }
  if (!fl) h[x] = -1;
  return fl;
}
void dfs(long long x) {
  vis[x] = 1;
  for (long long i = head[x]; i; i = nex[i])
    if (!vis[to[i]] && w[i]) dfs(to[i]);
}
signed main() {
  cin >> n >> m;
  t = n * (n + 1) + 1;
  for (long long i = 1; i <= m; i++)
    cin >> a[i] >> b[i] >> c[i], val[a[i]] += w[i], val[b[i]] -= w[i];
  for (long long i = 1; i <= n; i++) {
    add(s, (i - 1) * (n + 1) + 1, inf);
    for (long long j = 0; j < n; j++)
      add((i - 1) * (n + 1) + j + 1, (i - 1) * (n + 1) + j + 2,
          j * val[i] + base),
          ans[(i - 1) * (n + 1) + j + 1][(i - 1) * (n + 1) + j + 2] = j;
    add((i - 1) * (n + 1) + n + 1, t, inf);
  }
  for (long long i = 1; i <= m; i++) {
    for (long long j = 0; j < n; j++)
      add((b[i] - 1) * (n + 1) + j + 1, (a[i] - 1) * (n + 1) + j + 2, inf);
  }
  while (bfs()) dfs(s, inf);
  dfs(s);
  long long cnt = 0;
  set<long long> st;
  for (long long i = 1; i < t; i++)
    if (vis[i]) {
      for (long long j = head[i]; j; j = nex[j])
        if (!vis[to[j]] && to[j] != t && to[j] == i + 1) {
          cnt++;
          st.insert(i / (n + 1) + 1);
          res[i / (n + 1) + 1] = ans[i][to[j]];
        }
    }
  assert(st.size() == n);
  for (long long i = 1; i <= n; i++) printf("%lld ", res[i]);
  return 0;
}
