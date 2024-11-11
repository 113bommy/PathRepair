#include <bits/stdc++.h>
using namespace std;
long long n, m, T;
long long read() {
  long long x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x;
}
struct edge {
  long long v, w, next;
} e[100010 << 1];
long long eid, p[100010 << 1];
void insert(long long u, long long v, long long w) {
  e[++eid] = {v, w, p[u]};
  p[u] = eid;
}
struct BIT {
  long long sum[100010 << 4];
  long long lowbit(long long x) { return x & (-x); }
  void change(long long x, long long c) {
    for (; x <= m; x += lowbit(x)) sum[x] += c;
  }
  long long query(long long x) {
    long long ans = 0;
    for (; x; x -= lowbit(x)) ans += sum[x];
    return ans;
  }
} b1, b2;
long long dp[100010], x[100010], t[100010], dis[100010];
void dfs(long long u, long long f, long long d) {
  dis[u] = dis[f] + d;
  b1.change(t[u], x[u]);
  b2.change(t[u], t[u] * x[u]);
  long long l = 1, r = m, mid;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (b2.query(mid) > T - dis[u] * 2)
      r = mid - 1;
    else
      l = mid + 1;
  }
  dp[u] = b1.query(l - 1);
  if (l - 1 != m) dp[u] += (T - dis[u] * 2 - b2.query(l - 1)) / l;
  for (register long long i = p[u]; i; i = e[i].next) {
    long long v = e[i].v;
    if (v == f) continue;
    dfs(v, u, e[i].w);
  }
  b1.change(t[u], -x[u]);
  b2.change(t[u], -t[u] * x[u]);
}
long long ans[100010];
void DP(long long u, long long f) {
  long long fir = 0, sec = 0;
  for (register long long i = p[u]; i; i = e[i].next) {
    long long v = e[i].v;
    if (v == f) continue;
    DP(v, u);
    if (ans[v] >= fir)
      sec = fir, fir = ans[v];
    else if (ans[v] > sec)
      sec = ans[v];
  }
  if (u == 1)
    ans[u] = max(dp[u], fir);
  else
    ans[u] = max(dp[u], sec);
}
int main() {
  n = read(), T = read();
  for (register long long i = 1; i <= n; ++i) x[i] = read();
  for (register long long i = 1; i <= n; ++i) t[i] = read(), m = max(m, t[i]);
  for (register long long u = 2, v, w; u <= n; ++u) {
    v = read(), w = read();
    insert(u, v, w);
    insert(v, u, w);
  }
  dfs(1, 1, 0);
  DP(1, 1);
  cout << ans[1] << endl;
  return 0;
}
