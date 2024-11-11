#include <bits/stdc++.h>
using namespace std;
namespace acm {
const int N = 100010;
struct dd {
  int x, h;
  double l, r;
  void gettree() {
    scanf("%d%d%lf%lf", &x, &h, &l, &r);
    l /= 100.0;
    r /= 100.0;
  }
} t[N];
int n, m;
int bin[N], tot;
pair<int, double> mush[N];
struct node {
  int lft, rht;
  int lazy;
  double v;
  int getmid() { return (lft + rht) >> 1; }
  void set(double t) {
    lazy = 1;
    v *= t;
  }
} tree[N << 2];
void build(int root, int lft, int rht) {
  tree[root].lft = lft;
  tree[root].rht = rht;
  tree[root].lazy = 0;
  tree[root].v = 1.0;
  if (lft == rht) return;
  int mid = (lft + rht) >> 1;
  build((root << 1), lft, mid);
  build((root << 1 | 1), mid + 1, rht);
}
void pushdown(int root) {
  if (tree[root].lazy == 0) return;
  tree[(root << 1)].set(tree[root].v);
  tree[(root << 1 | 1)].set(tree[root].v);
  tree[root].lazy = 0;
  tree[root].v = 1;
}
void setval(int root, int pos, double v) {
  if (tree[root].lft == tree[root].rht) {
    tree[root].v = v;
    return;
  }
  int mid = tree[root].getmid();
  if (pos <= mid) setval((root << 1), pos, v);
  if (mid < pos) setval((root << 1 | 1), pos, v);
}
void insert(int root, int lft, int rht, double v) {
  if (lft <= tree[root].lft && tree[root].rht <= rht) {
    tree[root].set(v);
    return;
  }
  if (tree[root].lft == tree[root].rht) return;
  pushdown(root);
  int mid = tree[root].getmid();
  if (lft <= mid) insert((root << 1), lft, rht, v);
  if (mid < rht) insert((root << 1 | 1), lft, rht, v);
}
double getsum(int root) {
  if (tree[root].lft == tree[root].rht) {
    return tree[root].v;
  }
  pushdown(root);
  return getsum((root << 1)) + getsum((root << 1 | 1));
}
void solve() {
  for (int i = 0; i < (int)(n); i++) t[i].gettree();
  int tot = 0;
  for (int i = 0; i < (int)(m); i++) {
    int x;
    double z;
    scanf("%d%lf", &x, &z);
    mush[i] = make_pair(x, z);
    bin[tot++] = x;
  }
  sort(mush, mush + m);
  sort(bin, bin + tot);
  tot = unique(bin, bin + tot) - bin;
  build(1, 0, tot - 1);
  int pos = 0;
  for (int i = 0; i < (int)(tot); i++) {
    double val = 0;
    while (pos < m && mush[pos].first == bin[i]) {
      val += mush[pos].second;
      pos++;
    }
    setval(1, i, val);
  }
  int lft, rht;
  for (int i = 0; i < (int)(n); i++) {
    lft = lower_bound(bin, bin + tot, t[i].x + 1) - bin;
    rht = lower_bound(bin, bin + tot, t[i].x + t[i].h + 1) - bin - 1;
    if (lft <= rht) insert(1, lft, rht, 1 - t[i].r);
    lft = lower_bound(bin, bin + tot, t[i].x - t[i].h) - bin;
    rht = lower_bound(bin, bin + tot, t[i].x) - bin - 1;
    if (lft <= rht) insert(1, lft, rht, 1 - t[i].l);
  }
  printf("%lf\n", getsum(1));
}
void icpc() {
  while (~scanf("%d%d", &n, &m)) {
    solve();
  }
}
}  // namespace acm
int main() {
  acm::icpc();
  return 0;
}
