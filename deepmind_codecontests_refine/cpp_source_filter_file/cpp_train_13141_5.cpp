#include <bits/stdc++.h>
using namespace std;
const int maxN = 5e5 + 10;
const long long INF = 1e18;
struct Segment {
  long long num, lazy;
} tree[maxN * 4 + 1];
int n, m;
int p[maxN + 1], a[maxN + 1], b[maxN + 1];
inline int read() {
  int num = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) num = (num << 3) + (num << 1) + (ch ^ 48), ch = getchar();
  return num * f;
}
inline void pushup(int node) {
  tree[node].num = min(tree[node << 1].num, tree[node << 1 | 1].num);
}
inline void pushdown(int node) {
  if (!tree[node].lazy) return;
  int num = tree[node].lazy;
  tree[node].lazy = 0;
  if (tree[node << 1].num < INF)
    tree[node << 1].num += num, tree[node << 1].lazy += num;
  if (tree[node << 1 | 1].num < INF)
    tree[node << 1 | 1].num += num, tree[node << 1 | 1].lazy += num;
}
inline void build(int node, int l, int r) {
  if (l == r) {
    tree[node].num = l ? INF : 0;
    return;
  }
  int mid = (l + r) >> 1;
  build(node << 1, l, mid);
  build(node << 1 | 1, mid + 1, r);
  pushup(node);
}
inline void change(int node, int l, int r, int x, int y, long long num) {
  if (x <= l && r <= y) {
    if (tree[node].num < INF) tree[node].num += num, tree[node].lazy += num;
    return;
  }
  pushdown(node);
  int mid = (l + r) >> 1;
  if (x <= mid) change(node << 1, l, mid, x, y, num);
  if (y > mid) change(node << 1 | 1, mid + 1, r, x, y, num);
  pushup(node);
}
inline void modify(int node, int l, int r, int x, long long num) {
  if (l == r) {
    tree[node].num = min(tree[node].num, num);
    return;
  }
  pushdown(node);
  int mid = (l + r) >> 1;
  if (x <= mid)
    modify(node << 1, l, mid, x, num);
  else
    modify(node << 1 | 1, mid + 1, r, x, num);
  pushup(node);
}
inline long long query(int node, int l, int r, int x) {
  if (l == r) return tree[node].num;
  pushdown(node);
  int mid = (l + r) >> 1;
  if (x <= mid)
    return query(node << 1, l, mid, x);
  else
    return query(node << 1 | 1, mid + 1, r, x);
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++) p[i] = read();
  m = read();
  for (int i = 1; i <= m; i++) b[i] = read();
  build(1, 0, m);
  for (int i = 1; i <= n; i++) {
    int x = lower_bound(b + 1, b + m + 1, a[i]) - b;
    long long t;
    if (b[x] == a[i]) t = query(1, 0, m, x - 1);
    change(1, 0, m, 0, x - 1, p[i]);
    if (p[i] < 0 && x <= m) change(1, 0, m, x, m, p[i]);
    if (b[x] == a[i]) modify(1, 0, m, x, t);
  }
  long long ans = query(1, 0, m, m);
  if (ans >= INF)
    puts("NO");
  else {
    puts("YES");
    printf("%lld\n", ans);
  }
  return 0;
}
