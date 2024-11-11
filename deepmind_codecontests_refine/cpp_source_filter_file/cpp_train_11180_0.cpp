#include <bits/stdc++.h>
using namespace std;
const int M = 1e9, N = 800002;
int s1[N], s2[N], tag[N], n, m, f[N], s[N], op, l, r, x, i;
int move(int s1, int s2, int k) {
  if (k == -1) return s1;
  return (1ll * s1 * (!k ? 0 : f[k - 1]) + 1ll * s2 * f[k]) % M;
}
void up(int t, int l, int r) {
  s1[t] =
      (move(s1[t << 1 | 1], s2[t << 1 | 1], ((l + r) >> 1) - l) + s1[t << 1]) %
      M;
  s2[t] = (move(s1[t << 1 | 1], s2[t << 1 | 1], ((l + r) >> 1) - l + 1) +
           s2[t << 1]) %
          M;
}
void chg(int t, int l, int r, int v) {
  (tag[t] += v) %= M;
  (s1[t] += 1ll * v * s[r - l] % M) %= M;
  (s2[t] += 1ll * v * (s[r - l + 1] - 1) % M) %= M;
}
void down(int t, int l, int r) {
  if (tag[t]) {
    chg(t << 1, l, ((l + r) >> 1), tag[t]),
        chg(t << 1 | 1, ((l + r) >> 1) + 1, r, tag[t]);
    tag[t] = 0;
  }
}
void add(int t, int l, int r, int x, int y, int v) {
  if (x <= l && r <= y) {
    chg(t, l, r, v);
    return;
  }
  down(t, l, r);
  if (x <= ((l + r) >> 1)) add(t << 1, l, ((l + r) >> 1), x, y, v);
  if (((l + r) >> 1) < y) add(t << 1 | 1, ((l + r) >> 1) + 1, r, x, y, v);
  up(t, l, r);
}
int query(int t, int l, int r, int x, int y) {
  if (x <= l && r <= y) return move(s1[t], s2[t], l - x - 1);
  down(t, l, r);
  int ans = 0;
  if (x <= ((l + r) >> 1)) ans += query(t << 1, l, ((l + r) >> 1), x, y);
  if (((l + r) >> 1) < y) ans += query(t << 1 | 1, ((l + r) >> 1) + 1, r, x, y);
  return ans;
}
void change(int x, int y) { add(1, 1, n, x, x, y - query(1, 1, n, x, x)); }
int main() {
  scanf("%d%d", &n, &m);
  f[0] = f[1] = s[0] = 1, s[1] = 2;
  for (i = 2; i <= n; i++)
    f[i] = (f[i - 1] + f[i - 2]) % M, s[i] = (s[i - 1] + f[i]) % M;
  for (i = 1; i <= n; i++) scanf("%d", &x), change(i, x);
  for (; m--;) {
    scanf("%d%d%d", &op, &l, &r);
    if (op == 1) change(l, r);
    if (op == 2) printf("%d\n", query(1, 1, n, l, r));
    if (op == 3) scanf("%d", &x), add(1, 1, n, l, r, x);
  }
}
