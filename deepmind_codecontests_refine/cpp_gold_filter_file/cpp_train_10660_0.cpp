#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7fffffff;
const int N = 150010;
struct s_tree {
  int _min[N << 2], tag[N << 2];
  void pushdown(int p, int L, int R) {
    int l = (((p) << 1) + 1), r = (((p) << 1) + 2);
    _min[p] += tag[p];
    int d = tag[p];
    tag[p] = 0;
    if (L == R) return;
    tag[l] += d;
    tag[r] += d;
  }
  void upd(int p, int L, int R) {
    int l = (((p) << 1) + 1), r = (((p) << 1) + 2);
    pushdown(l, L, L + R >> 1);
    pushdown(r, ((L + R) >> 1) + 1, R);
    _min[p] = min(_min[l], _min[r]);
  }
  void insert(int p, int l, int r, int h, int e, int c) {
    pushdown(p, l, r);
    if (l == h && r == e) {
      tag[p] += c;
      return;
    }
    int mid = l + r >> 1;
    if (h <= mid) insert((((p) << 1) + 1), l, mid, h, min(mid, e), c);
    if (e > mid) insert((((p) << 1) + 2), mid + 1, r, max(mid + 1, h), e, c);
    upd(p, l, r);
  }
  int query(int p, int l, int r, int h, int e) {
    pushdown(p, l, r);
    if (l == h && r == e) {
      return _min[p];
    }
    int al, ar;
    al = ar = inf;
    int mid = l + r >> 1;
    if (h <= mid) al = query((((p) << 1) + 1), l, mid, h, min(mid, e));
    if (e > mid) ar = query((((p) << 1) + 2), mid + 1, r, max(mid + 1, h), e);
    upd(p, l, r);
    return min(al, ar);
  }
} st;
int n, len, h, a[N], b[N], d[N];
int main() {
  scanf("%d%d%d", &n, &len, &h);
  for (int i = 0; i < len; i++) scanf("%d", &b[i]);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(b, b + len);
  for (int i = 0; i < n; i++) {
    int l = 0, r = len - 1, mid, t = -1;
    while (l <= r) {
      mid = l + r >> 1;
      if (b[mid] + a[i] >= h)
        t = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    if (t != -1)
      d[i] = t;
    else
      d[i] = len;
  }
  for (int i = 0; i < len; i++) st.insert(0, 0, len, i, i, len - i);
  int ans = 0;
  for (int i = 0; i < len; i++) {
    st.insert(0, 0, len, 0, d[i], -1);
  }
  if (st.query(0, 0, len, 0, len) >= 0) ans++;
  for (int i = 1; i + len - 1 < n; i++) {
    st.insert(0, 0, len, 0, d[i - 1], 1);
    st.insert(0, 0, len, 0, d[i + len - 1], -1);
    if (st.query(0, 0, len, 0, len) >= 0) {
      ans++;
    }
  }
  printf("%d\n", ans);
}
