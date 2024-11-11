#include <bits/stdc++.h>
using namespace std;
const long long maxsN = 20010;
const long long maxsM = 200010;
struct bian {
  long long to;
  long long up;
  long long w;
} b[maxsM];
long long n, m, s, t, front[maxsN], l, ceng[maxsN], c[maxsN], g;
long long ans;
void add(long long x, long long y, long long w) {
  b[l].up = front[x];
  b[l].to = y;
  b[l].w = w;
  front[x] = l;
  l++;
  b[l].up = front[y];
  b[l].to = x;
  front[y] = l;
  l++;
}
bool bfs() {
  queue<long long> q;
  memset(ceng, 0, sizeof(ceng));
  ceng[s] = 1;
  q.push(s);
  while (!q.empty()) {
    long long now = q.front();
    q.pop();
    for (long long i = front[now]; i != -1; i = b[i].up) {
      if (ceng[b[i].to] == 0 && b[i].w > 0) {
        ceng[b[i].to] = ceng[now] + 1;
        q.push(b[i].to);
      }
    }
  }
  return ceng[t] <= 1 ? 0 : 1;
}
long long dfs(long long o, long long mins) {
  if (o == t) {
    return mins;
  }
  long long mi = 0;
  for (long long &i = c[o]; i != -1; i = b[i].up) {
    if (ceng[b[i].to] == ceng[o] + 1 && b[i].w != 0) {
      long long now = dfs(b[i].to, min(b[i].w, mins - mi));
      if (now != 0) {
        b[i].w -= now;
        b[i ^ 1].w += now;
        mi += now;
        if (mi == mins) break;
      }
    }
  }
  return mi;
}
void dinic() {
  while (bfs()) {
    memcpy(c, front, sizeof(c));
    ans += dfs(s, 1e18);
  }
}
long long a[maxsN];
signed main() {
  scanf("%lld%lld%lld", &n, &m, &g);
  s = 0;
  t = n + m + 1;
  for (long long i = 0; i <= t; i++) front[i] = -1;
  for (long long i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
  }
  for (long long i = 1; i <= n; ++i) {
    long long val;
    scanf("%lld", &val);
    if (a[i] == 0) {
      add(s, i, val);
    } else {
      add(i, t, val);
    }
  }
  long long zong = 0;
  for (long long i = 1; i <= m; ++i) {
    long long opt, w, k;
    scanf("%lld%lld%lld", &opt, &w, &k);
    if (opt == 0) {
      for (long long j = 1; j <= k; ++j) {
        long long pos;
        scanf("%lld", &pos);
        add(i + m, pos, 1e18);
      }
      long long sf;
      scanf("%lld", &sf);
      if (sf == 1)
        add(s, i + m, w + g);
      else
        add(s, i + m, w);
    } else {
      for (long long j = 1; j <= k; ++j) {
        long long pos;
        scanf("%lld", &pos);
        add(pos, i + m, 1e18);
      }
      long long sf;
      scanf("%lld", &sf);
      if (sf == 1)
        add(i + m, t, w + g);
      else
        add(i + m, t, w);
    }
    zong += w;
  }
  dinic();
  printf("%lld", zong - ans);
}
