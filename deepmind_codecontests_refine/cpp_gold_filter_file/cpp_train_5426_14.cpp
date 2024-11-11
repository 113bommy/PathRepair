#include <bits/stdc++.h>
using namespace std;
inline int gi() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + ch - 48;
    ch = getchar();
  }
  return x * f;
}
template <typename T>
inline bool Max(T &a, T b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T>
inline bool Min(T &a, T b) {
  return b < a ? a = b, 1 : 0;
}
const int N = 3e5 + 7, Nd = N << 2;
int n;
int a[N];
struct data {
  int l, r;
  data() {}
  data(int l, int r) : l(l), r(r) {}
  data operator+(const data &rhs) const {
    return data(min(l, rhs.l), max(r, rhs.r));
  }
} v[N];
struct sgt {
  data t[Nd];
  int dep;
  void build(int l, int r, int o) {
    if (l == r) {
      t[o] = v[l];
      return;
    }
    int mid = l + r >> 1;
    build(l, mid, o << 1);
    build(mid + 1, r, o << 1 | 1);
    t[o] = t[o << 1] + t[o << 1 | 1];
  }
  data query(int L, int R, int l, int r, int o) {
    if (L <= l && r <= R) return t[o];
    int mid = l + r >> 1;
    if (R <= mid) return query(L, R, l, mid, o << 1);
    if (L > mid) return query(L, R, mid + 1, r, o << 1 | 1);
    return query(L, R, l, mid, o << 1) + query(L, R, mid + 1, r, o << 1 | 1);
  }
} sg[20];
int main() {
  n = gi();
  if (n == 1) return puts("0"), 0;
  for (int i = 1; i <= n; ++i) a[i] = gi(), a[i + n] = a[i + 2 * n] = a[i];
  for (int i = 0; i <= 19; ++i) sg[i].dep = i;
  for (int i = 1; i <= 3 * n; ++i)
    v[i].l = max(1, i - a[i]), v[i].r = min(3 * n, i + a[i]);
  sg[0].build(1, 3 * n, 1);
  for (int dep = 1; dep <= 19; ++dep) {
    for (int i = 1; i <= 3 * n; ++i)
      v[i] = sg[dep - 1].query(v[i].l, v[i].r, 1, 3 * n, 1);
    sg[dep].build(1, 3 * n, 1);
  }
  for (int i = n + 1; i <= n + n; ++i) {
    data now(i, i), tmp;
    int cnt = 0;
    for (int k = 19; ~k; --k) {
      tmp = sg[k].query(now.l, now.r, 1, 3 * n, 1);
      if (tmp.r - tmp.l + 1 < n) cnt += 1 << k, now = tmp;
    }
    printf("%d%c", cnt + 1, i == n + n ? '\n' : ' ');
  }
  return 0;
}
