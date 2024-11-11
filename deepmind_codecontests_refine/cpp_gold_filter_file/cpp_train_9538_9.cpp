#include <bits/stdc++.h>
char ch;
bool fs;
void re(int& x) {
  while (ch = getchar(), ch < 33)
    ;
  if (ch == '-')
    fs = 1, x = 0;
  else
    fs = 0, x = ch - 48;
  while (ch = getchar(), ch > 33) x = x * 10 + ch - 48;
  if (fs) x = -x;
}
using namespace std;
long long ans[500001];
int m, b[500001];
int n, rt, dfn[500001], dep[500001], p[500001][19], a[500001];
int cnt, head[500001], nxt[500001], to[500001];
bool cmp(int a, int b) {
  return dep[a] < dep[b] || (dep[a] == dep[b] && dfn[a] < dfn[b]);
}
void dfs(int u) {
  dfn[u] = ++cnt;
  for (int i = 1; 1 << i <= dep[u]; ++i) p[u][i] = p[p[u][i - 1]][i - 1];
  for (int i = head[u], v; i; i = nxt[i]) {
    dep[v = to[i]] = dep[u] + 1;
    dfs(v);
  }
}
int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int i = 18; i >= 0; --i)
    if (dep[u] - (1 << i) >= dep[v]) u = p[u][i];
  if (u == v) return u;
  for (int i = 18; i >= 0; --i)
    if (p[u][i] != p[v][i]) u = p[u][i], v = p[v][i];
  return p[u][0];
}
void solve() {
  long long now = 0;
  int top = 0;
  static int sum[500001], val[500001];
  for (int i = 2; i <= m; ++i) {
    int x = 1, y = dep[lca(b[i], b[i - 1])];
    while (top && val[top] >= y) {
      now -= 1ll * sum[top] * val[top];
      x += sum[top];
      --top;
    }
    ++top;
    sum[top] = x;
    val[top] = y;
    now += 1ll * x * y;
    ans[b[i]] += now;
  }
}
int main() {
  re(n);
  for (int i = 1; i <= n; ++i) {
    re(p[i][0]);
    if (!p[i][0])
      rt = i;
    else
      nxt[++cnt] = head[p[i][0]], head[p[i][0]] = cnt, to[cnt] = i;
  }
  cnt = 0;
  dep[rt] = 1;
  dfs(rt);
  for (int i = 1; i <= n; ++i) a[i] = i;
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; ++i) {
    b[++m] = a[i];
    if (dep[a[i]] != dep[a[i + 1]]) {
      solve();
      reverse(b + 1, b + m + 1);
      solve();
      for (int j = 1; j <= m; ++j) ans[b[j]] += ans[p[b[j]][0]] + dep[b[j]] - 1;
      m = 0;
    }
  }
  for (int i = 1; i <= n; ++i) printf("%lld ", ans[i]);
}
