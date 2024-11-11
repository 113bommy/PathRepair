#include <bits/stdc++.h>
using namespace std;
const int N = 0x3f3f3f3f;
const int maxn = 3e5 + 10;
struct node {
  int minn1, minn2, cnt1, cnt2, laz;
};
node tree[4 * maxn];
int ary[maxn], pos[maxn];
int n;
void change(int cur, int val) {
  tree[cur].minn1 += val;
  if (tree[cur].minn2 != N) tree[cur].minn2 += val;
  tree[cur].laz++;
}
void pushup(int cur) {
  tree[cur].minn1 = min(tree[2 * cur].minn1, tree[2 * cur + 1].minn1);
  tree[cur].minn2 = N;
  if (tree[cur].minn1 != tree[2 * cur].minn1)
    tree[cur].minn2 = min(tree[cur].minn2, tree[2 * cur].minn1);
  if (tree[cur].minn1 != tree[2 * cur + 1].minn1)
    tree[cur].minn2 = min(tree[cur].minn2, tree[2 * cur + 1].minn1);
  tree[cur].minn2 =
      min(tree[cur].minn2, min(tree[2 * cur].minn2, tree[2 * cur + 1].minn2));
  tree[cur].cnt1 = 0;
  if (tree[cur].minn1 == tree[2 * cur].minn1)
    tree[cur].cnt1 += tree[2 * cur].cnt1;
  if (tree[cur].minn1 == tree[2 * cur + 1].minn1)
    tree[cur].cnt1 += tree[2 * cur + 1].cnt1;
  tree[cur].cnt2 = 0;
  if (tree[cur].minn2 == tree[2 * cur].minn1)
    tree[cur].cnt2 += tree[2 * cur].cnt1;
  if (tree[cur].minn2 == tree[2 * cur + 1].minn1)
    tree[cur].cnt2 += tree[2 * cur + 1].cnt1;
  if (tree[cur].minn2 == tree[2 * cur].minn2)
    tree[cur].cnt2 += tree[2 * cur].cnt2;
  if (tree[cur].minn2 == tree[2 * cur + 1].minn2)
    tree[cur].cnt2 += tree[2 * cur + 1].cnt2;
}
void pushdown(int cur) {
  if (tree[cur].laz != 0) {
    change(2 * cur, tree[cur].laz);
    change(2 * cur + 1, tree[cur].laz);
    tree[cur].laz = 0;
  }
}
void build(int l, int r, int cur) {
  int m;
  tree[cur].minn1 = 0, tree[cur].minn2 = N;
  tree[cur].cnt1 = r - l + 1, tree[cur].cnt2 = 0;
  tree[cur].laz = 0;
  if (l == r) return;
  m = (l + r) / 2;
  build(l, m, 2 * cur);
  build(m + 1, r, 2 * cur + 1);
  pushup(cur);
}
void update(int pl, int pr, int val, int l, int r, int cur) {
  int m;
  if (pl <= l && r <= pr) {
    change(cur, val);
    return;
  }
  pushdown(cur);
  m = (l + r) / 2;
  if (pl <= m) update(pl, pr, val, l, m, 2 * cur);
  if (pr > m) update(pl, pr, val, m + 1, r, 2 * cur + 1);
  pushup(cur);
}
long long query(int pl, int pr, int l, int r, int cur) {
  long long res;
  int m;
  if (pl <= l && r <= pr) {
    res = 0;
    if (tree[cur].minn1 == 1 || tree[cur].minn1 == 2)
      res += (long long)(tree[cur].cnt1);
    if (tree[cur].minn2 == 1 || tree[cur].minn2 == 2)
      res += (long long)(tree[cur].cnt2);
    return res;
  }
  pushdown(cur);
  res = 0, m = (l + r) / 2;
  if (pl <= m) res += query(pl, pr, l, m, 2 * cur);
  if (pr > m) res += query(pl, pr, m + 1, r, 2 * cur + 1);
  return res;
}
int main() {
  long long ans;
  int i, tmp, x, y;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &tmp);
    pos[tmp] = i;
  }
  build(1, n, 1);
  ans = 0;
  for (i = n; i >= 1; i--) {
    ary[pos[i]] = i;
    x = ary[pos[i] - 1], y = ary[pos[i] + 1];
    if (x > y) swap(x, y);
    if (x == 0 && y == 0) {
      update(i, n, 1, 1, n, 1);
    } else if (x == 0 && y != 0) {
      update(i, y - 1, 1, 1, n, 1);
    } else {
      update(i, x - 1, 1, 1, n, 1);
      update(y, n, -1, 1, n, 1);
    }
    ans += query(i, n, 1, n, 1);
  }
  printf("%lld\n", ans - n);
  return 0;
}
