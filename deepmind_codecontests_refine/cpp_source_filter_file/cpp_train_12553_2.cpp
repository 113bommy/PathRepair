#include <bits/stdc++.h>
using namespace std;
struct _ {
  int u, l, r, s, id;
  bool operator<(const _ &ob) const {
    if (u != ob.u) return u < ob.u;
  }
} a[100010];
int h, w, n;
struct __ {
  int id, actheight;
  bool operator<(const __ &ob) const { return actheight > ob.actheight; }
};
set<int, greater<int> > s[400010];
void erase(int id, int L, int R, int l, int r, int rt) {
  if (L <= l && r <= R) {
    s[rt].erase(s[rt].lower_bound(id));
    return;
  }
  int m = l + r >> 1;
  if (m >= L) erase(id, L, R, l, m, rt << 1);
  if (m < R) erase(id, L, R, m + 1, r, rt << 1 | 1);
}
void erase(int id) { erase(id, a[id].l, a[id].r, 1, w, 1); }
priority_queue<__> pq;
void inactive(int height) {
  __ tmp;
  while (!pq.empty()) {
    tmp = pq.top();
    if (tmp.actheight < height)
      pq.pop(), erase(tmp.id);
    else
      break;
  }
}
long long f[100010];
int query(int pos, int l, int r, int rt) {
  if (l == r) return s[rt].empty() ? 0 : *s[rt].begin();
  int m = l + r >> 1, ans = 0;
  if (!s[rt].empty()) ans = *s[rt].begin();
  if (pos <= m)
    ans = max(ans, query(pos, l, m, rt << 1));
  else
    ans = max(ans, query(pos, m + 1, r, rt << 1 | 1));
  return ans;
}
int query(int pos) { return query(pos, 1, w, 1); }
void insert(int id, int L, int R, int l, int r, int rt) {
  if (L <= l && r <= R) {
    s[rt].insert(id);
    return;
  }
  int m = l + r >> 1;
  if (m >= L) insert(id, L, R, l, m, rt << 1);
  if (m < R) insert(id, L, R, m + 1, r, rt << 1 | 1);
}
const long long mod = 1000000007;
int main() {
  scanf("%d%d%d", &h, &w, &n);
  int i;
  for (i = 1; i <= n; i++) {
    scanf("%d%d%d%d", &a[i].u, &a[i].l, &a[i].r, &a[i].s);
    a[i].s += a[i].u;
  }
  sort(a + 1, a + 1 + n);
  for (i = 1; i <= n; i++) {
    a[i].id = i;
  }
  f[0] = 1;
  int l, r;
  for (i = 1; i <= n; i++) {
    inactive(a[i].u);
    l = a[i].l - 1;
    r = a[i].r + 1;
    if (l == 0) l = r;
    if (r == w + 1) r = l;
    f[i] = (f[query(l)] + f[query(r)]) % mod;
    pq.push((__){i, a[i].s});
    insert(i, a[i].l, a[i].r, 1, w, 1);
  }
  inactive(h + 1);
  long long sum = 0;
  for (i = 1; i <= w; i++) {
    (sum += f[query(i)]) % mod;
  }
  printf("%lld\n", sum);
  return 0;
}
