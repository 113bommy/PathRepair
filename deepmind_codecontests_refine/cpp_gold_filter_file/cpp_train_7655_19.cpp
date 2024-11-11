#include <bits/stdc++.h>
using namespace std;
namespace MYS {
const int MAXN = 200005;
const int MAXL = 400005;
struct AdjList {
  int head[MAXN], to[MAXN << 1], next[MAXN << 1];
  int np;
  void push(int u, int v) {
    np++;
    next[np] = head[u];
    head[u] = np;
    to[np] = v;
  }
};
int N;
AdjList g;
int pre[MAXN], low[MAXN], dfs_clock;
void input() {
  int f;
  scanf("%d", &N);
  for (int i = 2; i <= N; i++) {
    scanf("%d", &f);
    g.push(f, i);
  }
}
void dfs(int x) {
  int y;
  pre[x] = ++dfs_clock;
  for (int i = g.head[x]; i; i = g.next[i]) {
    y = g.to[i];
    dfs(y);
  }
  low[x] = ++dfs_clock;
}
namespace SegTree {
const int MAXN = 800005;
int lc[MAXN], rc[MAXN];
int mx[MAXN], left[MAXN], right[MAXN];
int rp[MAXN], rm[MAXN], lp[MAXN], lm[MAXN];
int np;
void build(int &now, int L, int R) {
  now = ++np;
  if (L == R) return;
  int m = (L + R) >> 1;
  build(lc[now], L, m);
  build(rc[now], m + 1, R);
}
void maintain(int x) {
  int a, b, c, d, e, f;
  mx[x] = max(mx[lc[x]], mx[rc[x]]);
  a = left[lc[x]], b = right[lc[x]];
  c = left[rc[x]], d = right[rc[x]];
  if (b >= c) {
    e = a;
    f = b - c + d;
  } else {
    e = a + c - b;
    f = d;
  }
  left[x] = e;
  right[x] = f;
  mx[x] = max(rp[lc[x]] + lm[rc[x]], mx[x]);
  mx[x] = max(rm[lc[x]] + lp[rc[x]], mx[x]);
  lm[x] = max(lm[lc[x]], lm[rc[x]] + b - a);
  lp[x] = max(lp[lc[x]], max(a + b + lm[rc[x]], a - b + lp[rc[x]]));
  rm[x] = max(rm[rc[x]], c - d + rm[lc[x]]);
  rp[x] = max(rp[rc[x]], max(rp[lc[x]] - c + d, rm[lc[x]] + c + d));
}
void modify(int now, int L, int R, int x, int d) {
  if (L == R) {
    if (d > 0) {
      right[now] = 1;
      rp[now] = lp[now] = 1;
      lm[now] = 1;
    } else {
      left[now] = 1;
      rp[now] = lp[now] = 1;
      rm[now] = 1;
    }
    return;
  }
  int m = (L + R) >> 1;
  if (x <= m)
    modify(lc[now], L, m, x, d);
  else
    modify(rc[now], m + 1, R, x, d);
  maintain(now);
}
}  // namespace SegTree
struct node {
  int x, v;
  bool operator<(const node &b) const { return x < b.x; }
};
set<node> S;
int left, right, root;
void update() {
  set<node>::iterator x, y, i, j;
  x = S.lower_bound((node){left, 0});
  y = S.upper_bound((node){right, 0});
  if (y == S.begin() || y == x) return;
  for (i = x; i != y; i++) {
    SegTree::modify(root, 1, low[1], i->x, i->v);
    if (i != x) S.erase(j);
    j = i;
  }
  S.erase(j);
}
void light(int x) {
  int flag = 0;
  if (pre[x] + 1 < left) {
    left = pre[x] + 1;
    flag = 1;
  }
  if (pre[x] > right) {
    right = pre[x];
    flag = 1;
  }
  update();
}
void work() {
  dfs_clock = 0;
  dfs(1);
  left = low[1] + 1;
  right = 0;
  SegTree::build(root, 1, low[1]);
  S.insert((node){1, 1});
  S.insert((node){low[1], -1});
  light(1);
  for (int i = 2; i <= N; i++) {
    S.insert((node){pre[i], 1});
    S.insert((node){low[i], -1});
    light(i);
    printf("%d\n", SegTree::mx[root]);
  }
}
void Main() {
  input();
  work();
}
}  // namespace MYS
int main() {
  MYS::Main();
  return 0;
}
