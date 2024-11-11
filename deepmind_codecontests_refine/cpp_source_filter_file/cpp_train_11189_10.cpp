#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
inline void write(long long x) {
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const int N = 100005;
int To[N << 1], Ne[N << 1], Dis[N << 1], He[N], _;
inline void add(int x, int y, int z) {
  ++_;
  To[_] = y, Ne[_] = He[x], He[x] = _, Dis[_] = z;
  ++_;
  To[_] = x, Ne[_] = He[y], He[y] = _, Dis[_] = z;
}
int A, B;
namespace getRt {
long long mxd, dpt[N], mx[N];
inline void dfs(int x, int f) {
  mx[x] = x;
  for (int p = He[x], y; p; p = Ne[p])
    if ((y = To[p]) ^ f) {
      dpt[y] = dpt[x] + Dis[p];
      dfs(y, x);
      if (dpt[mx[x]] + dpt[mx[y]] - (dpt[x] << 1) >= mxd)
        A = mx[x], B = mx[y], mxd = dpt[mx[x]] + dpt[mx[y]] - (dpt[x] << 1);
      if (dpt[mx[y]] >= dpt[mx[x]]) mx[x] = mx[y];
    }
}
inline void solve() { A = B = 1, mxd = 0, dfs(1, -1); }
}  // namespace getRt
namespace Sort {
long long p[N];
inline bool cmp(int x, int y) { return p[x] > p[y]; }
inline void Sort(int *a, int n) { sort(a + 1, a + n + 1, cmp); }
}  // namespace Sort
int n, q;
struct Tree {
  long long dpt[N], mdpt[N];
  int fa[N], son[N], st[N], ed[N];
  inline void dfs1(int x) {
    mdpt[x] = dpt[x];
    for (int p = He[x], y; p; p = Ne[p])
      if ((y = To[p]) ^ fa[x]) {
        fa[y] = x, dpt[y] = dpt[x] + Dis[p];
        dfs1(y);
        if (mdpt[y] >= mdpt[x]) mdpt[x] = mdpt[y], son[x] = y;
      }
  }
  inline void dfs2(int x) {
    if (son[x]) {
      st[son[x]] = st[x], dfs2(son[x]), ed[x] = ed[son[x]];
      for (int p = He[x], y; p; p = Ne[p])
        if (!st[y = To[p]]) st[y] = y, dfs2(y);
    } else
      ed[x] = x;
  }
  int c[N], lc;
  long long sum[N];
  int a[N];
  inline void Tag(int c, int x) {
    long long t = st[x];
    sum[c] = sum[c - 1] + dpt[x] - dpt[fa[st[x]]];
    while (st[x] == t) a[x] = c, x = fa[x];
  }
  int f[N][20];
  inline void build(int r) {
    int i, j;
    fa[r] = 0, dpt[r] = 0, dfs1(r), st[r] = r, dfs2(r);
    for (lc = 0, i = 1; i <= n; ++i)
      if (ed[i] == i) c[++lc] = i, Sort::p[i] = dpt[i] - dpt[st[i]];
    Sort::Sort(c, lc);
    for (i = 1; i <= lc; ++i) Tag(i, c[i]);
    for (i = 1; i <= n; ++i) f[i][0] = fa[i];
    for (j = 1; j < 20; ++j)
      for (i = 1; i <= n; ++i) f[i][j] = f[f[i][j - 1]][j - 1];
  }
  inline long long ask1(int x, int k) {
    long long ret = sum[2 * k - 2] + mdpt[x];
    for (int i = 19; i >= 0; --i)
      if (a[f[x][i]] >= 2 * k - 1) x = f[x][i];
    x = fa[x];
    return ret - dpt[x];
  }
  inline long long ask2(int x, int k) {
    long long ret = sum[2 * k - 1] + mdpt[x];
    for (int i = 19; i >= 0; --i)
      if (a[f[x][i]] >= 2 * k) x = f[x][i];
    x = fa[x];
    return ret - mdpt[x];
  }
  inline long long Query(int x, int k) {
    int t = 1;
    if (a[x] <= k * 2 - 1) return sum[min(lc, k * 2 - 1)];
    return max(ask1(x, k), ask2(x, k));
  }
} T1, T2;
int main() {
  int i;
  long long x, y, z, ans = 0;
  read(n), read(q);
  for (i = 1; i < n; ++i) read(x), read(y), read(z), add(x, y, z);
  getRt::solve(), T1.build(A), T2.build(B);
  while (q--) {
    read(x), read(y), x = (x + ans - 1) % n + 1, y = (y + ans - 1) % n + 1;
    write(ans = max(T1.Query(x, y), T2.Query(x, y))), putchar('\n');
  }
  return 0;
}
