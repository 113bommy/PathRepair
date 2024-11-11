#include <bits/stdc++.h>
using namespace std;
int n;
struct zdq {
  int l, r;
} a[300005];
struct T {
  int ls, rs;
  long long v;
  int rnd;
  int size;
  long long lazy_add;
  void init(int val) {
    v = val;
    size = 1;
    rnd = rand();
  }
} t[1000006];
void push_up(int u) { t[u].size = t[t[u].ls].size + t[t[u].rs].size + 1; }
void push_down(int u) {
  if (t[u].lazy_add) {
    t[t[u].ls].lazy_add += t[u].lazy_add;
    t[t[u].rs].lazy_add += t[u].lazy_add;
    t[t[u].ls].v += t[u].lazy_add;
    t[t[u].rs].v += t[u].lazy_add;
    t[u].lazy_add = 0;
  }
}
int merge(int x, int y) {
  if (!x || !y) return x + y;
  int rt;
  push_down(x);
  push_down(y);
  if (t[x].rnd < t[y].rnd) {
    rt = x;
    t[x].rs = merge(t[x].rs, y);
    push_up(x);
  } else {
    rt = y;
    t[y].ls = merge(x, t[y].ls);
    push_up(y);
  }
  return rt;
}
void split_v(int rt, int &x, int &y, int v) {
  if (!rt) {
    x = y = 0;
    return;
  }
  push_down(rt);
  if (t[rt].v >= v) {
    y = rt;
    split_v(t[y].ls, x, t[y].ls, v);
  } else {
    x = rt;
    split_v(t[x].rs, t[x].rs, y, v);
  }
  push_up(rt);
}
void split_r(int rt, int &x, int &y, int rnk) {
  if (!rt) {
    x = y = 0;
    return;
  }
  push_down(rt);
  if (t[t[rt].ls].size >= rnk) {
    y = rt;
    split_r(t[y].ls, x, t[y].ls, rnk);
  } else {
    x = rt;
    split_r(t[x].rs, t[x].rs, y, rnk - t[t[x].ls].size - 1);
  }
  push_up(rt);
}
int rt = 0, cnt = 0;
void insert(int v) {
  int x, y;
  split_v(rt, x, y, v);
  cnt++;
  t[cnt].init(v);
  rt = merge(x, merge(cnt, y));
}
void add(int root, int v) {
  t[rt].v += v;
  t[rt].lazy_add += v;
}
void shan(int v) {
  int x, y, z;
  split_v(rt, x, y, v);
  split_r(y, y, z, 1);
  rt = merge(x, z);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].l >> a[i].r;
    int w, x, y, z;
    split_v(rt, x, y, a[i].l);
    split_v(y, y, z, a[i].r);
    split_r(z, w, z, 1);
    if (y) add(y, 1);
    rt = merge(x, merge(y, z));
    insert(a[i].l);
  }
  cout << t[rt].size;
  return 0;
}
