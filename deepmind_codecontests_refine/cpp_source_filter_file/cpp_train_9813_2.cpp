#include <bits/stdc++.h>
using namespace std;
struct Nod {
  int l, r;
  Nod() {}
  bool operator<(const Nod &cmp) const {
    if (l == cmp.l) return r > cmp.r;
    return l < cmp.l;
  }
} p[888888];
int cnt[888888], w[888888];
void PushDown(int rt) {
  if (cnt[rt]) {
    cnt[rt << 1] = 1;
    cnt[rt << 1 | 1] = 1;
  }
}
void update(int L, int R, int l, int r, int rt) {
  if (L <= l && r <= R) {
    cnt[rt] = 1;
    return;
  }
  int m = (l + r) >> 1;
  PushDown(rt);
  if (L <= m) update(L, R, l, m, rt << 1);
  if (m < R) update(L, R, m + 1, r, rt << 1 | 1);
}
int query(int d, int l, int r, int rt) {
  if (l == r) {
    return cnt[rt];
  }
  int m = (l + r) >> 1;
  PushDown(rt);
  if (d <= m)
    return query(d, l, m, rt << 1);
  else
    return query(d, m + 1, r, rt << 1 | 1);
}
int bin(int key, int n) {
  int l = 0, r = n - 1;
  while (l <= r) {
    int m = (l + r) >> 1;
    if (w[m] == key) return m;
    if (w[m] < key)
      l = m + 1;
    else
      r = m - 1;
  }
  return -1;
}
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    int i;
    int k = 0;
    for (i = 0; i < n; i++) {
      scanf("%d%d", &p[i].l, &p[i].r);
      w[k++] = p[i].l;
      w[k++] = p[i].r;
    }
    sort(w, w + k);
    sort(p, p + n);
    int sum = 0;
    memset(cnt, 0, sizeof(cnt));
    for (i = 0; i < n; i++) {
      int ll = bin(p[i].l, k);
      int rr = bin(p[i].r, k);
      int k = query(rr + 1, 1, n, 1);
      if (k != 0) sum++;
      update(ll, rr, 1, n, 1);
    }
    printf("%d\n", sum);
  }
  return 0;
}
