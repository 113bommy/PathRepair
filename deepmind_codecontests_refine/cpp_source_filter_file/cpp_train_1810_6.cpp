#include <bits/stdc++.h>
using namespace std;
int n, m, a[100000 + 5], L[100000 + 5], R[100000 + 5];
struct node {
  long long ma, mal, mar;
  long long maq, mah, maqt, maht;
  long long mi, mil, mir;
  long long miq, mih, miqt, miht;
  long long sum, tag;
};
struct Seg {
  node s[100000 * 4 + 5];
  node upd(node x, node y) {
    node k;
    k.tag = 0;
    k.sum = x.sum + y.sum;
    if (x.ma > y.ma) {
      k.ma = x.ma;
      k.mal = x.mal;
      k.mar = x.mar;
    } else {
      k.ma = y.ma;
      k.mal = y.mal;
      k.mar = y.mar;
    }
    if (x.mah + y.maq > k.ma) {
      k.ma = x.mah + y.maq;
      k.mal = x.maht;
      k.mar = y.maqt;
    }
    k.maq = x.maq;
    k.maqt = x.maqt;
    if (x.sum + y.maq > k.maq) {
      k.maq = x.sum + y.maq;
      k.maqt = y.maqt;
    }
    k.mah = y.mah;
    k.maht = y.maht;
    if (y.sum + x.mah > k.mah) {
      k.mah = y.sum + x.mah;
      k.maht = x.maht;
    }
    if (x.mi < y.mi) {
      k.mi = x.mi;
      k.mil = x.mil;
      k.mir = x.mir;
    } else {
      k.mi = y.mi;
      k.mil = y.mil;
      k.mir = y.mir;
    }
    if (x.mih + y.miq < k.mi) {
      k.mi = x.mih + y.miq;
      k.mil = x.miht;
      k.mir = y.miqt;
    }
    k.miq = x.miq;
    k.miqt = x.miqt;
    if (x.sum + y.miq < k.miq) {
      k.miq = x.sum + y.miq;
      k.miqt = y.miqt;
    }
    k.mih = y.mih;
    k.miht = y.miht;
    if (y.sum + x.mih < k.mih) {
      k.mih = y.sum + x.mih;
      k.miht = x.miht;
    }
    return k;
  }
  void build(int k, int l, int r) {
    if (l == r) {
      s[k].ma = s[k].maq = s[k].mah = s[k].mi = s[k].miq = s[k].mih = s[k].sum =
          (long long)a[l];
      s[k].mal = s[k].mar = s[k].maqt = s[k].maht = s[k].mil = s[k].mir =
          s[k].miqt = s[k].miht = (long long)l;
      s[k].tag = 0;
      return;
    }
    int mid = l + r >> 1;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
    s[k] = upd(s[k << 1], s[k << 1 | 1]);
  }
  void cha(int k, int l, int r, int z) {
    s[k].tag ^= 1;
    s[k].sum = -s[k].sum;
    swap(s[k].ma, s[k].mi);
    swap(s[k].maq, s[k].miq);
    swap(s[k].mah, s[k].mih);
    swap(s[k].mal, s[k].mil);
    swap(s[k].mar, s[k].mir);
    swap(s[k].maqt, s[k].miqt);
    swap(s[k].maht, s[k].miht);
    s[k].ma = -s[k].ma;
    s[k].mi = -s[k].mi;
    s[k].maq = -s[k].maq;
    s[k].mah = -s[k].mah;
    s[k].miq = -s[k].miq;
    s[k].mih = -s[k].mih;
  }
  void pushdown(int k, int l, int r, int mid) {
    if (!s[k].tag) return;
    cha(k << 1, l, mid, -1);
    cha(k << 1 | 1, mid + 1, r, -1);
    s[k].tag = 0;
  }
  void change(int k, int l, int r, int x, int z) {
    if (l == r) {
      s[k].ma = s[k].maq = s[k].mah = s[k].mi = s[k].miq = s[k].mih = s[k].sum =
          (long long)z;
      s[k].mal = s[k].mar = s[k].maqt = s[k].maht = s[k].mil = s[k].mir =
          s[k].miqt = s[k].miht = (long long)l;
      s[k].tag = 0;
      return;
    }
    int mid = l + r >> 1;
    pushdown(k, l, r, mid);
    if (x <= mid)
      change(k << 1, l, mid, x, z);
    else
      change(k << 1 | 1, mid + 1, r, x, z);
    s[k] = upd(s[k << 1], s[k << 1 | 1]);
  }
  node query(int k, int l, int r, int x, int y) {
    if (l >= x && r <= y) return s[k];
    int mid = l + r >> 1;
    pushdown(k, l, r, mid);
    if (x > mid)
      return query(k << 1 | 1, mid + 1, r, x, y);
    else if (y <= mid)
      return query(k << 1, l, mid, x, y);
    else
      return upd(query(k << 1, l, mid, x, y),
                 query(k << 1 | 1, mid + 1, r, x, y));
  }
  void change(int k, int l, int r, int x, int y, int z) {
    if (l >= x && r <= y) {
      cha(k, l, r, z);
      return;
    }
    int mid = l + r >> 1;
    pushdown(k, l, r, mid);
    if (x > mid)
      change(k << 1 | 1, mid + 1, r, x, y, z);
    else if (y <= mid)
      change(k << 1, l, mid, x, y, z);
    else
      change(k << 1, l, mid, x, y, z), change(k << 1 | 1, mid + 1, r, x, y, z);
    s[k] = upd(s[k << 1], s[k << 1 | 1]);
  }
} tree;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  tree.build(1, 1, n);
  scanf("%d", &m);
  int opt, l, r, z;
  long long ans, s;
  node now;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &opt, &l, &r);
    if (opt == 0)
      tree.change(1, 1, n, l, r);
    else {
      scanf("%d", &z);
      ans = -99999999;
      s = 0;
      for (int j = 1; j <= z; j++) {
        now = tree.query(1, 1, n, l, r);
        s += now.ma;
        ans = max(ans, s);
        L[j] = now.mal;
        R[j] = now.mar;
        tree.change(1, 1, n, now.mal, now.mar, -1);
      }
      printf("%lld\n", ans);
      for (int j = 1; j <= z; j++) tree.change(1, 1, n, L[j], R[j], -1);
    }
  }
  return 0;
}
