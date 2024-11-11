#include <bits/stdc++.h>
const int N = 300010;
int n, m, a[N], ans[N];
struct ft {
  int c[N];
  int lowbit(int x) { return x & (-x); }
  void change(int x, int dt) {
    while (x <= n) {
      c[x] += dt;
      x += lowbit(x);
    }
  }
  int ask(int x) {
    if (x <= 0) return 0;
    int res = 0;
    while (x) {
      res += c[x];
      x -= lowbit(x);
    }
    return res;
  }
  int sum(int x, int y) {
    if (x > y) return 0;
    return ask(y) - ask(x - 1);
  }
} t1;
struct segt {
  struct node {
    int mi, add;
  } t[N << 2];
  void maintain(int p) { t[p].mi = std::min(t[p << 1].mi, t[p << 1 | 1].mi); }
  void build(int p, int l, int r) {
    if (l == r) {
      t[p].mi = a[l];
      t[p].add = 0;
      return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    maintain(p);
  }
  void pushadd(int p, int dt) {
    t[p].mi += dt;
    t[p].add += dt;
  }
  void pushdown(int p) {
    if (t[p].add) {
      pushadd(p << 1, t[p].add);
      pushadd(p << 1 | 1, t[p].add);
      t[p].add = 0;
    }
  }
  void change(int p, int l, int r, int ql, int qr, int dt) {
    if (l >= ql && r <= qr) {
      pushadd(p, dt);
      return;
    }
    pushdown(p);
    int mid = (l + r) >> 1;
    if (ql <= mid) change(p << 1, l, mid, ql, qr, dt);
    if (qr > mid) change(p << 1 | 1, mid + 1, r, ql, qr, dt);
    maintain(p);
  }
  void ask(int p, int l, int r, int ql, int qr) {
    if (t[p].mi > 0) return;
    if (l == r) {
      t1.change(l, 1);
      if (l + 1 <= n) change(1, 1, n, l + 1, n, -1);
      t[p].mi = (n + 1);
      return;
    }
    pushdown(p);
    int mid = (l + r) >> 1;
    if (ql <= mid) ask(p << 1, l, mid, ql, qr);
    if (qr > mid) ask(p << 1 | 1, mid + 1, r, ql, qr);
    maintain(p);
  }
} t2;
struct question {
  int x, y, id;
  friend bool operator<(question a, question b) { return a.x > b.x; }
} qu[N];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    a[i] = i - a[i];
    if (a[i] < 0) a[i] = n + 1;
  }
  t2.build(1, 1, n);
  for (int i = 1; i <= m; ++i) {
    std::cin >> qu[i].x >> qu[i].y;
    qu[i].id = i;
  }
  std::sort(qu + 1, qu + m + 1);
  int L = n;
  for (int i = 1; i <= m; ++i) {
    while (L > qu[i].x) {
      t2.ask(1, 1, n, L, n);
      --L;
    }
    ans[qu[i].id] = t1.sum(qu[i].x + 1, n - qu[i].y);
  }
  for (int i = 1; i <= m; ++i) std::cout << ans[i] << '\n';
  return 0;
}
