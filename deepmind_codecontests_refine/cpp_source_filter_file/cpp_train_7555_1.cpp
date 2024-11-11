#include <bits/stdc++.h>
using namespace std;
long long dis[2000002];
bool vis[2000002];
long long root1, root2;
long long n, m, s, tot, cnt;
long long head[2000002], nxt[2000002];
long long point[2000002], edge[2000002];
struct nod {
  long long l, r, ls, rs;
} node[2000002];
void add(long long x, long long y, long long z) {
  point[++tot] = y;
  nxt[tot] = head[x];
  head[x] = tot;
  edge[tot] = z;
}
namespace seg_tree_with_edge {
void build1(long long l, long long r, long long &cur) {
  if (l == r) {
    cur = l;
    node[cur].l = l;
    node[cur].r = r;
  } else {
    cur = ++cnt;
    node[cur].l = l;
    node[cur].r = r;
    long long mid = (l + r) >> 1;
    build1(l, mid, node[cur].ls);
    build1(mid + 1, r, node[cur].rs);
    add(cur, node[cur].ls, 0);
    add(cur, node[cur].rs, 0);
  }
}
void build2(long long l, long long r, long long &cur) {
  if (l == r) {
    cur = l;
    node[cur].l = l;
    node[cur].r = r;
  } else {
    cur = ++cnt;
    node[cur].l = l;
    node[cur].r = r;
    long long mid = (l + r) >> 1;
    build2(l, mid, node[cur].ls);
    build2(mid + 1, r, node[cur].rs);
    add(node[cur].ls, cur, 0);
    add(node[cur].rs, cur, 0);
  }
}
void init(long long sign, long long cur, long long l, long long r, long long to,
          long long w) {
  if (l <= node[cur].l && node[cur].r <= r) {
    if (sign)
      add(cur, to, w);
    else
      add(to, cur, w);
  } else {
    long long mid = (node[cur].l + node[cur].r) >> 1;
    if (l <= mid) init(sign, node[cur].ls, l, r, to, w);
    if (mid < r) init(sign, node[cur].rs, l, r, to, w);
  }
}
}  // namespace seg_tree_with_edge
using namespace seg_tree_with_edge;
void spfa(long long st) {
  memset(dis, 0x3f, sizeof(dis));
  dis[st] = 0;
  queue<long long> q;
  q.push(st);
  while (!q.empty()) {
    long long u = q.front();
    q.pop();
    vis[u] = false;
    for (long long i = head[u]; i; i = nxt[i]) {
      long long v = point[i];
      if (dis[v] > dis[u] + edge[i]) {
        dis[v] = dis[u] + edge[i];
        if (!vis[v]) {
          vis[v] = 1;
          q.push(v);
        }
      }
    }
  }
}
void prin(long long x) {
  if (x >= 0x3f3f3f3f)
    printf("-1 ");
  else
    printf("%lld ", x);
}
signed main() {
  scanf("%lld%lld%lld", &n, &m, &s);
  cnt = n;
  build1(1, n, root1);
  build2(1, n, root2);
  for (long long i = 1; i <= m; i++) {
    long long opt, u, v, w, l, r;
    scanf("%lld", &opt);
    if (opt == 1) {
      scanf("%lld%lld%lld", &u, &v, &w);
      add(u, v, w);
    } else if (opt == 2) {
      scanf("%lld%lld%lld%lld", &v, &l, &r, &w);
      init(0, root1, l, r, v, w);
    } else if (opt == 3) {
      scanf("%lld%lld%lld%lld", &v, &l, &r, &w);
      init(1, root2, l, r, v, w);
    }
  }
  spfa(s);
  for (long long i = 1; i <= n; i++) prin(dis[i]);
  return 0;
}
