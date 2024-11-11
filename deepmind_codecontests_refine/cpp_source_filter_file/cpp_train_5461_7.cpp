#include <bits/stdc++.h>
using namespace std;
const int N = 210000;
int head[N], np[N], p[N], w[N], tot;
int sz[N];
inline void link(int a, int b, int c) {
  ++tot;
  p[tot] = b;
  np[tot] = head[a];
  head[a] = tot;
  w[tot] = c;
}
int n;
int root;
int Max[N];
void Getroot(int x) {
  sz[x] = 1;
  Max[x] = 0;
  for (int u = head[x]; u; u = np[u])
    if (!sz[p[u]]) {
      Getroot(p[u]);
      sz[x] += sz[p[u]];
      if (sz[p[u]] > Max[x]) Max[x] = sz[p[u]];
    }
  if (n - sz[x] > Max[x]) Max[x] = n - sz[x];
  if (!root || Max[x] < Max[root]) root = x;
}
long long ans = 0;
void Getans(int x, long long dis) {
  sz[x] = 1;
  ans += dis;
  for (int u = head[x]; u; u = np[u])
    if (!sz[p[u]]) {
      Getans(p[u], dis + 1ll * w[u]);
      sz[x] += sz[p[u]];
    }
}
int from[N];
vector<int> vals[N];
int d[N];
void dfs(int x, int fa, int bel) {
  vals[bel].push_back(x);
  from[x] = bel;
  d[bel] += 2;
  for (int u = head[x]; u; u = np[u])
    if (p[u] ^ fa) {
      dfs(p[u], x, bel);
    }
}
struct node {
  pair<int, int> Mival;
  pair<int, int> Mad;
  inline node(int num = 0, int d = 0, int theval = 0) {
    Mival = pair<int, int>(theval, num);
    Mad = pair<int, int>(d, num);
  }
} mes[N * 4];
inline node operator+(const node &a, const node &b) {
  node c = a;
  if (b.Mad > c.Mad) c.Mad = b.Mad;
  if (b.Mival < c.Mival) c.Mival = b.Mival;
  return c;
}
void del(int me, int l, int r, int x) {
  if (l == r) {
    mes[me].Mad.first--;
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid)
    del(me * 2, l, mid, x);
  else
    del(me * 2 + 1, mid + 1, r, x);
  mes[me] = mes[me * 2] + mes[me * 2 + 1];
}
void modify(int me, int l, int r, int x, int va) {
  if (l == r) {
    mes[me].Mival.first = va;
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid)
    modify(me * 2, l, mid, x, va);
  else
    modify(me * 2 + 1, mid + 1, r, x, va);
  mes[me] = mes[me * 2] + mes[me * 2 + 1];
}
node Get(int me, int l, int r, int x, int y) {
  if (x <= l && r <= y) return mes[me];
  int mid = (l + r) >> 1;
  if (x <= mid) {
    if (y > mid)
      return Get(me * 2, l, mid, x, y) + Get(me * 2 + 1, mid + 1, r, x, y);
    else
      return Get(me * 2, l, mid, x, y);
  } else
    return Get(me * 2 + 1, mid + 1, r, x, y);
}
void build(int me, int l, int r) {
  if (l == r) {
    mes[me] = node(l, d[l], vals[l].back());
    vals[l].pop_back();
    return;
  }
  int mid = (l + r) >> 1;
  build(me * 2, l, mid);
  build(me * 2 + 1, mid + 1, r);
  mes[me] = mes[me * 2] + mes[me * 2 + 1];
}
int now[N];
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (int)n - 1; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    link(a, b, c);
    link(b, a, c);
  }
  Getroot(1);
  memset(sz, 0, sizeof sz);
  Getans(root, 0);
  printf("%I64d\n", ans * 2ll);
  int M = 0;
  for (int u = head[root]; u; u = np[u]) {
    ++M;
    dfs(p[u], root, M);
    sort(vals[M].begin(), vals[M].end());
    reverse(vals[M].begin(), vals[M].end());
  }
  ++M;
  d[M] = 2;
  vals[M].push_back(root);
  from[root] = M;
  int A = n;
  for (int i = (1); i <= (int)M; i++) now[i] = vals[i].back();
  build(1, 1, M);
  for (int i = (1); i <= (int)n; i++) {
    int v = from[i];
    del(1, 1, M, v);
    node info;
    if (v == 1)
      info = Get(1, 1, M, 2, M);
    else if (v == M)
      info = Get(1, 1, M, 1, M);
    else
      info = Get(1, 1, M, 1, v - 1) + Get(1, 1, M, v + 1, M);
    int ret = 0;
    if (info.Mad.first == A) {
      ret = info.Mad.second;
    } else
      ret = info.Mival.second;
    printf("%d ", now[ret]);
    if (vals[ret].size()) {
      now[ret] = vals[ret].back();
      vals[ret].pop_back();
    } else
      now[ret] = 1e9;
    del(1, 1, M, ret);
    modify(1, 1, M, ret, now[ret]);
    A--;
  }
  return 0;
}
