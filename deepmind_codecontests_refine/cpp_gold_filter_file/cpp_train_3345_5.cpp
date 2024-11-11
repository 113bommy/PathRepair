#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const long long inf = 1LL << 60;
int n, m, tot = 0, head[N], fa[N], dep[N];
long long T, dis[N], a[N], b[N], t[N], res[N], ans = 0, h[N];
struct Edge {
  int to, nxt;
  long long val;
} e[N << 1];
inline void add(int from, int to, long long val) {
  e[++tot].to = to;
  e[tot].nxt = head[from];
  head[from] = tot;
  e[tot].val = val;
}
template <typename T>
inline void read(T &X) {
  X = 0;
  char ch = 0;
  T op = 1;
  for (; ch > '9' || ch < '0'; ch = getchar())
    if (ch == '-') op = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar())
    X = (X << 3) + (X << 1) + ch - 48;
  X *= op;
}
template <typename T>
inline void chkMax(T &x, T y) {
  if (y > x) x = y;
}
template <typename T>
inline void chkMin(T &x, T y) {
  if (y < x) x = y;
}
namespace SegT {
struct Node {
  int lc, rc;
  long long sum, suma;
} s[N * 40];
int root[N], nodeCnt = 0;
void ins(int &p, int l, int r, int x, long long y, int pre) {
  s[p = ++nodeCnt] = s[pre];
  s[p].sum += y * b[x], s[p].suma += y;
  if (l == r) return;
  if (x <= ((l + r) >> 1))
    ins(s[p].lc, l, ((l + r) >> 1), x, y, s[pre].lc);
  else
    ins(s[p].rc, ((l + r) >> 1) + 1, r, x, y, s[pre].rc);
}
long long query(int p, int l, int r, long long x) {
  if (l == r) return x >= s[p].sum ? s[p].suma : x / b[l];
  long long now = s[s[p].lc].sum;
  if (x < now)
    return query(s[p].lc, l, ((l + r) >> 1), x);
  else
    return s[s[p].lc].suma + query(s[p].rc, ((l + r) >> 1) + 1, r, x - now);
}
}  // namespace SegT
using namespace SegT;
void dfs(int x, int fat, int depth, long long nowDis) {
  dep[x] = depth, dis[x] = nowDis;
  ins(root[x], 1, m, t[x], a[x], root[fat]);
  if (T - nowDis * 2 > 0)
    res[x] = query(root[x], 1, m, T - nowDis * 2);
  else
    res[x] = 0;
  for (int i = head[x]; i; i = e[i].nxt) {
    int y = e[i].to;
    if (y == fat) continue;
    dfs(y, x, depth + 1, nowDis + e[i].val);
  }
}
void solve(int x, int fat) {
  h[x] = res[x];
  long long mx = -inf;
  int son = 0;
  for (int i = head[x]; i; i = e[i].nxt) {
    int y = e[i].to;
    if (y == fat) continue;
    solve(y, x);
    if (h[y] > mx) mx = h[y], son = y;
  }
  if (son != 0) {
    for (int i = head[x]; i; i = e[i].nxt) {
      int y = e[i].to;
      if (y == fat) continue;
      if (x == 1)
        chkMax(h[x], h[y]);
      else if (y != son)
        chkMax(h[x], h[y]);
    }
  }
}
int main() {
  read(n), read(T);
  m = 0;
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int i = 1; i <= n; i++) {
    read(t[i]);
    b[++m] = t[i];
  }
  sort(b + 1, b + 1 + m);
  m = unique(b + 1, b + 1 + m) - b - 1;
  for (int i = 1; i <= n; i++) t[i] = lower_bound(b + 1, b + 1 + m, t[i]) - b;
  for (int i = 2; i <= n; i++) {
    read(fa[i]);
    long long v;
    read(v);
    add(i, fa[i], v), add(fa[i], i, v);
  }
  dfs(1, 0, 1, 0LL);
  solve(1, 0);
  printf("%I64d\n", h[1]);
  return 0;
}
