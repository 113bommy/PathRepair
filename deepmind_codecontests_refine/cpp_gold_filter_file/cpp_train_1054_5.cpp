#include <bits/stdc++.h>
using namespace std;
long long n, q, head[500500], cnt, sd[500500], flag[500500 << 2], num;
long long mi[500500 << 3], depth[500500 << 2], tag[500500 << 3], size[500500];
long long stand = 1e18;
vector<pair<long long, long long> > side[500500];
struct node {
  long long v, l, r;
  long long ans;
  long long id;
} qu[500500];
void dfs1(long long now, long long fa) {
  size[now] = 1;
  if ((now == 1 && sd[now] == 0) || (now != 1 && sd[now] == 1)) {
    flag[now] = 1;
    return;
  }
  for (long long i = 0; i < side[now].size(); i++) {
    long long v = side[now][i].first;
    if (v == fa) continue;
    depth[v] = depth[now] + side[now][i].second;
    dfs1(v, now);
    size[now] += size[v];
  }
}
void push_down(long long x) {
  tag[x << 1] += tag[x];
  tag[x << 1 | 1] += tag[x];
  mi[x << 1] += tag[x];
  mi[x << 1 | 1] += tag[x];
  tag[x] = 0;
  if (tag[x << 1] > stand) tag[x << 1] = stand;
  if (tag[x << 1 | 1] > stand) tag[x << 1 | 1] = stand;
  if (mi[x << 1] > stand) mi[x << 1] = stand;
  if (mi[x << 1 | 1] > stand) mi[x << 1 | 1] = stand;
}
void push_up(long long x) { mi[x] = min(mi[x << 1], mi[x << 1 | 1]); }
void change(long long l, long long r, long long root, long long tl,
            long long tr, long long val) {
  if (tl > tr) return;
  if (mi[root] >= stand) return;
  push_down(root);
  if (tl <= l && r <= tr) {
    if (tag[root] > stand) tag[root] = stand;
    if (mi[root] > stand) mi[root] = stand;
    tag[root] += val;
    mi[root] += val;
    return;
  }
  long long mid = (l + r) >> 1;
  if (tl <= mid) change(l, mid, root << 1, tl, tr, val);
  if (tr >= mid + 1) change(mid + 1, r, root << 1 | 1, tl, tr, val);
  push_up(root);
  return;
}
long long query(long long l, long long r, long long root, long long tl,
                long long tr) {
  push_down(root);
  if (tl <= l && r <= tr) {
    return mi[root];
  }
  long long tmp = stand + 1000;
  long long mid = (l + r) >> 1;
  if (tl <= mid) tmp = min(tmp, query(l, mid, root << 1, tl, tr));
  if (tr >= mid + 1) tmp = min(tmp, query(mid + 1, r, root << 1 | 1, tl, tr));
  return tmp;
}
bool cop(node x, node y) { return x.v < y.v; }
bool cop2(node x, node y) { return x.id < y.id; }
void dfs2(long long now, long long fa) {
  while (num < q && qu[num + 1].v == now) {
    num++;
    qu[num].ans = query(1, n, 1, qu[num].l, qu[num].r);
  }
  for (long long i = 0; i < side[now].size(); i++) {
    long long v = side[now][i].first;
    if (v == fa) continue;
    long long w = side[now][i].second;
    change(1, n, 1, v, v + size[v] - 1, -w);
    change(1, n, 1, 1, v - 1, w);
    change(1, n, 1, v + size[v], n, w);
    dfs2(v, now);
    change(1, n, 1, v, v + size[v] - 1, w);
    change(1, n, 1, 1, v - 1, -w);
    change(1, n, 1, v + size[v], n, -w);
  }
}
signed main() {
  scanf("%lld%lld", &n, &q);
  for (long long i = 2; i <= n; i++) {
    long long u, v, w;
    scanf("%lld%lld", &u, &w);
    side[u].push_back(make_pair(i, w));
    side[i].push_back(make_pair(u, w));
    sd[u]++;
    sd[i]++;
  }
  for (long long i = 1; i <= n; i++) sort(side[i].begin(), side[i].end());
  for (long long i = 1; i <= q; i++) {
    scanf("%lld%lld%lld", &qu[i].v, &qu[i].l, &qu[i].r);
    qu[i].id = i;
  }
  sort(qu + 1, qu + 1 + q, cop);
  dfs1(1, 0);
  for (long long i = 1; i <= n; i++) {
    if (flag[i]) {
      change(1, n, 1, i, i, depth[i]);
    } else {
      change(1, n, 1, i, i, stand + 1000);
    }
  }
  dfs2(1, 0);
  sort(qu + 1, qu + 1 + q, cop2);
  for (long long i = 1; i <= q; i++) {
    printf("%lld\n", qu[i].ans);
  }
  return 0;
}
