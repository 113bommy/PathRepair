#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, k, a, b, q;
long long sq[4 * maxn], sh[maxn], s[maxn];
int L[maxn], R[maxn];
int p, v, ql, qr;
void Push_up(int o) {
  s[o] = s[o << 1] + s[o << 1 | 1];
  sq[o] = sq[o << 1] + sq[o << 1 | 1];
  sh[o] = sh[o << 1] + sh[o << 1 | 1];
}
void Update(int o, int l, int r) {
  if (l == r) {
    s[o] += 1LL * v;
    sq[o] = s[o];
    sh[o] = s[o];
    if (sq[o] > b) sq[o] = b;
    if (sh[o] > a) sh[o] = a;
    return;
  }
  int mid = (l + r) / 2;
  if (p <= mid)
    Update(o << 1, l, mid);
  else
    Update(o << 1 | 1, mid + 1, r);
  Push_up(o);
}
long long queryq(int o, int l, int r) {
  if (ql <= l && r <= qr) {
    return sq[o];
  }
  int mid = (l + r) / 2;
  long long ans = 0LL;
  if (ql <= mid) ans += queryq(o << 1, l, mid);
  if (qr > mid) ans += queryq(o << 1 | 1, mid + 1, r);
  return ans;
}
long long queryh(int o, int l, int r) {
  if (ql <= l && r <= qr) {
    return sh[o];
  }
  int mid = (l + r) / 2;
  long long ans = 0LL;
  if (ql <= mid) ans += queryh(o << 1, l, mid);
  if (qr > mid) ans += queryh(o << 1 | 1, mid + 1, r);
  return ans;
}
void solve() {
  int cmd, dd, aa, pp;
  memset(sq, 0, sizeof(sq));
  memset(sh, 0, sizeof(sh));
  memset(s, 0, sizeof(s));
  for (int i = 1; i <= q; i++) {
    scanf("%d", &cmd);
    if (cmd == 1) {
      scanf("%d %d", &p, &v);
      Update(1, 1, n);
    } else {
      scanf("%d", &pp);
      long long qian = 0LL, hou = 0LL, res = 0LL;
      ql = 1;
      qr = pp - 1;
      if (qr >= ql) qian = queryq(1, 1, n);
      ql = pp + k;
      qr = n;
      hou = queryh(1, 1, n);
      res = qian + hou;
      printf("%I64d\n", res);
    }
  }
}
int main() {
  while (scanf("%d %d %d %d %d", &n, &k, &a, &b, &q) != EOF) {
    solve();
  }
  return 0;
}
