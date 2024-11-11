#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z, k, S, sl, fh, s[1000010], b[1000010], ru[1000010],
    id[1000010];
int tim, top, stk[1000010], vis[1000010], dfn[1000010], low[1000010];
int t1, h1[1000010], to1[1000010], v1[1000010], n1[1000010];
int t2, h2[1000010], to2[1000010], v2[1000010], n2[1000010];
long long ans, sv[1000010], dp[1000010], sum[1000010];
queue<int> q;
int rd() {
  sl = 0;
  fh = 1;
  char ch = getchar();
  while (ch < '0' || '9' < ch) {
    if (ch == '-') fh = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') sl = sl * 10 + ch - '0', ch = getchar();
  return sl * fh;
}
void add1(int u, int v, int w) {
  t1++;
  to1[t1] = v;
  v1[t1] = w;
  n1[t1] = h1[u];
  h1[u] = t1;
}
void add2(int u, int v, int w) {
  t2++;
  to2[t2] = v;
  v2[t2] = w;
  n2[t2] = h2[u];
  h2[u] = t2;
}
void init() {
  int mxv = 0;
  for (int i = 1; i <= m; ++i) {
    x = rd();
    y = rd();
    z = rd();
    add1(x, y, z);
    mxv = max(mxv, z);
  }
  for (int i = 1;; ++i) {
    s[i] = s[i - 1] + i;
    sum[i] = sum[i - 1] + s[i];
    s[0] = i;
    if (s[i] + i + 1 > mxv) break;
  }
}
void dfs(int u) {
  dfn[u] = low[u] = ++tim;
  stk[++top] = u;
  vis[u] = 1;
  int v;
  for (int i = h1[u]; i; i = n1[i])
    if (!dfn[v = to1[i]]) {
      dfs(v);
      low[u] = min(low[u], low[v]);
    } else if (vis[v])
      low[u] = min(low[u], dfn[v]);
  if (dfn[u] == low[u]) {
    k++;
    do {
      v = stk[top--];
      id[v] = k;
      vis[v] = 0;
    } while (u != v);
  }
}
void r(int u) {
  b[u] = 1;
  int v;
  for (int i = h1[u]; i; i = n1[i])
    if (!b[v = to1[i]]) r(v);
}
long long getval(int ss) {
  int pos = upper_bound(s + 1, s + s[0] + 1, ss) - s;
  return 1ll * ss * pos - 1ll * sum[pos - 1];
}
int main() {
  n = rd();
  m = rd();
  init();
  for (int i = 1; i <= n; ++i)
    if (!dfn[i]) dfs(i);
  S = rd();
  r(S);
  int v;
  for (int u = 1; u <= n; ++u) {
    if (!b[u]) continue;
    for (int i = h1[u]; i; i = n1[i])
      if (id[u] != id[v = to1[i]])
        add2(id[u], id[v], v1[i]), ru[id[v]]++;
      else
        sv[id[u]] += getval(v1[i]);
  }
  q.push(id[S]), dp[id[S]] = sv[id[S]];
  int u;
  while (!q.empty()) {
    u = q.front();
    q.pop();
    for (int i = h2[u]; i; i = n2[i]) {
      v = to2[i];
      ru[v]--;
      dp[v] = max(dp[v], dp[u] + sv[v] + v2[i]);
      if (!ru[v]) q.push(v);
    }
  }
  for (int i = 1; i <= k; ++i) ans = max(ans, dp[i]);
  printf("%I64d\n", ans);
  return 0;
}
