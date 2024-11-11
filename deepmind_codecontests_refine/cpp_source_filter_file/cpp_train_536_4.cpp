#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int res = 0, f = 1;
  char c = getchar();
  while (!(c >= '0' && c <= '9') && c != '-') c = getchar();
  if (c == '-') f = -1, c = getchar();
  while ((c >= '0' && c <= '9'))
    res = (res << 3) + (res << 1) + (c ^ 48), c = getchar();
  return res * f;
}
const int maxn = 1e4 + 10;
int n, e[maxn << 1][2], h[maxn];
void add_edge(int u, int v, int i) {
  e[i][0] = v, e[i][1] = h[u];
  h[u] = i;
  return;
}
int siz[maxn], dp[maxn], y = 1e9, cen;
void dfs(int u, int fa) {
  siz[u] = 1;
  for (int i = h[u]; i; i = e[i][1]) {
    int v = e[i][0];
    if (v != fa) {
      dfs(v, u);
      siz[u] += siz[v];
      dp[u] = max(dp[u], siz[v]);
    }
  }
  dp[u] = max(dp[u], n - siz[u]);
  if (dp[u] < y) cen = u, y = dp[u];
  return;
}
pair<int, int> a[maxn];
int cnt;
int num, fa[maxn], ans[maxn];
void work(int u, int sta, int v) {
  siz[u] = 1;
  ans[u] = sta * v;
  sta = 1;
  for (int i = h[u]; i; i = e[i][1]) {
    int v = e[i][0];
    if (v != fa[u]) {
      fa[v] = u;
      work(v, sta, v);
      siz[u] += siz[v];
      sta += siz[v];
    }
  }
}
int main() {
  n = read();
  for (int i = 1, u, v; i < n; i++) {
    u = read(), v = read();
    add_edge(u, v, i * 2);
    add_edge(v, u, i * 2 + 1);
  }
  dfs(1, 0);
  for (int i = h[cen]; i; i = e[i][1]) {
    int v = e[i][0];
    if (siz[v] < siz[cen])
      a[++cnt] = make_pair(siz[v], v);
    else
      a[++cnt] = make_pair(n - siz[cen], v);
  }
  sort(a + 1, a + cnt + 1);
  int mx = -1, bd = 0, tmp = 0, t;
  for (int i = 1; i <= cnt; i++) {
    tmp += a[i].first;
    if (tmp * (n - tmp - 1) > mx) mx = tmp * (n - tmp - 1), t = tmp, bd = i;
  }
  tmp = 1;
  for (int i = 1; i <= bd; i++) {
    fa[a[i].second] = cen;
    work(a[i].second, tmp, 1);
    tmp += a[i].first;
  }
  tmp = 1;
  for (int i = bd + 1; i <= cnt; i++) {
    fa[a[i].second] = cen;
    work(a[i].second, tmp, t + 1);
    tmp += a[i].first;
  }
  for (int i = 1; i <= n; i++)
    if (i != cen) printf("%d %d %d\n", i, fa[i], ans[i]);
  return 0;
}
