#include <bits/stdc++.h>
using namespace std;
int n, m, l, r;
long long v;
char ch;
struct node {
  int l, r;
  long long minn, lazy;
} tree[200010 << 2];
void push_up(int p) {
  tree[p].minn = min(tree[p << 1].minn, tree[p << 1 | 1].minn);
}
void build(int p, int l, int r) {
  tree[p].l = l, tree[p].r = r;
  if (l == r) {
    scanf("%d", &tree[p].minn);
    return;
  }
  int mid = l + r >> 1;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
  push_up(p);
}
void spread(int p) {
  if (!tree[p].lazy) return;
  tree[p << 1].minn += tree[p].lazy;
  tree[p << 1 | 1].minn += tree[p].lazy;
  tree[p << 1].lazy += tree[p].lazy;
  tree[p << 1 | 1].lazy += tree[p].lazy;
  tree[p].lazy = 0;
}
void change(int p, int l, int r, long long x) {
  if (tree[p].l > r || tree[p].r < l) return;
  if (tree[p].l >= l && tree[p].r <= r) {
    tree[p].minn += x;
    tree[p].lazy += x;
    return;
  }
  spread(p);
  change(p << 1, l, r, x);
  change(p << 1 | 1, l, r, x);
  push_up(p);
}
long long ask(int p, int l, int r) {
  if (tree[p].l > r || tree[p].r < l) return 0x7f7f7f7f;
  if (tree[p].l >= l && tree[p].r <= r) return tree[p].minn;
  spread(p);
  return min(ask(p << 1, l, r), ask(p << 1 | 1, l, r));
}
int main() {
  scanf("%d", &n);
  build(1, 1, n);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &l, &r);
    l++, r++;
    ch = getchar();
    if (ch == '\n') {
      if (l <= r)
        printf("%lld\n", ask(1, l, r));
      else
        printf("%lld\n", min(ask(1, l, n), ask(1, 1, r)));
    } else {
      scanf("%lld", &v);
      if (l <= r)
        change(1, l, r, v);
      else
        change(1, l, n, v), change(1, 1, r, v);
    }
  }
  return 0;
}
