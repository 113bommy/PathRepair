#include <bits/stdc++.h>
inline int read() {
  int data = 0, w = 1;
  char ch = getchar();
  while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
  if (ch == '-') w = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') data = data * 10 + (ch ^ 48), ch = getchar();
  return data * w;
}
const int N(1e5 + 10);
const long long INF(1e18);
struct tag {
  long long a, d;
} t[N];
int n, rt, cur, fa[N], son[2][N], size[N];
long long val[N];
inline tag operator+(const tag &lhs, const tag &rhs) {
  return (tag){lhs.a + rhs.a, lhs.d + rhs.d};
}
inline int getSon(int x) { return son[1][fa[x]] == x; }
inline void update(int x) { size[x] = size[son[0][x]] + size[son[1][x]] + 1; }
inline void puttag(int x, const tag &a) {
  val[x] += a.d * (size[son[0][x]] + 1) + a.a, t[x] = t[x] + a;
}
inline void pushdown(int x) {
  if (!t[x].a && !t[x].d) return;
  if (son[0][x]) puttag(son[0][x], t[x]);
  if (son[1][x])
    puttag(son[1][x], (tag){t[x].a + t[x].d * (size[son[0][x]] + 1), t[x].d});
  t[x] = (tag){0, 0};
}
void rotate(int x) {
  int f = fa[x], g = fa[f], l = getSon(x), r = l ^ 1;
  if (g)
    son[getSon(f)][g] = x;
  else
    rt = x;
  fa[x] = g, fa[f] = x, fa[son[r][x]] = f;
  son[l][f] = son[r][x], son[r][x] = f;
  update(f), update(x);
}
void Splay(int x, int f = 0) {
  for (; fa[x] != f; rotate(x))
    if (fa[fa[x]] != f) rotate(getSon(fa[x]) ^ getSon(x) ? x : fa[x]);
}
long long k_th(int k) {
  for (int t = rt; t;) {
    pushdown(t);
    int s = size[son[0][t]] + 1;
    if (k > s)
      t = son[1][t], k -= s;
    else if (k == s)
      return Splay(t), val[t];
    else
      t = son[0][t];
  }
  return -INF;
}
long long getAns(int x) {
  if (!x) return -INF;
  pushdown(x);
  return std::max(val[x], std::max(getAns(son[0][x]), getAns(son[1][x])));
}
int main() {
  n = read(), size[1] = rt = cur = 1;
  for (int i = 1, a, l, r, t; i <= n; i++) {
    a = read(), l = 0, r = i - 2, t = i - 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (k_th(mid + 1) + 1ll * a * (mid + 1) > k_th(mid + 2))
        t = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    k_th(t + 1), ++cur;
    fa[cur] = rt, fa[son[1][rt]] = cur, son[1][cur] = son[1][rt];
    son[1][rt] = cur, val[cur] = val[rt];
    puttag(cur, (tag){1ll * t * a, a});
  }
  printf("%lld\n", getAns(rt));
  return 0;
}
