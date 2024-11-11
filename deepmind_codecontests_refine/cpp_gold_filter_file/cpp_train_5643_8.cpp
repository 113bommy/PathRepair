#include <bits/stdc++.h>
using namespace std;
vector<int> ord;
const int maxn = 2e5 + 5;
int tree[maxn << 2];
int lazy[maxn << 2];
struct node {
  int l, r;
  int id;
  bool operator<(const node &rhs) const {
    if (r == rhs.r) return l < rhs.l;
    return r < rhs.r;
  }
} a[maxn];
void build(int rt, int l, int r) {
  lazy[rt] = 0;
  tree[rt] = 0;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(rt << 1, l, mid);
  build(rt << 1 | 1, mid + 1, r);
}
void pushup(int rt) { tree[rt] = max(tree[rt << 1], tree[rt << 1 | 1]); }
void pushdown(int rt) {
  if (lazy[rt] == 0) return;
  tree[rt << 1] += lazy[rt];
  tree[rt << 1 | 1] += lazy[rt];
  lazy[rt << 1] += lazy[rt];
  lazy[rt << 1 | 1] += lazy[rt];
  lazy[rt] = 0;
}
void update(int rt, int l, int r, int begin, int end, int val) {
  if (begin <= l && r <= end) {
    lazy[rt] += val;
    tree[rt] += val;
    return;
  }
  pushdown(rt);
  int mid = (l + r) >> 1;
  if (begin <= mid) update(rt << 1, l, mid, begin, end, val);
  if (mid + 1 <= end) update(rt << 1 | 1, mid + 1, r, begin, end, val);
  pushup(rt);
}
int query(int rt, int l, int r, int begin, int end) {
  if (begin <= l && r <= end) {
    return tree[rt];
  }
  pushdown(rt);
  int mid = (l + r) >> 1;
  int res = 0;
  if (begin <= mid) res = max(res, query(rt << 1, l, mid, begin, end));
  if (mid + 1 <= end)
    res = max(res, query(rt << 1 | 1, mid + 1, r, begin, end));
  return res;
}
int main(void) {
  int n, k;
  scanf("%d%d", &n, &k);
  int N = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i].l, &a[i].r);
    a[i].id = i;
    N = max(N, a[i].r);
  }
  sort(a + 1, a + 1 + n);
  build(1, 1, N);
  for (int i = 1; i <= n; i++) {
    int l, r;
    l = a[i].l;
    r = a[i].r;
    int t = query(1, 1, N, l, r);
    if (t < k)
      update(1, 1, N, l, r, 1);
    else
      ord.push_back(a[i].id);
  }
  sort(ord.begin(), ord.end());
  printf("%d\n", ord.size());
  int sz = ord.size();
  for (int i = 0; i <= sz - 1; i++) {
    printf("%d", ord[i]);
    if (i == sz - 1)
      printf("\n");
    else
      printf(" ");
  }
}
