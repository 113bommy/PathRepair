#include <bits/stdc++.h>
using namespace std;
long long tem[200010], sum, s;
int num[200010], pos[200010];
struct Tree {
  int l, r, son;
  long long sum;
} tree[200010 * 3];
void init() {
  tem[0] = 1;
  s = sum = 0;
}
void build(int s, int t, int id) {
  tree[id].l = s, tree[id].r = t, tree[id].son = tree[id].sum = 0;
  if (s != t) {
    int mid = (tree[id].l + tree[id].r) >> 1;
    build(s, mid, id << 1);
    build(mid + 1, t, (id << 1) + 1);
  }
}
void update(int s, int number, int action, int id) {
  if (tree[id].l == tree[id].r) {
    tree[id].son += action;
    tree[id].sum += number;
    return;
  }
  int mid = (tree[id].l + tree[id].r) >> 1;
  if (s <= mid)
    update(s, number, action, id << 1);
  else
    update(s, number, action, (id << 1) + 1);
  tree[id].son = tree[id << 1].son + tree[(id << 1) + 1].son;
  tree[id].sum = tree[id << 1].sum * tem[tree[(id << 1) + 1].son] +
                 tree[(id << 1) + 1].sum;
}
int main() {
  int n, m, in;
  int i;
  scanf("%d %d", &n, &m);
  init();
  for (i = 1; i <= n; i++) {
    scanf("%d", &in);
    tem[i] = 1000003 * tem[i - 1];
    sum = sum * 1000003 + in;
    s += tem[i - 1];
  }
  for (i = 1; i <= m; i++) {
    scanf("%d", &num[i]);
    pos[num[i]] = i;
  }
  build(1, m, 1);
  int ans = 0;
  for (i = 1; i <= m; i++) {
    update(pos[i], i, 1, 1);
    if (i > n) update(pos[(i - n)], -(i - n), -1, 1);
    if (i >= n) {
      if (tree[1].sum - (i - n) * s == sum) ans++;
    }
  }
  printf("%d\n", ans);
}
