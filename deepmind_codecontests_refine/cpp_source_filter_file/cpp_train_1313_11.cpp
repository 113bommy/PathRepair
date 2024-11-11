#include <bits/stdc++.h>
using namespace std;
int n, q, tail(0), root[200010], p[200010];
struct tree {
  int lc, rc, x;
  tree() { lc = rc = x = 0; }
} t[200010 * 18];
template <class Aqua>
inline void read(Aqua &s) {
  s = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) s = s * 10 + c - '0', c = getchar();
}
void modify(int &cur, int pre, int l, int r, int pos) {
  cur = ++tail;
  t[cur].lc = t[pre].lc, t[cur].rc = t[pre].rc;
  t[cur].x = t[pre].x + 1;
  if (l == r) return;
  if (pos <= ((l + r) >> 1))
    modify(t[cur].lc, t[pre].lc, l, ((l + r) >> 1), pos);
  else
    modify(t[cur].rc, t[pre].rc, ((l + r) >> 1) + 1, r, pos);
}
long long query(int cl, int cr, int l, int r, int L, int R) {
  if (L > R) return 0;
  if (L <= l && r <= R) return t[cr].x - t[cl].x;
  long long ans = 0;
  if (((l + r) >> 1) >= L)
    ans += query(t[cl].lc, t[cr].lc, l, ((l + r) >> 1), L, R);
  if (((l + r) >> 1) < R)
    ans += query(t[cl].rc, t[cr].rc, ((l + r) >> 1) + 1, r, L, R);
  return ans;
}
int main() {
  read(n), read(q);
  for (int i = 1; i <= n; i++) read(p[i]);
  for (int i = 1; i <= n; i++) modify(root[i], root[i - 1], 1, n, p[i]);
  long long x, y, x_, y_, ans, a, b, c;
  for (int i = 1; i <= q; i++) {
    read(x), read(y), read(x_), read(y_);
    ans = x_ * (n - x + 1) - (x_ - x + 1) * (x_ - x + 2) / 2;
    a = query(0, root[x_], 1, n, y_ + 1, n);
    b = query(root[x - 1], root[n], 1, n, y_ + 1, n);
    c = query(root[x - 1], root[x_], 1, n, y_ + 1, n);
    ans -= a * b - c * (c + 1) / 2;
    a = query(0, root[x_], 1, n, 1, y - 1);
    b = query(root[x - 1], root[n], 1, n, 1, y - 1);
    c = query(root[x - 1], root[x_], 1, n, 1, y - 1);
    ans -= a * b - c * (c + 1) / 2;
    printf("%lld\n", ans);
  }
  return 0;
}
