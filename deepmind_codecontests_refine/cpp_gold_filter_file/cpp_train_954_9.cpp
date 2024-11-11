#include <bits/stdc++.h>
using namespace std;
namespace io {
const int l = 1 << 20;
char buf[l], *s, *t;
inline char gc() {
  if (s == t) {
    t = (s = buf) + fread(buf, 1, l, stdin);
    return s == t ? EOF : *s++;
  }
  return *s++;
}
char c;
template <class IT>
inline void gi(IT &x) {
  x = 0;
  c = gc();
  while (c < '0' || c > '9') c = gc();
  while ('0' <= c && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = gc();
  }
}
};  // namespace io
using io::gi;
template <class IT>
inline void cmin(IT &a, IT b = 0) {
  if (a > b) a = b;
}
template <class IT>
inline void cmax(IT &a, IT b = 0) {
  if (a < b) a = b;
}
template <class IT>
inline IT _min(IT a, IT b = 0) {
  return a > b ? b : a;
}
template <class IT>
inline IT _max(IT a, IT b = 0) {
  return a < b ? b : a;
}
const long long p = 1000000007ll;
const int N = 200005;
int dp[N][5];
vector<int> e[N];
inline void upd(int v, int w, int d) {
  if (dp[v][0] <= w) {
    dp[v][3] = d;
    dp[v][2] = dp[v][1];
    dp[v][1] = dp[v][0];
    dp[v][0] = w;
  } else if (dp[v][1] <= w) {
    dp[v][2] = dp[v][1];
    dp[v][1] = w;
  } else
    cmax(dp[v][2], w);
}
void dfs1(int v, int fa) {
  int i = 0, s = e[v].size(), u;
  for (; i < s; ++i)
    if ((u = e[v][i]) != fa) {
      dfs1(u, v);
      upd(v, dp[u][0] + 1, u);
    }
}
void dfs2(int v, int fa) {
  upd(v, dp[v][4], 0);
  int w = dp[v][3], w0 = dp[v][0] + 1, w1 = dp[v][1] + 1, i = 0,
      s = e[v].size(), u;
  for (; i < s; ++i)
    if ((u = e[v][i]) != fa) {
      if (u == w)
        dp[u][4] = w1;
      else
        dp[u][4] = w0;
      dfs2(u, v);
    }
}
int f[N], d[N], mx, id;
void dfs3(int v, int fa) {
  f[v] = fa;
  int p = d[v] + 1, i = 0, s = e[v].size(), u;
  for (; i < s; ++i)
    if ((u = e[v][i]) != fa) {
      if ((d[u] = p) > mx) {
        mx = p;
        id = u;
      }
      dfs3(u, v);
    }
}
int ans[N], k0;
void dfsv(int v, int fa) {
  int p = ans[v] + 1, i = 0, s = e[v].size(), u;
  if (p > k0) p = 1;
  for (; i < s; ++i)
    if ((u = e[v][i]) != fa) {
      ans[u] = p;
      dfsv(u, v);
    }
}
void dfsu(int v, int fa) {
  int p = ans[v] - 1, i = 0, s = e[v].size(), u;
  if (!p) p = k0;
  for (; i < s; ++i)
    if ((u = e[v][i]) != fa) {
      ans[u] = p;
      dfsu(u, v);
    }
}
int main() {
  int n, k, i = 1, v, u, w;
  scanf("%d%d", &n, &k);
  k0 = k--;
  for (; i < n; ++i) {
    scanf("%d%d", &v, &u);
    e[v].push_back(u);
    e[u].push_back(v);
  }
  dfs1(1, 0);
  dfs2(1, 0);
  if (k >= 2)
    for (i = 1; i <= n; ++i)
      if (dp[i][2] + dp[i][1] >= k && dp[i][2]) {
        putchar('N');
        putchar('o');
        return 0;
      }
  v = u = 0;
  for (i = 1; i <= n; ++i)
    if (dp[i][0] > u) {
      u = dp[i][0];
      v = i;
    }
  dfs3(v, 0);
  u = id;
  w = mx >> 1;
  while (w--) u = f[u];
  v = f[u];
  ans[v] = 1;
  ans[u] = k0;
  dfsv(v, u);
  dfsu(u, v);
  putchar('Y');
  putchar('e');
  putchar('s');
  putchar('\n');
  for (i = 1; i <= n; ++i) printf("%d ", ans[i]);
  return 0;
}
