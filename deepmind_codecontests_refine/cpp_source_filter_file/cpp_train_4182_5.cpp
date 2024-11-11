#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 1;
long long n, m, tot = 1, tag, q, u, v, w, x, t, head[maxn + 1],
                suc[maxn << 1 | 1], len[maxn << 1 | 1], to[maxn << 1 | 1],
                from[maxn << 1 | 1], dis[maxn + 1][2], path[maxn + 1],
                last[maxn + 1], bound[maxn + 1][2], tree[maxn << 3 | 1];
bool vis[maxn + 1], in[maxn << 1 | 1];
inline void add_edge(long long x, long long y, long long z) {
  suc[++tot] = head[x];
  from[tot] = x;
  to[tot] = y;
  len[tot] = z;
  head[x] = tot;
  return;
}
void Dijkstra(long long now, long long opt1, long long opt2) {
  priority_queue<pair<long long, pair<long long, long long> >,
                 vector<pair<long long, pair<long long, long long> > >,
                 greater<pair<long long, pair<long long, long long> > > >
      que;
  memset(vis, 0, sizeof vis);
  dis[now][opt1] = 0;
  que.push(make_pair(0, make_pair(now, -1)));
  while (!que.empty()) {
    long long top = que.top().second.first, pos = que.top().second.second;
    que.pop();
    if (vis[top]) continue;
    vis[top] = true;
    if (opt2 && pos != -1 && !in[pos])
      bound[now][opt1] = bound[from[pos]][opt1];
    for (long long i = head[top]; ~i; i = suc[i])
      if (dis[to[i]][opt1] > dis[top][opt1] + len[i]) {
        dis[to[i]][opt1] = dis[top][opt1] + len[i];
        que.push(make_pair(dis[to[i]][opt1], make_pair(to[i], i)));
        if (opt2) continue;
        path[to[i]] = i;
        last[to[i]] = top;
      }
  }
  return;
}
inline void pushdown(long long now) {
  tree[now << 1] = min(tree[now << 1], tree[now]);
  tree[now << 1 | 1] = min(tree[now << 1 | 1], tree[now]);
  return;
}
void change(long long now, long long l, long long r, long long target_l,
            long long target_r, long long value) {
  if (target_l > target_r || r < target_l || l > target_r) return;
  if (target_l <= l && target_r >= r) {
    tree[now] = min(tree[now], value);
    return;
  }
  long long mid = (l + r) >> 1;
  pushdown(now);
  change(now << 1, l, mid, target_l, target_r, value);
  change(now << 1 | 1, mid + 1, r, target_l, target_r, value);
  return;
}
long long query(long long now, long long l, long long r, long long target_l,
                long long target_r) {
  if (l > r || r < target_l || l > target_r) return 0x3f3f3f3f3f3f3f3fll;
  if (target_l <= l && target_r >= r) return tree[now];
  long long mid = (l + r) >> 1;
  pushdown(now);
  return min(query(now << 1, l, mid, target_l, target_r),
             query(now << 1 | 1, mid + 1, r, target_l, target_r));
}
signed main() {
  memset(head, -1, sizeof head);
  memset(dis, 0x3f, sizeof dis);
  memset(tree, 0x3f, sizeof tree);
  scanf("%lld%lld%lld", &n, &m, &q);
  for (long long i = 1; i <= m; ++i) {
    scanf("%lld%lld%lld", &u, &v, &w);
    add_edge(u, v, w);
    add_edge(v, u, w);
  }
  Dijkstra(1, 0, 0);
  path[1] = -1;
  for (long long i = n; i; i = last[i]) {
    if (~path[i]) in[path[i]] = in[path[i] ^ 1] = true;
    bound[last[i]][0] = bound[i][1] = ++tag;
  }
  memset(dis, 0x3f, sizeof dis);
  Dijkstra(1, 0, 1);
  Dijkstra(n, 1, 1);
  for (long long i = 1; i <= n; ++i)
    for (long long j = head[i]; ~j; j = suc[j])
      if (!in[j])
        change(1, 1, n, bound[to[j]][1], bound[i][0],
               dis[i][0] + len[j] + dis[to[j]][1]);
  while (q--) {
    scanf("%lld%lld", &t, &x);
    if (!in[t << 1])
      printf("%lld\n", min(dis[n][0],
                           min(dis[from[t << 1]][0] + x + dis[to[t << 1]][1],
                               dis[from[t << 1]][1] + x + dis[to[t << 1]][0])));
    else
      printf(
          "%lld\n",
          min(min(query(1, 1, n, bound[from[t << 1]][1], bound[to[t << 1]][0]),
                  query(1, 1, n, bound[to[t << 1]][1], bound[from[t << 1]][0])),
              min(dis[from[t << 1]][0] + x + dis[to[t << 1]][1],
                  dis[from[t << 1]][1] + x + dis[to[t << 1]][0])));
  }
  return 0;
}
