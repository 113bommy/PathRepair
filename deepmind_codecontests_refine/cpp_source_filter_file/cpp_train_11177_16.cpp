#include <bits/stdc++.h>
using namespace std;
struct Node {
  int minv, tag;
} tree[1005000 << 2];
long long vx, vy;
int L[1005000], R[1005000], d[1005000], w[1005000], n;
bool cmp(int i, int j) { return d[i] < d[j]; }
void update_set(int root, int v) {
  tree[root].minv = max(tree[root].minv, v);
  tree[root].tag = max(tree[root].tag, v);
}
void push_down(int root) {
  if (tree[root].tag) {
    update_set(root << 1, tree[root].tag),
        update_set(root << 1 | 1, tree[root].tag);
    tree[root].tag = 0;
  }
}
int Query(int root, int l, int r, int x, int y) {
  if (l == x && r == y) return tree[root].minv;
  push_down(root);
  int mid = (l + r) >> 1;
  if (y <= mid)
    return Query(root << 1, l, mid, x, y);
  else if (mid < x)
    return Query(root << 1 | 1, mid + 1, r, x, y);
  else
    return min(Query(root << 1, l, mid, x, mid),
               Query(root << 1 | 1, mid + 1, r, mid + 1, y));
}
void Insert(int root, int l, int r, int x, int y, int v) {
  if (l == x && r == y) {
    update_set(root, v);
    return;
  }
  push_down(root);
  int mid = (l + r) >> 1;
  if (y <= mid)
    Insert(root << 1, l, mid, x, y, v);
  else if (mid < x)
    Insert(root << 1 | 1, mid + 1, r, x, y, v);
  else
    Insert(root << 1, l, mid, x, mid, v),
        Insert(root << 1 | 1, mid + 1, r, mid + 1, y, v);
  tree[root].minv = min(tree[root << 1].minv, tree[root << 1 | 1].minv);
}
void add(int a, int b, int v) {
  long long l = 1000000000000000000LL, r = -1000000000000000000LL,
            dis = 1000000000000000000LL;
  for (int i = a - 1; i <= a; ++i)
    for (int j = b - 1; j <= b; ++j) {
      long long val = vx * j - vy * i;
      l = min(l, val), r = max(r, val), dis = min(dis, vx * i + vy * j);
    }
  ++n, L[n] = l, R[n] = r, d[n] = dis, w[n] = v;
}
void read() {
  int n;
  cin >> n >> vx >> vy;
  for (int i = 1, x; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      scanf("%d", &x);
      if (x) add(i, j, x);
    }
}
long long work() {
  static int x[1005000 << 1], id[1005000];
  int tot = 0;
  for (int i = 1; i <= n; ++i) x[++tot] = L[i], x[++tot] = R[i], id[i] = i;
  sort(x + 1, x + tot + 1);
  tot = unique(x + 1, x + tot + 1) - x - 1;
  for (int i = 1; i <= n; ++i) {
    L[i] = lower_bound(x + 1, x + tot + 1, L[i]) - x;
    R[i] = lower_bound(x + 1, x + tot + 1, R[i]) - x;
  }
  sort(id + 1, id + n + 1, cmp);
  long long ans = 0;
  for (int j = 1; j <= n; ++j) {
    int i = id[j], h = Query(1, 1, tot, L[i], R[i]);
    ans += max(0, w[i] - h), Insert(1, 1, tot, L[i], R[i], w[i]);
  }
  return ans;
}
int main() {
  read();
  cout << work() << endl;
  return 0;
}
