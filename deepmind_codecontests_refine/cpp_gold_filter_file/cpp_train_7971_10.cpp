#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int sc = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') sc = sc * 10 + ch - '0', ch = getchar();
  return sc * f;
}
const int MAXN = 500005;
int n, tag[MAXN << 2], id[MAXN];
pair<int, int> a[MAXN], mn[MAXN << 2];
set<int> in, de, ze;
inline void pushup(int x) {
  mn[x] = min(mn[x << 1], mn[x << 1 | 1]);
  mn[x].first += tag[x];
}
inline void build(int x, int l, int r) {
  if (l == r) {
    mn[x] = make_pair(a[l].first, l);
    return;
  }
  int mid = l + r >> 1;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);
  pushup(x);
}
inline void modify(int x, int l, int r, int ql, int qr, int v) {
  if (l == ql && r == qr) {
    mn[x].first += v;
    tag[x] += v;
    return;
  }
  int mid = l + r >> 1;
  if (qr <= mid)
    modify(x << 1, l, mid, ql, qr, v);
  else if (ql > mid)
    modify(x << 1 | 1, mid + 1, r, ql, qr, v);
  else
    modify(x << 1, l, mid, ql, mid, v),
        modify(x << 1 | 1, mid + 1, r, mid + 1, qr, v);
  pushup(x);
}
inline pair<int, int> query(int x, int l, int r, int ql, int qr) {
  if (l == ql && r == qr) return mn[x];
  int mid = l + r >> 1;
  pair<int, int> ret;
  if (qr <= mid)
    ret = query(x << 1, l, mid, ql, qr);
  else if (ql > mid)
    ret = query(x << 1 | 1, mid + 1, r, ql, qr);
  else
    ret = min(query(x << 1, l, mid, ql, mid),
              query(x << 1 | 1, mid + 1, r, mid + 1, qr));
  return make_pair(ret.first + tag[x], ret.second);
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i].first = read(), a[i].second = i;
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) id[a[i].second] = i;
  build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    int x = id[i];
    pair<int, int> v = query(1, 1, n, x, x);
    if (!v.first)
      ze.insert(x);
    else if (v.first > 0) {
      in.insert(x);
      modify(1, 1, n, x, n, -1);
      pair<int, int> t = query(1, 1, n, x, n);
      if (t.first < 0) {
        in.erase(t.second);
        ze.insert(t.second);
        modify(1, 1, n, t.second, n, 1);
      }
    } else {
      de.insert(x);
      modify(1, 1, n, x, n, 1);
      int p = *--de.end();
      if (a[p].first == 1 - de.size()) {
        de.erase(p);
        ze.insert(p);
        modify(1, 1, n, p, n, -1);
      } else if (ze.size()) {
        int q = *ze.begin();
        ze.erase(q);
        in.insert(q);
        modify(1, 1, n, q, n, -1);
      }
    }
    printf("%d\n", in.size() - de.size());
  }
}
