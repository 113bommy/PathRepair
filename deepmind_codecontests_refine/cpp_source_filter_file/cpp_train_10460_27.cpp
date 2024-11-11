#include <bits/stdc++.h>
using namespace std;
vector<int> g[100005];
int n, logn;
int P[100005][21];
int L[100005];
int T[100005];
int vis[100005] = {0};
int size1[100005];
int caLog(int a) {
  int ret = 0;
  while (1) {
    a = a / 2;
    if (a == 0) {
      break;
    }
    ret++;
  }
  return ret;
}
int dfs(int node, int par, int lev) {
  T[node] = par;
  L[node] = lev;
  int ret = 1;
  for (int i = 0; i < g[node].size(); i++) {
    if (vis[g[node][i]] == 0) {
      vis[g[node][i]] = 1;
      ret = ret + dfs(g[node][i], node, lev + 1);
    }
  }
  size1[node] = ret;
  return ret;
}
void presolve() {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= logn; j++) {
      P[i][j] = -1;
    }
  }
  for (int i = 1; i <= n; i++) {
    P[i][0] = T[i];
  }
  for (int j = 1; j <= logn; j++) {
    for (int i = 1; i <= n; i++) {
      if (P[i][j - 1] != -1) {
        P[i][j] = P[P[i][j - 1]][j - 1];
      }
    }
  }
}
int lca(int x, int y) {
  if (L[x] > L[y]) {
    x = x + y;
    y = x - y;
    x = x - y;
  }
  int lg = caLog(L[x]);
  for (int j = lg; j >= 0; j--) {
    if (P[x][j] != -1 && L[P[x][j]] >= L[y]) {
      x = P[x][j];
    }
  }
  if (x == y) {
    return x;
  }
  lg = caLog(L[x]);
  for (int j = lg; j >= 0; j--) {
    if (P[x][j] != -1 && P[x][j] != P[y][j]) {
      x = P[x][j];
      y = P[y][j];
    }
  }
  return T[x];
}
int query(int x, int y) {
  int lc = lca(x, y);
  if (x == y) {
    return n;
  }
  if ((L[x] + L[y] - 2 * L[lc]) % 2 != 0) {
    return 0;
  }
  if ((L[x] - L[lc]) == (L[y] - L[lc])) {
    int lg = caLog(L[x]);
    for (int j = lg; j >= 0; j--) {
      if (P[x][j] != -1 && P[x][j] != P[y][j]) {
        x = P[x][j];
        y = P[y][j];
      }
    }
    return n - size1[x] - size1[y];
  }
  if (L[x] < L[y]) {
    x = x + y;
    y = x - y;
    x = x - y;
  }
  int x1 = x;
  int dis = L[x] + L[y] - 2 * L[lc];
  dis = dis / 2;
  dis = L[x] - dis;
  int lg = caLog(L[x]);
  for (int j = lg; j >= 0; j--) {
    if (P[x][j] != -1 && L[P[x][j]] >= dis) {
      x = P[x][j];
    }
  }
  int ret = size1[x];
  x = x1;
  dis++;
  for (int j = lg; j >= 0; j--) {
    if (P[x][j] != -1 && L[P[x][j]] >= dis) {
      x = P[x][j];
    }
  }
  ret = ret - size1[x];
  return ret;
}
int main() {
  int m, x, y, ans;
  scanf("%d", &n);
  for (int i = 0; i < (n - 1); i++) {
    scanf("%d", &x);
    scanf("%d", &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  logn = caLog(n);
  vis[1] = 1;
  dfs(1, 0, 0);
  presolve();
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &x);
    scanf("%d", &y);
    ans = query(x, y);
    printf("%d\n", ans);
  }
  return 0;
}
