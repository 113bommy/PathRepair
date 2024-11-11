#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5, inf = 2e9;
int h[maxn];
int n, limit, ans, L = inf, R = -inf;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return x * f;
}
struct segment_tree {
  bool clear[maxn << 2];
  long long sum[maxn << 2], tag[maxn << 2];
  void update(int p) { sum[p] = sum[p << 1] + sum[p << 1 | 1]; }
  void add_tag(int p, int l, int r, int v) {
    tag[p] += v;
    sum[p] += 1ll * (r - l + 1) * v;
  }
  void push_down(int p, int l, int r) {
    if (clear[p]) {
      clear[p << 1] = clear[p << 1 | 1] = 1;
      sum[p << 1] = sum[p << 1 | 1] = 0;
      clear[p] = 0;
    }
    if (tag[p]) {
      int mid = (l + r) >> 1;
      add_tag(p << 1, l, mid, tag[p]);
      add_tag(p << 1 | 1, mid + 1, r, tag[p]);
      tag[p] = 0;
    }
  }
  void add(int p, int l, int r, int L, int R) {
    if (L <= l && r <= R) {
      add_tag(p, l, r, 1);
      return;
    }
    int mid = (l + r) >> 1;
    push_down(p, l, r);
    if (L <= mid) add(p << 1, l, mid, L, R);
    if (R > mid) add(p << 1 | 1, mid + 1, r, L, R);
    update(p);
  }
  int query(int p, int l, int r, int pos, int v) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    push_down(p, l, r);
    if (pos <= mid) return query(p << 1, l, mid, pos, v);
    if (pos > mid) {
      if (sum[p << 1 | 1] > v) return query(p << 1 | 1, mid + 1, r, pos, v);
      return query(p << 1, l, mid, pos, v - sum[p << 1 | 1]);
    }
    return 0;
  }
  void Clear(int p, int l, int r, int L, int R) {
    if (L <= l && r <= R) {
      clear[p] = 1;
      sum[p] = 0;
      return;
    }
    int mid = (l + r) >> 1;
    push_down(p, l, r);
    if (L <= mid) Clear(p << 1, l, mid, L, R);
    if (R > mid) Clear(p << 1 | 1, mid + 1, r, L, R);
    update(p);
  }
} T;
int main() {
  n = read(), limit = read();
  for (int i = 1; i <= n; i++) {
    h[i] = read();
    L = min(L, h[i]);
    R = max(R, h[i]);
  }
  for (int i = 1; i <= n; i++) T.add(1, 1, R, 1, h[i]);
  int l = L, r = R;
  while (l < r) {
    int tmp = T.query(1, 1, R, r, limit);
    T.Clear(1, 1, R, tmp + 1, r);
    r = tmp;
    ans++;
  }
  printf("%d\n", ans);
  return 0;
}
