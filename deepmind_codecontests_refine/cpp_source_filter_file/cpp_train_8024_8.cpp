#include <bits/stdc++.h>
using namespace std;
void read(int &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -f;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  x *= f;
}
void print(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (!x) return;
  print(x / 10), putchar(x % 10 + 48);
}
void write(int x) {
  if (!x)
    putchar('0');
  else
    print(x);
  putchar('\n');
}
const int maxn = 1e5 + 10;
const int inf = 1e9;
const double eps = 1e-8;
const int mod = 1e9 + 7;
int n, m, xx, a[maxn];
struct node {
  pair<int, int> l[21], r[21];
  int t1, t2;
  long long ans;
  node() { t1 = t2 = ans = 0; }
  void init(int x) {
    l[t1 = 1] = make_pair(x, 1), r[t2 = 1] = make_pair(x, 1);
    ans = x >= xx;
  }
} t[maxn << 2];
node merge(node x, node y) {
  node a;
  a.ans = x.ans + y.ans;
  for (int i = 1; i <= x.t1; i++) a.l[i] = x.l[i];
  a.t1 = x.t1;
  for (int i = 1, v; i <= y.t1; i++)
    if (!a.t1 || ((v = a.l[a.t1].first | y.l[i].first) != a.l[a.t1].first))
      a.l[++a.t1] = make_pair(v, y.l[i].second);
    else
      a.l[a.t1].second += y.l[i].second;
  for (int i = 1; i <= y.t2; i++) a.r[i] = y.r[i];
  a.t2 = y.t2;
  for (int i = 1, v; i <= x.t2; i++)
    if (!a.t2 || ((v = a.r[a.t2].first | x.r[i].first) != a.r[a.t2].first))
      a.r[++a.t2] = make_pair(v, x.r[i].second);
    else
      a.r[a.t2].second += x.r[i].second;
  for (int i = 1; i <= x.t2; i++)
    for (int j = 1; j <= y.t1; j++)
      if ((x.r[i].first | y.l[j].first) >= xx)
        a.ans += x.r[i].second * y.l[j].second;
  return a;
}
void build(int p, int l, int r) {
  if (l == r) return t[p].init(a[l]), void();
  build(p << 1, l, ((l + r) >> 1)), build(p << 1 | 1, ((l + r) >> 1) + 1, r),
      t[p] = merge(t[p << 1], t[p << 1 | 1]);
}
void modify(int p, int l, int r, int x, int v) {
  if (l == r) return t[p].init(v), void();
  if (x <= ((l + r) >> 1))
    modify(p << 1, l, ((l + r) >> 1), x, v);
  else
    modify(p << 1 | 1, ((l + r) >> 1) + 1, r, x, v);
  t[p] = merge(t[p << 1], t[p << 1 | 1]);
}
node query(int p, int l, int r, int x, int y) {
  if (x <= l && r <= y) return t[p];
  if (y <= ((l + r) >> 1))
    return query(p << 1, l, ((l + r) >> 1), x, y);
  else if (x > ((l + r) >> 1))
    return query(p << 1 | 1, ((l + r) >> 1) + 1, r, x, y);
  else
    return merge(query(p << 1, l, ((l + r) >> 1), x, y),
                 query(p << 1 | 1, ((l + r) >> 1) + 1, r, x, y));
}
int main() {
  read(n), read(m), read(xx);
  for (int i = 1; i <= n; i++) read(a[i]);
  build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    int op, x, y;
    read(op), read(x), read(y);
    if (op == 1)
      modify(1, 1, n, x, y);
    else
      printf("%lld\n", query(1, 1, n, x, y).ans);
  }
  return 0;
}
