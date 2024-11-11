#include <bits/stdc++.h>
using namespace std;
int n, nq, tr, tg, z, tot, root;
int ls[7000010], rs[7000010], s[7000010];
long long mod, ans, x, y;
long long b[100010], a[100010];
void push_down(int p) {
  if (!ls[p]) ls[p] = ++tot;
  if (!rs[p]) rs[p] = ++tot;
  if (s[ls[p]] == 0 || s[p] < s[ls[p]]) s[ls[p]] = s[p];
  if (s[rs[p]] == 0 || s[p] < s[rs[p]]) s[rs[p]] = s[p];
  s[p] = 0;
}
void change(int &p, long long l, long long r) {
  if (l > y || r < x) return;
  if (!p) p = ++tot;
  if (l >= x && r <= y) {
    if (s[p] == 0 || z < s[p]) s[p] = z;
    return;
  }
  if (s[p]) push_down(p);
  change(ls[p], l, (l + r) / 2);
  change(rs[p], (l + r) / 2 + 1, r);
}
int query(int &p, long long l, long long r) {
  if (!p) p = ++tot;
  if (l == r) return s[p];
  if (s[p]) push_down(p);
  if (x <= (l + r) / 2)
    return query(ls[p], l, (l + r) / 2);
  else
    return query(rs[p], (l + r) / 2 + 1, r);
}
int main() {
  int i, j, q;
  long long tx, ty;
  scanf("%d%d%d", &n, &tg, &tr);
  mod = tg + tr;
  for (i = 1; i <= n + 1; i++) scanf("%I64d", &a[i]);
  for (i = 1; i <= n + 1; i++) a[i] += a[i - 1];
  for (i = n; i >= 1; i--) {
    x = mod - a[i] % mod;
    y = query(root, 1, mod);
    if (!y)
      b[i] = 0;
    else
      b[i] = b[y] + (mod - (a[y] - a[i]) % mod);
    tx = ((tg - a[i]) % mod + mod - 1) % mod + 1;
    ty = ((mod - 1 - a[i]) % mod + mod - 1) % mod + 1;
    z = i;
    if (tx <= ty) {
      x = tx;
      y = ty;
      change(root, 1, mod);
    } else {
      x = 1;
      y = tx;
      change(root, 1, mod);
      x = ty;
      y = mod;
      change(root, 1, mod);
    }
  }
  scanf("%d", &nq);
  for (q = 1; q <= nq; q++) {
    scanf("%d", &x);
    ans = x + a[n + 1];
    x = (x - 1) % mod + 1;
    y = query(root, 1, mod);
    if (y) ans += mod - (a[y] + x) % mod + b[y];
    printf("%I64d\n", ans);
  }
  return 0;
}
