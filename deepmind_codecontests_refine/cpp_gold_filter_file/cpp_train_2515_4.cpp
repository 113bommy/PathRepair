#include <bits/stdc++.h>
using namespace std;
int a[300000], b[300000], t[2 * (1 << 20)], lazy[2 * (1 << 20)];
void propagate(int n) {
  if (!lazy[n]) return;
  if (n < (1 << 20)) {
    lazy[n << 1] += lazy[n];
    lazy[n << 1 | 1] += lazy[n];
  }
  t[n] += lazy[n];
  lazy[n] = 0;
}
void upd(int n, int d, int l, int r, int nv) {
  propagate(n);
  if (l >= r) return;
  if (!l && r == d) {
    lazy[n] += nv;
    propagate(n);
    return;
  }
  d >>= 1;
  upd(n << 1, d, l, min(d, r), nv);
  upd(n << 1 | 1, d, max(0, l - d), r - d, nv);
  t[n] = max(t[n << 1], t[n << 1 | 1]);
}
int query(int n) {
  if (n >= (1 << 20)) return n - (1 << 20) + 1;
  propagate(n << 1);
  propagate(n << 1 | 1);
  if (t[n << 1 | 1] > 0) return query(n << 1 | 1);
  return query(n << 1);
}
int main() {
  int N, M, Q;
  while (scanf("%d %d", &N, &M) != EOF) {
    memset(t, 0, sizeof(t));
    memset(lazy, 0, sizeof(lazy));
    for (int i = int(0); i < int(N); i++) {
      scanf("%d", a + i);
      a[i]--;
      t[a[i] + (1 << 20)]++;
    }
    for (int i = int(0); i < int(M); i++) {
      scanf("%d", b + i);
      b[i]--;
      t[b[i] + (1 << 20)]--;
    }
    for (int i = (1 << 20) - 2; i >= 0; i--)
      t[(1 << 20) + i] += t[(1 << 20) + i + 1];
    for (int i = (1 << 20) - 1; i; i--) t[i] = max(t[i << 1], t[i << 1 | 1]);
    scanf("%d", &Q);
    for (int i = int(0); i < int(Q); i++) {
      int type, id, x;
      scanf("%d %d %d", &type, &id, &x);
      id--;
      if (type == 1) {
        int l = a[id];
        if (l < x)
          upd(1, (1 << 20), l + 1, x, 1);
        else
          upd(1, (1 << 20), x, l + 1, -1);
        a[id] = x - 1;
      } else {
        int l = b[id];
        if (l < x)
          upd(1, (1 << 20), l + 1, x, -1);
        else
          upd(1, (1 << 20), x, l + 1, 1);
        b[id] = x - 1;
      }
      printf("%d\n", t[1] > 0 ? query(1) : -1);
    }
  }
  return 0;
}
