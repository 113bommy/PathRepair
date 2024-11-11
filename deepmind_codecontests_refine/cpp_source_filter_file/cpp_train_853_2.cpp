#include <bits/stdc++.h>
using namespace std;
int tree[500005 << 2];
struct P {
  int x, y, z;
  int id;
} p[500005];
bool cmp1(P a, P b) {
  if (a.x != b.x)
    return a.x > b.x;
  else if (a.y != b.y)
    return a.y > b.y;
  else
    return a.z > b.z;
}
bool cmp2(P a, P b) { return a.y < b.y; }
void push_up(int rt) { tree[rt] = max(tree[rt << 1], tree[rt << 1 | 1]); }
void update(int pos, int x, int l, int r, int rt) {
  if (l == r) {
    tree[rt] = max(tree[rt], x);
    return;
  }
  int m = (l + r) >> 1;
  if (pos <= m)
    update(pos, x, l, m, rt << 1);
  else
    update(pos, x, m + 1, r, rt << 1 | 1);
  push_up(rt);
}
int query(int L, int R, int l, int r, int rt) {
  if (L <= l && R >= r) return tree[rt];
  int m = (l + r) >> 1;
  int ans = 0;
  if (L <= m) ans = max(ans, query(L, R, l, m, rt << 1));
  if (R > m) ans = max(ans, query(L, R, m + 1, r, rt << 1 | 1));
  return ans;
}
int main() {
  int i, j, n, ans, cnt, pre;
  while (~scanf("%d", &n)) {
    ans = 0;
    cnt = 1;
    memset(tree, 0, sizeof(tree));
    for (i = 0; i < n; i++) scanf("%d", &p[i].x), p[i].id = i;
    for (i = 0; i < n; i++) scanf("%d", &p[i].y);
    for (i = 0; i < n; i++) scanf("%d", &p[i].z);
    sort(p, p + n, cmp2);
    pre = p[0].y;
    p[0].y = 1;
    for (i = 1; i < n; i++)
      if (p[i].y == pre) {
        pre = p[i].y;
        p[i].y = cnt;
      } else {
        pre = p[i].y;
        p[i].y = ++cnt;
      }
    sort(p, p + n, cmp1);
    for (i = 0; i < n; i++) {
      for (j = i; j <= n && p[i].x == p[j].x; j++) {
        if (query(p[j].y + 1, cnt, 1, cnt, 1) > p[j].z) ans++;
      }
      for (; i < j; i++) update(p[i].y, p[i].z, 1, cnt, 1);
    }
    printf("%d\n", ans);
  }
  return 0;
}
