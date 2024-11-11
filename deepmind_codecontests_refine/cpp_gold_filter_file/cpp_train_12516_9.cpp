#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
const int inf = 1e9 + 100;
int a[N + 100], b[N + 100];
vector<pair<int, int> > mon[N + 100];
int tree[N * 4 + 100], lazy[N * 4 + 100];
void build(int v, int tl, int tr) {
  if (tl == tr) {
    tree[v] = -b[tl + 1];
    return;
  }
  int tm = (tl + tr) / 2;
  build(v * 2, tl, tm);
  build(v * 2 + 1, tm + 1, tr);
  tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
}
void push(int v) {
  tree[v * 2] += lazy[v];
  tree[v * 2 + 1] += lazy[v];
  lazy[v * 2] += lazy[v];
  lazy[v * 2 + 1] += lazy[v];
  lazy[v] = 0;
}
void update(int v, int tl, int tr, int l, int r, int addend) {
  if (l > r) {
    return;
  }
  if (tl == l && tr == r) {
    tree[v] += addend;
    lazy[v] += addend;
    return;
  }
  push(v);
  int tm = (tl + tr) / 2;
  update(v * 2, tl, tm, l, min(r, tm), addend);
  update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
  tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
}
int query(int v, int tl, int tr, int l, int r) {
  if (l > r) {
    return -inf;
  }
  if (tl == l && tr == r) {
    return tree[v];
  }
  push(v);
  int tm = (tl + tr) / 2;
  return max(query(v * 2, tl, tm, l, min(r, tm)),
             query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}
int main() {
  for (int i = 1; i <= N + 1; i++) {
    a[i] = b[i] = inf;
  }
  int n, m, p;
  scanf("%d%d%d", &n, &m, &p);
  for (int i = 1; i <= n; i++) {
    int cur, cost;
    scanf("%d%d", &cur, &cost);
    a[cur] = min(cost, a[cur]);
  }
  int mx = 0;
  for (int i = 1; i <= m; i++) {
    int cur, cost;
    scanf("%d%d", &cur, &cost);
    b[cur] = min(cost, b[cur]);
    mx = max(mx, cur);
  }
  for (int i = 1; i <= p; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    mon[x].push_back(make_pair(y, z));
  }
  for (int i = 1; i <= N; i++) {
    sort(mon[i].begin(), mon[i].end());
  }
  for (int i = N; i > 0; i--) {
    a[i] = min(a[i], a[i + 1]);
    b[i] = min(b[i], b[i + 1]);
  }
  build(1, 1, N);
  int ans = -a[1] - b[1];
  int total = 0;
  for (int i = 1; i <= N; i++) {
    if (a[i + 1] == inf) {
      break;
    }
    for (auto it : mon[i]) {
      update(1, 1, N, it.first, N, it.second);
      ans = max(ans, query(1, 1, N, 1, mx - 1) - a[i + 1]);
    }
  }
  printf("%d\n", ans);
}
