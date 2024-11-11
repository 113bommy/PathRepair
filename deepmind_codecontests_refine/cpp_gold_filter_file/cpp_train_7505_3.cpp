#include <bits/stdc++.h>
using namespace std;
int inline read() {
  int num = 0, neg = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') neg = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    num = (num << 3) + (num << 1) + c - '0';
    c = getchar();
  }
  return num * neg;
}
const int maxn = 200010, mod = 998244353;
int n, m;
vector<int> g[maxn];
int dfn[maxn], sz[maxn], tot, jmp[maxn][20], dep[maxn];
map<int, map<int, int> > M;
void dfs(int x, int fa) {
  dfn[x] = ++tot;
  sz[x] = 1;
  dep[x] = dep[fa] + 1;
  for (int i = 1; i <= 19; i++) jmp[x][i] = jmp[jmp[x][i - 1]][i - 1];
  for (int i = 0; i < g[x].size(); i++) {
    int v = g[x][i];
    if (v == fa) continue;
    jmp[v][0] = x;
    dfs(v, x);
    sz[x] += sz[v];
  }
}
int gets(int x, int y) {
  for (int i = 19; i >= 0; i--)
    if (dep[jmp[x][i]] > dep[y]) x = jmp[x][i];
  return x;
}
int cover[maxn << 2], len[maxn << 2];
void pushup(int x, int l, int r) {
  if (cover[x] > 0)
    len[x] = r - l + 1;
  else if (l == r)
    len[x] = 0;
  else
    len[x] = len[(x << 1)] + len[(x << 1 | 1)];
}
void update(int x, int l, int r, int L, int R, int k) {
  if (L > R) return;
  if (L <= l && r <= R) {
    cover[x] += k;
    pushup(x, l, r);
    return;
  }
  int mid = l + r >> 1;
  if (L <= mid) update(x << 1, l, mid, L, R, k);
  if (R > mid) update(x << 1 | 1, mid + 1, r, L, R, k);
  pushup(x, l, r);
}
int main() {
  n = read();
  m = read();
  for (int i = 1; i < n; i++) {
    int x = read(), y = read();
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  while (m--) {
    int x = read(), y = read();
    if (dfn[x] > dfn[y]) swap(x, y);
    if (dfn[y] <= dfn[x] + sz[x] - 1 && dfn[y] >= dfn[x]) {
      int son = gets(y, x);
      if (M[x][y]) {
        M[x][y] = 0;
        update(1, 1, n, dfn[son], dfn[y] - 1, -1);
        update(1, 1, n, dfn[y] + sz[y], dfn[son] + sz[son] - 1, -1);
      } else {
        M[x][y] = 1;
        update(1, 1, n, dfn[son], dfn[y] - 1, 1);
        update(1, 1, n, dfn[y] + sz[y], dfn[son] + sz[son] - 1, 1);
      }
    } else {
      if (M[x][y]) {
        M[x][y] = 0;
        update(1, 1, n, 1, dfn[x] - 1, -1);
        update(1, 1, n, dfn[x] + sz[x], dfn[y] - 1, -1);
        update(1, 1, n, dfn[y] + sz[y], n, -1);
      } else {
        M[x][y] = 1;
        update(1, 1, n, 1, dfn[x] - 1, 1);
        update(1, 1, n, dfn[x] + sz[x], dfn[y] - 1, 1);
        update(1, 1, n, dfn[y] + sz[y], n, 1);
      }
    }
    printf("%d\n", n - len[1]);
  }
  return 0;
}
