#include <bits/stdc++.h>
using namespace std;
vector<int> g[200002];
int n, k, i, j, a[200002];
int f[200002];
int v, u;
int M, answ;
bool mark[200002];
int p[200002], deg[200002], dpd[200002], dpv[200002];
int h[200002], h2[200002];
int an;
void dfs1(int x) {
  int i;
  deg[x] = 1;
  for (i = 0; i < g[x].size(); i++) {
    int v = g[x][i];
    if (v == p[x]) continue;
    p[v] = x;
    dfs1(v);
    deg[x] += deg[v];
  }
}
void dfs(int x) {
  int i;
  dpd[x] = (a[x] >= M);
  h[x] = 0;
  h2[x] = 0;
  for (i = 0; i < g[x].size(); i++) {
    int v = g[x][i];
    if (v == p[x]) continue;
    p[v] = x;
    dfs(v);
    if (dpd[v] == deg[v])
      dpd[x] += dpd[v];
    else {
      if (dpd[v] + h[v] >= h[x]) {
        h2[x] = h[x];
        h[x] = dpd[v] + h[v];
      } else
        h2[x] = max(h2[x], dpd[v] + h[v]);
    }
  }
  if (a[x] < M) {
    dpd[x] = 0;
    h[x] = 0;
    h2[x] = 0;
  }
  an = max(an, dpd[x] + h[x]);
}
void dfs2(int x) {
  int i;
  if (a[x] >= M)
    an = max(an, dpd[x] + dpv[x] + ((deg[1] - deg[x] == dpv[x]) ? h[x] : 0));
  for (i = 0; i < g[x].size(); i++) {
    int v = g[x][i];
    if (v == p[x]) continue;
    dpv[v] += dpd[x];
    int f = h[x];
    if (deg[v] == dpd[v])
      dpv[v] -= dpd[v];
    else if (dpd[v] + h[v] == h[x])
      f = h2[x];
    if (deg[1] - deg[x] == dpv[x])
      dpv[v] += dpv[x];
    else
      dpv[v] += max(f, dpv[x]);
    if (a[x] < M || a[v] < M) dpv[v] = 0;
    dfs2(v);
  }
}
bool lava() {
  int i, j;
  an = 0;
  memset(mark, 0, (n + 1) * (sizeof(bool)));
  memset(dpv, 0, (n + 1) * (sizeof(int)));
  memset(dpd, 0, (n + 1) * (sizeof(int)));
  memset(h, 0, (n + 1) * (sizeof(int)));
  memset(h2, 0, (n + 1) * (sizeof(int)));
  dfs(1);
  dpv[1] = 0;
  dfs2(1);
  return (an >= k);
}
int main() {
  scanf("%d%d", &n, &k);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    f[i] = a[i];
  }
  sort(f + 1, f + n + 1);
  for (i = 1; i < n; i++) {
    scanf("%d%d", &v, &u);
    g[v].push_back(u);
    g[u].push_back(v);
  }
  p[1] = 1;
  dfs1(1);
  int S = 1;
  int E = n - k + 1;
  while (S <= E) {
    int m = (S + E) / 2;
    M = f[m];
    if (lava()) {
      S = m + 1;
      answ = M;
    } else
      E = m - 1;
  }
  cout << answ << endl;
  return 0;
}
