#include <bits/stdc++.h>
using namespace std;
int n, m, Q, a[100010], bit, ans;
long long tmp;
class sgt {
 public:
  bool rev[400010];
  int v[400010][2][32];
  inline void pushup(int p) {
    for (int i = 0; i < (1 << m); i++) {
      v[p][0][i] = v[(p << 1)][0][v[((p << 1) | 1)][0][i]];
      v[p][1][i] = v[(p << 1)][1][v[((p << 1) | 1)][1][i]];
    }
  }
  inline void pushnow(int p) {
    rev[p] ^= 1;
    swap(v[p][0], v[p][1]);
  }
  inline void pushdown(int p) {
    if (rev[p]) {
      pushnow((p << 1));
      pushnow(((p << 1) | 1));
      rev[p] = 0;
    }
  }
  void build(int p, int l, int r) {
    if (l == r) {
      for (int i = 0; i < (1 << m); i++) {
        if (i != (1 << m) - 1)
          v[p][0][i] = v[p][1][i] = (i >> 1) | bit;
        else if (a[l])
          v[p][0][i] = i >> 1, v[p][1][i] = (i >> 1) | bit;
        else
          v[p][0][i] = (i >> 1) | bit, v[p][1][i] = i >> 1;
      }
      return;
    }
    int mid = (l + r) >> 1;
    build((p << 1), l, mid);
    build(((p << 1) | 1), mid + 1, r);
    pushup(p);
  }
  void modify(int p, int l, int r, int ml, int mr) {
    if (ml <= l && r <= mr) {
      pushnow(p);
      return;
    }
    pushdown(p);
    int mid = (l + r) >> 1;
    if (ml <= mid) modify((p << 1), l, mid, ml, mr);
    if (mr > mid) modify(((p << 1) | 1), mid + 1, r, ml, mr);
    pushup(p);
  }
  void query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
      ans = v[p][0][ans];
      return;
    }
    pushdown(p);
    int mid = (l + r) >> 1;
    if (qr > mid) query(((p << 1) | 1), mid + 1, r, ql, qr);
    if (ql <= mid) query((p << 1), l, mid, ql, qr);
  }
} T;
int main() {
  scanf("%d%d%d", &n, &m, &Q);
  bit = 1 << (m - 1);
  for (int i = 1; i <= n; i++) scanf("%lld", &tmp), a[i] = tmp & 1;
  T.build(1, 1, n);
  while (Q--) {
    int opt, l, r;
    long long d;
    scanf("%d%d%d", &opt, &l, &r);
    if (opt == 1) {
      scanf("%lld", &d);
      if (d & 1) T.modify(1, 1, n, l, r);
    } else {
      ans = (1 << m) - 1;
      T.query(1, 1, n, l, r);
      if (ans & bit)
        puts("1");
      else
        puts("2");
    }
  }
  return 0;
}
