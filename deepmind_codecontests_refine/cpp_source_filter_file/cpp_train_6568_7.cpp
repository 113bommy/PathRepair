#include <bits/stdc++.h>
using namespace std;
void Rd(int &res) {
  res = 0;
  char c;
  while (c = getchar(), c < 48)
    ;
  do res = (res << 1) + (res << 3) + (c ^ 48);
  while (c = getchar(), c > 47);
}
struct edge {
  int to, nxt;
  edge(int _to = 0, int _nxt = 0) : to(_to), nxt(_nxt) {}
} G[100005 << 1];
struct node {
  int op, a;
} Q[200005];
int head[100005];
int tol;
void addedge(int a, int b) {
  G[++tol] = edge(b, head[a]);
  head[a] = tol;
}
int n, m;
namespace P4 {
struct date {
  int sum;
  int all;
};
date T[100005 << 2];
bool Flag[100005];
int Fa[100005];
int Sz[100005];
int Son[100005];
void dfs1(int x, int f) {
  Sz[x] = 1;
  Fa[x] = f;
  Son[x] = 0;
  for (int i = head[x]; ~i; i = G[i].nxt) {
    int y = G[i].to;
    if (y == f) continue;
    dfs1(y, x);
    Sz[x] += Sz[y];
    if (Sz[y] > Sz[Son[x]]) Son[x] = y;
  }
}
int Lt[100005], Rt[100005], tid;
int Top[100005];
void dfs2(int x, int tp) {
  Top[x] = tp;
  Lt[x] = ++tid;
  if (Son[x]) dfs2(Son[x], tp);
  for (int i = head[x]; ~i; i = G[i].nxt) {
    int y = G[i].to;
    if (y == Fa[x] || y == Son[x]) continue;
    dfs2(y, y);
  }
  Rt[x] = tid;
}
void Build(int L, int R, int p) {
  T[p].all = -1;
  T[p].sum = -(R - L + 1);
  if (L == R) return;
  int mid = (L + R) >> 1;
  Build(L, mid, p << 1);
  Build(mid + 1, R, p << 1 | 1);
}
void Date(int p, int L, int R) {
  T[p].all = -1;
  T[p].sum = -(R - L + 1);
  Flag[p] = 1;
}
void Down(int p, int L, int R) {
  if (Flag[p]) {
    int mid = (L + R) >> 1;
    Date(p << 1, L, mid);
    Date(p << 1 | 1, mid + 1, R);
    Flag[p] = 0;
  }
}
void Up(date &a, date b, date c) {
  a.sum = b.sum + c.sum;
  a.all = max(c.all, c.sum + b.all);
}
void Modify(int L, int R, int p, int l, int r) {
  if (L == l && R == r) {
    Flag[p] = 1;
    T[p].all = -1;
    T[p].sum = -(R - L + 1);
    return;
  }
  Down(p, L, R);
  int mid = (L + R) >> 1;
  if (r <= mid)
    Modify(L, mid, p << 1, l, r);
  else if (l > mid)
    Modify(mid + 1, R, p << 1 | 1, l, r);
  else
    Modify(L, mid, p << 1, l, mid), Modify(mid + 1, R, p << 1 | 1, mid + 1, r);
  Up(T[p], T[p << 1], T[p << 1 | 1]);
}
void Release(int L, int R, int p, int x, int a) {
  if (L == R) {
    T[p].sum -= a;
    T[p].all -= a;
    return;
  }
  Down(p, L, R);
  int mid = (L + R) >> 1;
  if (x <= mid)
    Release(L, mid, p << 1, x, a);
  else
    Release(mid + 1, R, p << 1 | 1, x, a);
  Up(T[p], T[p << 1], T[p << 1 | 1]);
}
void Plague(int L, int R, int p, int x) {
  if (L == R) {
    T[p].sum++;
    T[p].all++;
    return;
  }
  Down(p, L, R);
  int mid = (L + R) >> 1;
  if (x <= mid)
    Plague(L, mid, p << 1, x);
  else
    Plague(mid + 1, R, p << 1 | 1, x);
  Up(T[p], T[p << 1], T[p << 1 | 1]);
}
date Query(int L, int R, int p, int l, int r) {
  if (L == l && R == r) return T[p];
  Down(p, L, R);
  int mid = (L + R) >> 1;
  if (r <= mid)
    return Query(L, mid, p << 1, l, r);
  else if (l > mid)
    return Query(mid + 1, R, p << 1 | 1, l, r);
  else {
    date res;
    Up(res, Query(L, mid, p << 1, l, mid),
       Query(mid + 1, R, p << 1 | 1, mid + 1, r));
    return res;
  }
}
int Answer(int a) {
  date res;
  res.sum = 0;
  res.all = -1;
  while (a) {
    Up(res, Query(1, n, 1, Lt[Top[a]], Lt[a]), res);
    a = Fa[Top[a]];
  }
  return res.all;
}
void Solve() {
  dfs1(1, 0);
  dfs2(1, 1);
  Build(1, n, 1);
  for (int i = (1), i_END_ = (m); i <= i_END_; ++i) {
    int op = Q[i].op, a = Q[i].a;
    if (op == 1) {
      Plague(1, n, 1, Lt[a]);
    } else if (op == 2) {
      Modify(1, n, 1, Lt[a], Rt[a]);
      int res = Answer(a);
      if (res >= 0) Release(1, n, 1, Lt[a], res + 1);
    } else {
      int res = Answer(a);
      puts(res >= 0 ? "black" : "white");
    }
  }
}
}  // namespace P4
int main() {
  Rd(n);
  Rd(m);
  for (int i = (1), i_END_ = (n); i <= i_END_; ++i) head[i] = -1;
  int a;
  for (int i = (2), i_END_ = (n); i <= i_END_; ++i) {
    Rd(a);
    addedge(i, a);
    addedge(a, i);
  }
  for (int i = (1), i_END_ = (m); i <= i_END_; ++i) Rd(Q[i].op), Rd(Q[i].a);
  P4::Solve();
  return 0;
}
