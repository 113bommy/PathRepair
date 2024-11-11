#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;
const int P = 257;
const int maxn = 200005, maxp = maxn * 25 * 2;
int tot;
int ls[maxp], rs[maxp], val[maxp];
int n, m;
int base[maxn];
char s[maxn];
int rt[maxn];
int pre[26];
int insert(int rt, int l, int r, int x, int y) {
  int t = ++tot;
  ls[t] = ls[rt], rs[t] = rs[rt];
  if (l == r) {
    val[t] = y;
    return t;
  }
  int mid = (l + r) >> 1;
  if (x <= mid)
    ls[t] = insert(ls[t], l, mid, x, y);
  else
    rs[t] = insert(rs[t], mid + 1, r, x, y);
  val[t] = ((long long)val[ls[t]] * base[r - mid] + val[rs[t]]) % M;
  return t;
}
int query(int t, int l, int r, int x, int y) {
  if (x <= l && y >= r) return val[t];
  int mid = (l + r) >> 1;
  if (y <= mid) return query(ls[t], l, mid, x, y);
  if (x > mid) return query(rs[t], mid + 1, r, x, y);
  return ((long long)query(ls[t], l, mid, x, y) * base[y - mid] +
          query(rs[t], mid + 1, r, x, y)) %
         M;
}
int get(int r, int l) { return query(rt[r], 1, n, l, r); }
int main() {
  scanf("%d%d", &n, &m);
  base[0] = 1;
  for (int i = 1; i <= n; ++i) base[i] = (long long)base[i - 1] * P % M;
  scanf("%s", s + 1);
  for (int i = 1; i <= n; ++i) {
    rt[i] = insert(rt[i - 1], 1, n, i, 0);
    if (pre[s[i] - 'a'])
      rt[i] = insert(rt[i], 1, n, pre[s[i] - 'a'], i - pre[s[i] - 'a']);
    pre[s[i] - 'a'] = i;
  }
  while (m--) {
    int x, y, l;
    scanf("%d%d%d", &x, &y, &l);
    int p = get(x + l - 1, x), q = get(y + l - 1, y);
    if (p == q)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
