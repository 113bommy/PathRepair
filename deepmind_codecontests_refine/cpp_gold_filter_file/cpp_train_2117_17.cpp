#include <bits/stdc++.h>
using namespace std;
const int M = 100000 + 10;
struct BUS {
  int s, f, t;
  int index;
  bool operator<(const BUS& x) const { return s < x.s; }
} bus[M];
struct PA {
  int l, r, b;
  int index;
  bool operator<(const PA& x) const { return l < x.l; }
} pa[M];
int pos[4 * M];
const int MAX = 2000000000;
struct TREE {
  int l, r;
  int eid;
  int busindex;
} tree[16 * M];
void build(int l, int r, int node) {
  tree[node].l = l;
  tree[node].r = r;
  tree[node].eid = -1;
  tree[node].busindex = -1;
  if (l == r) {
    return;
  } else {
    int mid = (l + r) / 2;
    build(l, mid, node * 2);
    build(mid + 1, r, 2 * node + 1);
    return;
  }
}
void modify(int node, int busid) {
  int l = tree[node].l;
  int r = tree[node].r;
  if (l == r) {
    if (bus[busid].f > tree[node].eid) {
      tree[node].eid = bus[busid].f;
      tree[node].busindex = bus[busid].index;
    }
    return;
  }
  int mid = (l + r) / 2;
  if (bus[busid].t <= mid) {
    modify(2 * node, busid);
  } else {
    modify(2 * node + 1, busid);
  }
  tree[node].eid = max(tree[2 * node].eid, tree[2 * node + 1].eid);
  return;
}
int query(int node, int paid) {
  int l = tree[node].l;
  int r = tree[node].r;
  if (tree[node].eid < pa[paid].r) {
    return -1;
  }
  if (l == r) {
    return tree[node].busindex;
  }
  int mid = (l + r) / 2;
  if (pa[paid].b > mid) {
    return query(2 * node + 1, paid);
  } else {
    int tmp = query(2 * node, paid);
    if (tmp > 0) {
      return tmp;
    } else {
      return query(2 * node + 1, paid);
    }
  }
}
int ans[M];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int tid = 0;
  for (int i = 0; i < n; i++) {
    int s, f, t;
    scanf("%d %d %d", &s, &f, &t);
    bus[i].s = s;
    bus[i].f = f;
    bus[i].t = t;
    bus[i].index = i + 1;
    pos[tid++] = bus[i].t;
  }
  for (int i = 0; i < m; i++) {
    int l, r, b;
    scanf("%d %d %d", &l, &r, &b);
    pa[i].l = l;
    pa[i].r = r;
    pa[i].b = b;
    pa[i].index = i + 1;
    pos[tid++] = pa[i].b;
  }
  sort(pos, pos + tid);
  int rid = tid;
  for (int i = 0; i < n; i++) {
    int id = lower_bound(pos, pos + rid, bus[i].t) - pos;
    bus[i].t = id + 1;
  }
  build(1, rid, 1);
  for (int i = 0; i < m; i++) {
    int id = lower_bound(pos, pos + rid, pa[i].b) - pos;
    pa[i].b = id + 1;
  }
  sort(bus, bus + n);
  sort(pa, pa + m);
  int busid = 0;
  for (int i = 0; i < m; i++) {
    while (busid < n && bus[busid].s <= pa[i].l) {
      modify(1, busid);
      busid++;
    }
    int ansid = query(1, i);
    ans[pa[i].index] = ansid;
  }
  for (int i = 1; i <= m; i++) {
    printf("%d", ans[i]);
    if (i < m) {
      printf(" ");
    } else {
      printf("\n");
    }
  }
  return 0;
}
