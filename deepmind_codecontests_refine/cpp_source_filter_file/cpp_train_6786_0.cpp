#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, F = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') F = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * F;
}
struct Uni {
  int p[1000000 + 5], num;
  void add(int x) { p[++num] = x; }
  void process() {
    sort(p + 1, p + num + 1);
    num = unique(p + 1, p + num + 1) - p - 1;
  }
  int get_num(int x) { return lower_bound(p + 1, p + num + 1, x) - p; }
} U;
struct Seg_tree {
  struct node {
    long long mx, tag;
    int pos;
  } p[(1000000 << 2) + 5];
  void add(int x, long long val) { p[x].tag += val, p[x].mx += val; }
  void pushup(int x) {
    p[x].pos =
        p[x << 1].mx > p[x << 1 | 1].mx ? p[x << 1].pos : p[x << 1 | 1].pos;
    p[x].mx = max(p[x << 1].mx, p[x << 1 | 1].mx);
  }
  void pushdown(int x) {
    if (p[x].tag) {
      add(x << 1, p[x].tag);
      add(x << 1 | 1, p[x].tag);
      p[x].tag = 0;
    }
  }
  void Build(int x, int l, int r) {
    if (l == r) {
      p[x].pos = p[x].mx = U.p[l];
      return;
    }
    int mid = (l + r) >> 1;
    Build(x << 1, l, mid), Build(x << 1 | 1, mid + 1, r);
    pushup(x);
  }
  void modf(int x, int l, int r, int L, int R, int val) {
    if (R < l || r < L) return;
    if (L <= l && r <= R) {
      add(x, val);
      return;
    }
    pushdown(x);
    int mid = (l + r) >> 1;
    modf(x << 1, l, mid, L, R, val);
    modf(x << 1 | 1, mid + 1, r, L, R, val);
    pushup(x);
  }
  int tmp;
  void query(int x, int l, int r, int L, int R) {
    if (R < l || r < L) return;
    if (L <= l && r <= R) {
      if (p[x].mx > p[tmp].mx) tmp = x;
      return;
    }
    pushdown(x);
    int mid = (l + r) >> 1;
    query(x << 1, l, mid, L, R);
    query(x << 1 | 1, mid + 1, r, L, R);
  }
  int Query(int L, int R) {
    tmp = 0;
    query(1, 1, U.num, L, R);
    return tmp;
  }
} T;
int n, a[1000000 + 5], b[1000000 + 5], c[1000000 + 5];
vector<int> G[1000000 + 5];
long long ans;
int L, R;
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    int t1 = read(), t2 = read();
    a[i] = min(t1, t2), b[i] = max(t1, t2), c[i] = read();
    U.add(a[i]), U.add(b[i]);
  }
  U.process();
  for (int i = 1; i <= n; i++) {
    a[i] = U.get_num(a[i]);
    b[i] = U.get_num(b[i]);
    G[b[i]].push_back(i);
  }
  T.Build(1, 1, U.num);
  T.p[0].mx = ans = -1000000000000000000;
  for (int i = 1; i <= U.num; i++) {
    for (int j = 0; j < G[i].size(); j++) {
      int tmp = G[i][j];
      T.modf(1, 1, U.num, 1, a[tmp], c[tmp]);
    }
    int vp = T.Query(1, i);
    if (T.p[vp].mx - U.p[i] > ans) {
      ans = T.p[vp].mx - U.p[i];
      L = T.p[vp].pos, R = U.p[i];
    }
  }
  if (ans <= 0) ans = 0, L = R = 1000000000;
  printf("%lld\n%d %d %d %d\n", ans, L, L, R, R);
}
