#include <bits/stdc++.h>
using namespace std;
int mx[800010], lazy[800010];
void update(int root) {
  mx[root] = max(mx[root << 1], mx[root << 1 | 1]);
  return;
}
void pushdown(int root) {
  mx[root << 1] += lazy[root];
  mx[root << 1 | 1] += lazy[root];
  lazy[root << 1] += lazy[root];
  lazy[root << 1 | 1] += lazy[root];
  lazy[root] = 0;
  return;
}
void add(int root, int l, int r, int x, int y, int z) {
  if (x > y) return;
  if (x <= l && r <= y) {
    lazy[root] += z;
    mx[root] += z;
    return;
  }
  pushdown(root);
  int mid = (l + r) >> 1;
  if (x <= mid) add(root << 1, l, mid, x, y, z);
  if (y > mid) add(root << 1 | 1, mid + 1, r, x, y, z);
  update(root);
  return;
}
struct Val {
  int x, y, z;
} v[200010];
bool cmp(Val a, Val b) { return a.x < b.x; }
struct W {
  int x, c;
} w1[200010], w2[200010];
bool cmp2(W a, W b) { return a.x < b.x; }
int n, m, p;
int find(int val) {
  int l = 0, r = m + 1;
  while (l + 1 < r) {
    int mid = (l + r) >> 1;
    if (w2[mid].x > val)
      r = mid;
    else
      l = mid;
  }
  return r;
}
int main() {
  scanf("%d %d %d", &n, &m, &p);
  for (int i = 1; i <= n; i++) scanf("%d %d", &w1[i].x, &w1[i].c);
  for (int i = 1; i <= m; i++) scanf("%d %d", &w2[i].x, &w2[i].c);
  sort(w1 + 1, w1 + n + 1, cmp2);
  sort(w2 + 1, w2 + m + 1, cmp2);
  for (int i = 1; i <= p; i++) scanf("%d %d %d", &v[i].x, &v[i].y, &v[i].z);
  sort(v + 1, v + p + 1, cmp);
  int ans = -2e9;
  for (int i = 1; i <= m; i++) add(1, 1, m, i, i, -w2[i].c);
  int now = 1;
  for (int i = 1; i <= n; i++) {
    while (now <= m && v[now].x < w1[i].x) {
      add(1, 1, m, find(v[now].y), m, v[now].z);
      now++;
    }
    ans = max(ans, mx[1] - w1[i].c);
  }
  printf("%d\n", ans);
  return 0;
}
