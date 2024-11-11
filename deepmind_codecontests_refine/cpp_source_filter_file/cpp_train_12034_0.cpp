#include <bits/stdc++.h>
using namespace std;
struct info {
  vector<long long> d;
  vector<char> c;
  bool hasCarry;
};
info createN(int val) {
  info r;
  r.d = vector<long long>(10);
  r.c = vector<char>(10);
  for (int i = 0; i < 10; i++) r.c[i] = i;
  int p = 1;
  while (val) {
    r.d[val % 10] += p;
    p *= 10;
    val /= 10;
  }
  r.hasCarry = 0;
  return r;
}
info join(info p1, info p2) {
  info r = p1;
  for (int i = 0; i < 10; i++) r.d[i] += p2.d[i], r.c[i] = i;
  r.hasCarry = 0;
  return r;
}
void updateR(info &p, int u, int v) {
  for (int i = 0; i < 10; i++) {
    if (p.c[i] == u) {
      p.c[i] = v;
    }
  }
  long long t = p.d[u];
  p.d[u] = 0;
  p.d[v] += t;
  p.hasCarry = 1;
}
void updateR(info &p, vector<char> c) {
  vector<char> tc(10);
  for (int i = 0; i < 10; i++) tc[i] = c[p.c[i]];
  p.c = tc;
  vector<long long> d(10);
  for (int i = 0; i < 10; i++) d[p.c[i]] += p.d[i];
  p.d = d;
  p.hasCarry = 1;
}
info st[400000];
int N, a[100010];
void create(int n = 1, int l = 0, int r = N) {
  if (l == r)
    st[n] = createN(a[r]);
  else {
    int m = (l + r) / 2;
    create(2 * n, l, m);
    create(2 * n + 1, m + 1, r);
    st[n] = st[2 * n];
    for (int i = 0; i < 10; i++) st[n].d[i] += st[2 * n + 1].d[i];
  }
}
long long query(int x, int y, int n = 1, int l = 0, int r = N) {
  if (x <= l && r <= y) {
    long long g = 0;
    for (int i = 1; i < 10; i++) g += st[n].d[i] * i;
    return g;
  } else {
    int m = (l + r) / 2;
    if (st[n].hasCarry) {
      updateR(st[2 * n], st[n].c);
      updateR(st[2 * n + 1], st[n].c);
      for (int i = 0; i < 10; i++)
        st[n].d[i] = st[2 * n].d[i] + st[2 * n + 1].d[i], st[n].c[i] = i;
      st[n].hasCarry = 0;
    }
    long long g = 0;
    if (x <= m) g += query(x, y, 2 * n, l, m);
    if (y > m) g += query(x, y, 2 * n + 1, m + 1, r);
    return g;
  }
}
void update(int x, int y, int u, int v, int n = 1, int l = 0, int r = N) {
  if (x <= l && r <= y)
    updateR(st[n], u, v);
  else {
    int m = (l + r) / 2;
    if (st[n].hasCarry) {
      updateR(st[2 * n], st[n].c);
      updateR(st[2 * n + 1], st[n].c);
    }
    if (x <= m) update(x, y, u, v, 2 * n, l, m);
    if (y > m) update(x, y, u, v, 2 * n + 1, m + 1, r);
    for (int i = 0; i < 10; i++)
      st[n].d[i] = st[2 * n].d[i] + st[2 * n + 1].d[i], st[n].c[i] = i;
    st[n].hasCarry = 0;
  }
}
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  N = n - 1;
  create();
  while (q--) {
    int op, l, r;
    scanf("%d%d%d", &op, &l, &r);
    l--, r--;
    if (op & 1) {
      int u, v;
      scanf("%d%d", &u, &v);
      update(l, r, u, v);
    } else
      printf("%I64d\n", query(l, r));
  }
}
