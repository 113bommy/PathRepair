#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn], pos[maxn];
int n;
struct segtree {
  int cnt[maxn << 2], val[maxn << 2];
  long long seg[maxn << 2];
  int tag_val[maxn << 2];
  long long get_val(int v) { return seg[v] + 1LL * cnt[v] * tag_val[v]; }
  void pushdown(int v) {
    tag_val[v << 1] += tag_val[v];
    tag_val[v << 1 | 1] += tag_val[v];
    tag_val[v] = 0;
  }
  void pushup(int v) {
    seg[v] = get_val(v << 1) + get_val(v << 1 | 1);
    cnt[v] = cnt[v << 1] + cnt[v << 1 | 1];
    val[v] = val[v << 1] + val[v << 1 | 1];
  }
  void update_val(int l, int r, int ql, int qr, int v) {
    if (ql > r || l > qr) return;
    if (ql <= l && r <= qr) {
      ++tag_val[v];
      return;
    }
    pushdown(v);
    int mid = (l + r) >> 1;
    if (ql <= mid) update_val(l, mid, ql, qr, v << 1);
    if (qr > mid) update_val(mid + 1, r, ql, qr, v << 1 | 1);
    pushup(v);
  }
  void update_cnt(int l, int r, int x, int v, int nval) {
    if (l == r) {
      cnt[v] += nval;
      return;
    }
    pushdown(v);
    int mid = (l + r) >> 1;
    if (x <= mid)
      update_cnt(l, mid, x, v << 1, nval);
    else
      update_cnt(mid + 1, r, x, v << 1 | 1, nval);
    pushup(v);
  }
  int ask_cnt(int l, int r, int x, int v) {
    if (l == r) return cnt[v];
    pushdown(v);
    int mid = (l + r) >> 1, res;
    if (x <= mid) res = ask_cnt(l, mid, x, v << 1);
    if (x > mid) res = ask_cnt(mid + 1, r, x, v << 1 | 1);
    pushup(v);
    return res;
  }
  int ask_val(int l, int r, int x, int v) {
    if (l == r) return val[v] + tag_val[v];
    pushdown(v);
    int mid = (l + r) >> 1, res;
    if (x <= mid) res = ask_cnt(l, mid, x, v << 1);
    if (x > mid) res = ask_cnt(mid + 1, r, x, v << 1 | 1);
    pushup(v);
    return res;
  }
} seg;
struct segtree_max {
  int fi[maxn << 2], se[maxn << 2], tag[maxn << 2];
  int cnt[maxn << 2];
  void pushup(int v) {
    fi[v] = min(fi[v << 1], fi[v << 1 | 1]);
    if (fi[v << 1] == fi[v << 1 | 1]) {
      cnt[v] = cnt[v << 1] + cnt[v << 1 | 1];
      se[v] = min(se[v << 1], se[v << 1 | 1]);
    } else if (fi[v << 1] < fi[v << 1 | 1]) {
      cnt[v] = cnt[v << 1];
      se[v] = min(fi[v << 1 | 1], se[v << 1]);
    } else {
      cnt[v] = cnt[v << 1 | 1];
      se[v] = min(fi[v << 1], se[v << 1 | 1]);
    }
  }
  void pushdown(int v) {
    if (tag[v]) {
      if (tag[v] > fi[v << 1]) {
        fi[v << 1] = tag[v << 1] = tag[v];
      }
      if (tag[v] > fi[v << 1 | 1]) {
        fi[v << 1 | 1] = tag[v << 1 | 1] = tag[v];
      }
      tag[v] = 0;
    }
  }
  void init(int l, int r, int v = 1) {
    if (l == r) {
      fi[v] = n + 2;
      se[v] = INT_MAX;
      cnt[v] = 1;
      return;
    }
    int mid = (l + r) >> 1;
    init(l, mid, v << 1);
    init(mid + 1, r, v << 1 | 1);
    pushup(v);
  }
  void update(int l, int r, int ql, int qr, int nval, int v) {
    if (ql > qr || ql > r || l > qr || nval <= fi[v]) return;
    if (ql <= l && r <= qr) {
      if (nval < se[v]) {
        seg.update_cnt(0, n + 1, fi[v] - 1, 1, +cnt[v]);
        fi[v] = nval;
        seg.update_cnt(0, n + 1, fi[v] - 1, 1, -cnt[v]);
        tag[v] = nval;
        return;
      }
    }
    pushdown(v);
    int mid = (l + r) >> 1;
    if (ql <= mid) update(l, mid, ql, qr, nval, v << 1);
    if (qr > mid) update(mid + 1, r, ql, qr, nval, v << 1 | 1);
    pushup(v);
  }
  void set(int l, int r, int x, int val, int v) {
    if (l == r) {
      seg.update_cnt(0, n + 1, fi[v] - 1, 1, +cnt[v]);
      fi[v] = val;
      seg.update_cnt(0, n + 1, fi[v] - 1, 1, -cnt[v]);
      cnt[v] = 1;
      tag[v] = 0;
      return;
    }
    pushdown(v);
    int mid = (l + r) >> 1;
    if (x <= mid)
      set(l, mid, x, val, v << 1);
    else
      set(mid + 1, r, x, val, v << 1 | 1);
    pushup(v);
  }
} segl;
struct segtree_min {
  int fi[maxn << 2], se[maxn << 2], tag[maxn << 2];
  int cnt[maxn << 2];
  void pushup(int v) {
    fi[v] = max(fi[v << 1], fi[v << 1 | 1]);
    if (fi[v << 1] == fi[v << 1 | 1]) {
      cnt[v] = cnt[v << 1] + cnt[v << 1 | 1];
      se[v] = max(se[v << 1], se[v << 1 | 1]);
    } else if (fi[v << 1] > fi[v << 1 | 1]) {
      cnt[v] = cnt[v << 1];
      se[v] = max(fi[v << 1 | 1], se[v << 1]);
    } else {
      cnt[v] = cnt[v << 1 | 1];
      se[v] = max(fi[v << 1], se[v << 1 | 1]);
    }
  }
  void pushdown(int v) {
    if (tag[v]) {
      if (tag[v] < fi[v << 1]) {
        fi[v << 1] = tag[v << 1] = tag[v];
      }
      if (tag[v] < fi[v << 1 | 1]) {
        fi[v << 1 | 1] = tag[v << 1 | 1] = tag[v];
      }
      tag[v] = 0;
    }
  }
  void init(int l, int r, int v = 1) {
    if (l == r) {
      fi[v] = 0;
      se[v] = INT_MIN;
      cnt[v] = 1;
      return;
    }
    int mid = (l + r) >> 1;
    init(l, mid, v << 1);
    init(mid + 1, r, v << 1 | 1);
    pushup(v);
  }
  void update(int l, int r, int ql, int qr, int nval, int v) {
    if (ql > qr || ql > r || l > qr || nval >= fi[v]) return;
    if (ql <= l && r <= qr) {
      if (nval > se[v]) {
        seg.update_cnt(0, n + 1, fi[v], 1, -cnt[v]);
        fi[v] = nval;
        seg.update_cnt(0, n + 1, fi[v], 1, +cnt[v]);
        tag[v] = nval;
        return;
      }
    }
    pushdown(v);
    int mid = (l + r) >> 1;
    if (ql <= mid) update(l, mid, ql, qr, nval, v << 1);
    if (qr > mid) update(mid + 1, r, ql, qr, nval, v << 1 | 1);
    pushup(v);
  }
  void set(int l, int r, int x, int val, int v) {
    if (l == r) {
      seg.update_cnt(0, n + 1, fi[v], 1, -cnt[v]);
      fi[v] = val;
      seg.update_cnt(0, n + 1, fi[v], 1, +cnt[v]);
      cnt[v] = 1;
      tag[v] = 0;
      return;
    }
    pushdown(v);
    int mid = (l + r) >> 1;
    if (x <= mid)
      set(l, mid, x, val, v << 1);
    else
      set(mid + 1, r, x, val, v << 1 | 1);
    pushup(v);
  }
} segr;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    pos[a[i]] = i;
  }
  segr.init(1, n);
  segl.init(1, n);
  seg.update_cnt(0, n + 1, 0, 1, -n);
  seg.update_cnt(0, n + 1, n + 1, 1, n);
  for (int i = 1; i <= n; ++i) {
    segr.update(1, n, 1, pos[i] - 1, pos[i] - 1, 1);
    segl.update(1, n, pos[i] + 1, n, pos[i] + 1, 1);
    segl.set(1, n, pos[i], 1, 1);
    segr.set(1, n, pos[i], n, 1);
    seg.update_val(0, n + 1, pos[i], n, 1);
    printf("%d\n", seg.get_val(1));
  }
  return 0;
}
