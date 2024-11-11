#include <bits/stdc++.h>
const int inf = 0x3f3f3f3f;
using namespace std;
int n, m;
char s[200005];
int mp[3][200005];
struct node {
  int ab, aa, bb, ba;
  void clear() { ab = aa = bb = ba = inf; }
} tr[200005 * 4];
node pushup(node l, node r) {
  node res;
  res.aa = min(inf, min(l.aa + r.aa, l.ab + r.ba) + 1);
  res.ab = min(inf, min(l.aa + r.ab, l.ba + r.bb) + 1);
  res.ba = min(inf, min(l.bb + r.ba, l.ba + r.aa) + 1);
  res.bb = min(inf, min(l.bb + r.bb, l.ba + r.ab) + 1);
  return res;
}
void build(int rt, int l, int r) {
  if (l == r) {
    tr[rt].clear();
    if (mp[1][l] == 0 && mp[2][l] == 0) tr[rt].ab = tr[rt].ba = 1;
    if (mp[1][l] == 0) tr[rt].aa = 0;
    if (mp[2][l] == 0) tr[rt].bb = 0;
    return;
  }
  build(rt << 1, l, ((l + r) >> 1));
  build(rt << 1 | 1, ((l + r) >> 1) + 1, r);
  tr[rt] = pushup(tr[rt << 1], tr[rt << 1 | 1]);
}
node query(int rt, int l, int r, int L, int R) {
  if (L <= l && r <= R) return tr[rt];
  if (R <= ((l + r) >> 1))
    return query(rt << 1, l, ((l + r) >> 1), L, R);
  else if (L > ((l + r) >> 1))
    return query(rt << 1 | 1, ((l + r) >> 1) + 1, r, L, R);
  return pushup(query(rt << 1, l, ((l + r) >> 1), L, R),
                query(rt << 1 | 1, ((l + r) >> 1) + 1, r, L, R));
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= 2; ++i) {
    scanf("%s", s);
    for (int j = 1; j <= n; ++j) mp[i][j] = (s[j - 1] == 'X') ? 1 : 0;
  }
  build(1, 1, n);
  for (int i = 1, l, r; i <= m; ++i) {
    scanf("%d%d", &l, &r);
    int x = l, y = r, ans;
    if (x > n) x -= n;
    if (y > n) y -= n;
    if (x > y) {
      swap(x, y);
      swap(l, r);
    }
    node p = query(1, 1, n, x, y);
    if (l > n && r > n) ans = p.bb;
    if (l > n && r <= n) ans = p.ba;
    if (l <= n && r <= n) ans = p.aa;
    if (l <= n && r > n) ans = p.ab;
    printf("%d\n", ans < inf ? ans : -1);
  }
  return 0;
}
