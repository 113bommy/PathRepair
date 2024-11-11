#include <bits/stdc++.h>
using namespace std;
const int N = 50505, BLCK = 1 << 8;
int n, q, a[N], pr[N], gpr[N], l[N];
vector<int> g[N];
int sz;
int nxt[N][2];
int ans[N][BLCK];
void insert(int v) {
  int cur = 0;
  for (int e = 15; e >= 0; e--) {
    int& u = nxt[cur][(v >> e) & 1];
    if (u == -1) {
      u = sz++;
      nxt[u][0] = -1;
      nxt[u][1] = -1;
    }
    cur = u;
  }
}
int search(int x) {
  int rt = 0, tot = 0;
  for (int e = 15; e >= 0; e--) {
    int tk = (x >> e) & 1;
    if (nxt[rt][tk ^ 1] != -1) {
      tot += (1 << e);
      rt = nxt[rt][tk ^ 1];
    } else
      rt = nxt[rt][tk];
  }
  return tot;
}
void dfs(int i, int p) {
  pr[i] = p;
  l[i] = l[p] + 1;
  if (l[i] >= BLCK) {
    sz = 1;
    nxt[0][0] = nxt[0][1] = -1;
    int cur = i;
    for (int j = 0; j <= BLCK - 1; ++j) insert(a[cur] ^ j), cur = pr[cur];
    for (int j = 0; j <= BLCK - 1; ++j) ans[i][j] = search(j << 8);
    gpr[i] = cur;
  }
  for (int j : g[i])
    if (j != p) dfs(j, i);
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 2; i <= n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  while (q--) {
    int u, v;
    scanf("%d%d", &u, &v);
    int res = 0, d = 0;
    while (l[v] - BLCK + 1 >= l[u]) {
      res = max(res, ans[v][d >> 8]);
      v = gpr[v];
      d += BLCK;
    }
    while (v != pr[u]) {
      res = max(res, d ^ a[v]);
      v = pr[v];
      ++d;
    }
    printf("%d\n", res);
  }
}
