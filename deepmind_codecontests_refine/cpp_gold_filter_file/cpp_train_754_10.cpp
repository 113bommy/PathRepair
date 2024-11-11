#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5, mod = 998244353;
template <class o>
inline void qr(o &x) {
  x = 0;
  char c = getchar();
  int f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + (c ^ 48);
    c = getchar();
  }
  x *= f;
}
template <class o>
void qw(o x) {
  if (x / 10) qw(x / 10);
  putchar(x % 10 + 48);
}
template <class o>
void pr1(o x) {
  if (x < 0) putchar('-'), x = -x;
  qw(x);
  putchar(' ');
}
template <class o>
void pr2(o x) {
  if (x < 0) putchar('-'), x = -x;
  qw(x);
  puts("");
}
int ch[N << 1][2], yss[N << 1], w[N], ed[N << 1];
int st[N << 1], cnt, fa[N << 1], num;
pair<int, int> d[N << 4];
void dfs(int x) {
  st[x] = cnt + 1;
  if (!ch[x][0]) yss[++cnt] = x;
  for (int i = 0; i < 2; ++i)
    if (ch[x][i]) dfs(ch[x][i]);
  ed[x] = cnt;
}
void upd(int p) { d[p] = max(d[p << 1], d[p << 1 | 1]); }
void build(int p, int l, int r) {
  if (l == r) {
    d[p] = make_pair(w[yss[l]], l);
    return;
  };
  int mid = l + r >> 1;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
  upd(p);
}
pair<int, int> ask(int p, int l, int r, int L, int R) {
  if (L <= l && R >= r) {
    return d[p];
  }
  int mid = l + r >> 1;
  pair<int, int> val = make_pair(0, 0);
  if (L <= mid) val = ask(p << 1, l, mid, L, R);
  if (R > mid) val = max(val, ask(p << 1 | 1, mid + 1, r, L, R));
  return val;
}
void change(int p, int l, int r, int pos) {
  if (l == r) {
    d[p] = make_pair(0, 0);
    return;
  }
  int mid = l + r >> 1;
  if (pos <= mid)
    change(p << 1, l, mid, pos);
  else
    change(p << 1 | 1, mid + 1, r, pos);
  upd(p);
}
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x != y) {
    ++num, fa[num] = num, fa[x] = num, fa[y] = num;
    ch[num][0] = x, ch[num][1] = y;
  }
}
pair<int, int> e[N], q[N << 1];
bool loc[N];
void solve() {
  int n, m, Q;
  qr(n), qr(m), qr(Q);
  num = n;
  cnt = 0;
  for (int i = 1; i <= n; ++i) fa[i] = i, qr(w[i]);
  for (int i = 1; i <= m; ++i) loc[i] = 0, qr(e[i].first), qr(e[i].second);
  for (int i = 1; i <= Q; ++i) {
    qr(q[i].first), qr(q[i].second);
    if (q[i].first == 2) loc[q[i].second] = 1;
  }
  for (int i = 1; i <= m; ++i)
    if (!loc[i]) merge(e[i].first, e[i].second);
  for (int i = Q; i; i--) {
    if (q[i].first == 1)
      q[i].second = find(q[i].second);
    else {
      int j = q[i].second;
      merge(e[j].first, e[j].second);
    }
  }
  for (int i = 1; i <= n; ++i)
    if (!st[i]) dfs(find(i));
  build(1, 1, n);
  for (int i = 1; i <= Q; ++i)
    if (q[i].first == 1) {
      int x = q[i].second;
      pair<int, int> d = ask(1, 1, n, st[x], ed[x]);
      if (d.first) change(1, 1, n, d.second);
      pr2(d.first);
    }
}
int main() {
  solve();
  return 0;
}
