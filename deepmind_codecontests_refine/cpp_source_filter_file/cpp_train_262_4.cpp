#include <bits/stdc++.h>
using namespace std;
const int MAXN = 400010;
vector<int> t[MAXN];
int par[MAXN], sz[MAXN], up[MAXN], dw[MAXN], n;
void dfs_sz(int u, int parent) {
  par[u] = parent;
  sz[u] = 1;
  int size = t[u].size();
  for (int i = 0; i < size; i++) {
    int v = t[u][i];
    if (v == parent) continue;
    dfs_sz(v, u);
    sz[u] += sz[v];
  }
}
void dfs_down(int u, int parent) {
  dw[u] = sz[u] <= n / 2 ? sz[u] : 0;
  int size = t[u].size();
  for (int i = 0; i < size; i++) {
    int v = t[u][i];
    if (v == parent) continue;
    dfs_down(v, u);
    dw[u] = max(dw[u], dw[v]);
  }
}
void dfs_up(int u, int parent, int val) {
  up[u] = max((n - sz[u] <= n / 2 ? n - sz[u] : 0), val);
  int size = t[u].size();
  int mx0 = 0, mx1 = 0;
  for (int i = 0; i < size; i++) {
    int v = t[u][i];
    if (v == parent) continue;
    if (dw[v] >= mx0) {
      mx1 = mx0;
      mx0 = dw[v];
    } else if (dw[v] >= mx1) {
      mx1 = dw[v];
    }
  }
  for (int i = 0; i < size; i++) {
    int v = t[u][i];
    if (v == parent) continue;
    dfs_up(v, u, max(up[u], (mx0 == dw[v] ? mx1 : mx0)));
  }
}
int main() {
  int u, v;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &u, &v);
    t[u].push_back(v);
    t[v].push_back(u);
  }
  dfs_sz(1, -1);
  dfs_down(1, -1);
  dfs_up(1, -1, 0);
  for (int i = 1; i <= n; i++) {
    int ans = 1;
    int size = t[i].size();
    for (int k = 0; k < size; k++) {
      int u = t[i][k];
      if (u == par[i]) {
        if (n - sz[i] - up[u] > n / 2) ans = 0;
      } else {
        if (sz[u] - dw[u] > n / 2) ans = 0;
      }
    }
    printf("%d", ans);
    if (i == n)
      printf("\n");
    else
      printf(" ");
  }
  return 0;
}
