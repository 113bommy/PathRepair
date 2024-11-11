#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
class sgt {
 public:
  int tag[N << 2];
  void build(int p, int l, int r) {
    tag[p] = 1000000001;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build((p << 1), l, mid);
    build(((p << 1) | 1), mid + 1, r);
  }
  void modify(int p, int l, int r, int ml, int mr, int v) {
    if (ml <= l && r <= mr) {
      tag[p] = min(tag[p], v);
      return;
    }
    int mid = (l + r) >> 1;
    if (ml <= mid) modify((p << 1), l, mid, ml, mr, v);
    if (mr > mid) modify(((p << 1) | 1), mid + 1, r, ml, mr, v);
  }
  int query(int p, int l, int r, int pos, int cur) {
    cur = min(cur, tag[p]);
    if (l == r) return cur;
    int mid = (l + r) >> 1;
    if (pos <= mid) return query((p << 1), l, mid, pos, cur);
    return query(((p << 1) | 1), mid + 1, r, pos, cur);
  }
} T1;
class sgt2 {
 public:
  int val[N << 2];
  void build(int p, int l, int r, int* v) {
    if (l == r) {
      val[p] = v[l];
      return;
    }
    int mid = (l + r) >> 1;
    build((p << 1), l, mid, v);
    build(((p << 1) | 1), mid + 1, r, v);
    val[p] = max(val[(p << 1)], val[((p << 1) | 1)]);
  }
  void modify(int p, int l, int r, int pos, int v) {
    if (l == r) {
      val[p] = v;
      return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
      modify((p << 1), l, mid, pos, v);
    else
      modify(((p << 1) | 1), mid + 1, r, pos, v);
    val[p] = max(val[(p << 1)], val[((p << 1) | 1)]);
  }
  int query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return val[p];
    int mid = (l + r) >> 1, ret = 0;
    if (ql <= mid) ret = query((p << 1), l, mid, ql, qr);
    if (qr > mid) ret = max(ret, query(((p << 1) | 1), mid + 1, r, ql, qr));
    return ret;
  }
} T2;
int n, m, opt[N], a[N], b[N], c[N], val[N], cnt[N], ls[N];
bool vis[N];
int main() {
  scanf("%d%d", &n, &m);
  T1.build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &opt[i], &a[i], &b[i]);
    if (opt[i] == 1) {
      scanf("%d", &c[i]);
      T1.modify(1, 1, n, a[i], b[i], c[i]);
    } else {
      if (!vis[a[i]]) {
        vis[a[i]] = 1;
        val[a[i]] = T1.query(1, 1, n, a[i], 1000000001);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) val[i] = T1.query(1, 1, n, i, 1000000001);
  }
  T2.build(1, 1, n, val);
  for (int i = 1; i <= m; i++) {
    if (opt[i] == 1) {
      if (T2.query(1, 1, n, a[i], b[i]) != c[i]) {
        puts("NO");
        return 0;
      }
    } else {
      T2.modify(1, 1, n, a[i], b[i]);
    }
  }
  int totcnt = 0;
  for (int i = 1; i <= n; i++) totcnt += val[i] == 1000000001;
  if (totcnt >= 2) {
    puts("YES");
    bool has1 = 0;
    for (int i = 1; i <= n; i++) {
      if (val[i] != 1000000001)
        printf("%d ", val[i]);
      else {
        if (has1)
          printf("%d ", (1 << 29) - 1);
        else {
          printf("%d ", 1 << 29);
          has1 = 1;
        }
      }
    }
    return 0;
  }
  for (int i = 1; i <= n; i++) ls[i] = val[i];
  sort(ls + 1, ls + n + 1);
  int ex = unique(ls + 1, ls + n + 1) - ls;
  for (int i = 1; i <= n; i++) cnt[lower_bound(ls + 1, ls + ex, val[i]) - ls]++;
  int resor = 0;
  for (int i = 1; i <= n; i++) {
    if (!val[i] || val[i] == 1000000001) continue;
    int p = lower_bound(ls + 1, ls + ex, val[i]) - ls;
    cnt[p]--;
    if (cnt[p]) {
      int p = 0;
      while ((1 << p) - 1 <= val[i]) p++;
      val[i] = ((1 << (p - 1)) - 1);
    }
    resor |= val[i];
  }
  if (totcnt == 1) {
    for (int i = 1; i <= n; i++) {
      if (val[i] == 1000000001) {
        val[i] = 0;
        for (int j = 29; j >= 0; j--)
          if (!((resor >> j) & 1) && (val[i] | (1 << j)) <= 1000000000)
            val[i] |= (1 << j);
        break;
      }
    }
  }
  puts("YES");
  for (int i = 1; i <= n; i++) printf("%d ", val[i]);
  return 0;
}
