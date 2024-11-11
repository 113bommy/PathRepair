#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int n, m, q;
int root[N], lastv;
struct Tr {
  bool p = false;
  int le = 0, ri = 0, val = 0;
} tr[N * 55];
void push(int v, int l, int r) {
  if (tr[v].p == false) return;
  tr[v].p = false;
  if (l == r) return;
  int t = (l + r) / 2;
  int pv = tr[v].le;
  tr[v].le = ++lastv;
  tr[tr[v].le] = tr[pv];
  tr[tr[v].le].p ^= true;
  tr[tr[v].le].val = t - l + 1 - tr[tr[v].le].val;
  pv = tr[v].ri;
  tr[v].ri = ++lastv;
  tr[tr[v].ri] = tr[pv];
  tr[tr[v].ri].val = r - t - tr[tr[v].ri].val;
  tr[tr[v].ri].p ^= true;
}
void upd(int& v, int l, int r, int pos, int val) {
  int pv = v;
  v = ++lastv;
  tr[v] = tr[pv];
  push(v, l, r);
  if (l == r) {
    tr[v].val = val;
    return;
  }
  int t = (l + r) / 2;
  if (pos <= t)
    upd(tr[v].le, l, t, pos, val);
  else
    upd(tr[v].ri, t + 1, r, pos, val);
  tr[v].val = tr[tr[v].le].val + tr[tr[v].ri].val;
}
void rev(int& v, int l, int r, int ql, int qr) {
  int pv = v;
  v = ++lastv;
  tr[v] = tr[pv];
  push(v, l, r);
  if (qr < ql) return;
  if (ql == l && qr == r) {
    tr[v].val = (r - l + 1) - tr[v].val;
    tr[v].p = true;
    return;
  }
  int t = (l + r) / 2;
  rev(tr[v].le, l, t, ql, min(t, qr));
  rev(tr[v].ri, t + 1, r, max(t + 1, ql), qr);
  tr[v].val = tr[tr[v].le].val + tr[tr[v].ri].val;
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  const int R = n * m - 1;
  for (int i = 1; i <= q; ++i) {
    int t;
    scanf("%d", &t);
    if (t == 1 || t == 2) {
      int x, y;
      scanf("%d%d", &x, &y);
      --x;
      --y;
      root[i] = root[i - 1];
      upd(root[i], 0, R, x * m + y, 2 - t);
      printf("%d\n", tr[root[i]].val);
      continue;
    }
    if (t == 3) {
      int x;
      scanf("%d", &x);
      --x;
      root[i] = root[i - 1];
      rev(root[i], 0, R, x * m, x * m + m - 1);
    } else {
      int x;
      scanf("%d", &x);
      root[i] = root[x];
    }
    printf("%d\n", tr[root[i]].val);
  }
  return 0;
}
