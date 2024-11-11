#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long sum = 0, ff = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') ff = -1;
    ch = getchar();
  }
  while (isdigit(ch)) sum = sum * 10 + (ch ^ 48), ch = getchar();
  return sum * ff;
}
const long long N = 2e5 + 5;
const long long inf = 1e9;
long long n, m, head[N], ans, lev[N];
long long cnt = 1, val[N], a[N], c[N], s, t;
struct nood {
  long long nex, to;
};
nood e[N << 1];
inline void jia(long long u, long long v, long long w) {
  e[++cnt].nex = head[u];
  head[u] = cnt;
  e[cnt].to = v;
  val[cnt] = w;
}
inline bool bfs() {
  queue<long long> q;
  memset(lev, -1, sizeof(lev));
  lev[s] = 0;
  q.push(s);
  while (!q.empty()) {
    long long u = q.front();
    q.pop();
    for (long long i = head[u]; i; i = e[i].nex) {
      long long v = e[i].to;
      if (lev[v] == -1 && val[i]) {
        lev[v] = lev[u] + 1;
        q.push(v);
      }
    }
  }
  return (lev[t] != -1);
}
inline long long dinic(long long x, long long fl) {
  if (x == t) return fl;
  long long now = fl;
  for (long long i = head[x]; i; i = e[i].nex) {
    long long v = e[i].to;
    if (now <= 0) break;
    if (val[i] && lev[v] == lev[x] + 1) {
      long long mf = dinic(v, min(now, val[i]));
      now -= mf;
      val[i] -= mf;
      val[i ^ 1] += mf;
    }
  }
  return fl - now;
}
signed main() {
  n = read();
  m = read();
  long long g = read();
  s = 0, t = n + m + 1;
  for (long long i = 1; i <= n; i++) a[i] = read();
  for (long long i = 1; i <= n; i++) {
    c[i] = read();
    if (a[i])
      jia(i, t, c[i]), jia(t, i, 0);
    else
      jia(s, i, c[i]), jia(i, s, 0);
  }
  for (long long i = 1; i <= m; i++) {
    long long op, w, ok, gs;
    op = read(), w = read();
    gs = read();
    ans += w;
    if (op) {
      for (long long j = 1; j <= gs; j++) {
        long long z = read();
        jia(z, i + n, inf);
        jia(i + n, z, 0);
      }
      ok = read();
      if (ok)
        jia(i + n, t, g + w), jia(t, i + n, 0);
      else
        jia(i + n, t, w), jia(t, i + n, 0);
    } else {
      for (long long j = 1; j <= gs; j++) {
        long long z = read();
        jia(i + n, z, inf);
        jia(z, i + n, 0);
      }
      ok = read();
      if (ok)
        jia(s, i + n, g + w), jia(i + n, s, 0);
      else
        jia(s, i + n, w), jia(i + n, s, 0);
    }
  }
  long long sum = 0;
  while (bfs()) sum += dinic(s, inf);
  printf("%lld\n", ans - sum);
  return 0;
}
