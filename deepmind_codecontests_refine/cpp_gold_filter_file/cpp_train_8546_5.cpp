#include <bits/stdc++.h>
using namespace std;
const long long NR = 805 + 10;
const long long INF = 0x3f3f3f3f;
long long n, ans;
long long a[NR];
long long to[NR * NR << 1], nxt[NR * NR << 1], val[NR * NR << 1];
long long head[NR << 1];
long long tot = 1;
void add(long long x, long long y, long long z) {
  to[tot] = y;
  val[tot] = z;
  nxt[tot] = head[x];
  head[x] = tot++;
}
long long dep[NR], now[NR];
bool bfs() {
  memcpy(now, head, sizeof(now));
  memset(dep, 0, sizeof(dep));
  dep[0] = 1;
  queue<long long> q;
  q.push(0);
  while (!q.empty()) {
    long long x = q.front();
    q.pop();
    for (long long i = head[x]; i; i = nxt[i]) {
      long long y = to[i];
      if (!val[i] || dep[y]) continue;
      dep[y] = dep[x] + 1;
      if (y == 2 * n + 1) return 1;
      q.push(y);
    }
  }
  return 0;
}
long long dinic(long long x, long long flow) {
  if (x == 2 * n + 1) return flow;
  long long ans = 0;
  for (long long i = now[x]; i; i = nxt[i]) {
    long long y = to[i];
    now[x] = i;
    if (dep[y] != dep[x] + 1 || !val[i]) continue;
    if (flow - ans <= 0) break;
    long long num = dinic(y, min(flow - ans, val[i]));
    if (!num) dep[y] = 0;
    ans += num;
    val[i] -= num;
    val[i * 2 - (i ^ 1)] += num;
  }
  return ans;
}
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
signed main() {
  n = read();
  for (long long i = 1, x, t; i <= n; i++) {
    t = read();
    while (t--) {
      x = read();
      add(i, x + n, INF);
      add(x + n, i, 0);
    }
  }
  for (long long i = 1; i <= n; i++)
    a[i] = read(), ans -= a[i], add(0, i, -a[i] + INF), add(i, 0, 0),
    add(i + n, 2 * n + 1, INF), add(2 * n + 1, i + n, 0);
  long long flow = 0;
  while (bfs()) flow -= dinic(0, (long long)(1e18));
  printf("%lld\n", (-flow - INF * n) - ans);
  return 0;
}
