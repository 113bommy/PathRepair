#include <bits/stdc++.h>
using std::min;
struct node {
  long long to, from, w, p, nxt, delta;
} edge[300100];
long long cnt, head[300100], size[300100], n;
void addedge(long long x, long long y, long long w, long long p) {
  edge[++cnt].from = x;
  edge[cnt].to = y;
  edge[cnt].w = w;
  edge[cnt].p = p;
  edge[cnt].nxt = head[x];
  head[x] = cnt;
}
void dfs1(long long x) {
  for (long long i = head[x]; i; i = edge[i].nxt) {
    long long upup = edge[i].to;
    dfs1(upup);
    size[x] += size[upup];
    long long minn = min(min(edge[i].w - 1, edge[i].p), edge[i].p - size[upup]);
    if (minn < 0) {
      puts("-1");
      exit(0);
    }
    edge[i].w -= minn;
    edge[i].p -= minn;
    edge[i].delta = minn;
    size[x] += edge[i].w;
  }
}
long long dfs2(long long x, long long val) {
  long long used = 0;
  for (long long i = head[x]; i; i = edge[i].nxt) {
    long long upup = edge[i].to;
    long long minn = min(edge[i].delta, val);
    edge[i].w += minn;
    edge[i].p += minn;
    val -= minn;
    used += minn;
    long long VAL = dfs2(upup, min(val, edge[i].p - size[upup]));
    val -= VAL;
    used += VAL;
  }
  return used;
}
signed main() {
  scanf("%lld", &n);
  for (long long i = 1, u, v, w, p; i < n; i++) {
    scanf("%lld%lld%lld%lld", &u, &v, &w, &p);
    addedge(u, v, w, p);
  }
  dfs1(1);
  dfs2(1, 1ll << 60);
  printf("%lld\n", n);
  for (long long i = 1; i <= cnt; i++)
    printf("%lld %lld %lld %lld\n", edge[i].from, edge[i].to, edge[i].w,
           edge[i].p);
  return 0;
}
