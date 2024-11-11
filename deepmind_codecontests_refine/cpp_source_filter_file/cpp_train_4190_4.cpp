#include <bits/stdc++.h>
using namespace std;
vector<int> a[200005];
int deep[200005];
int f[200005];
int b[200005][20];
int kk[200005];
int flag, k;
void dfs(int u, int fu) {
  f[u] = fu;
  b[u][0] = fu;
  for (int i = 1; i <= 20; i++) b[u][i] = b[b[u][i - 1]][i - 1];
  deep[u] = deep[fu] + 1;
  for (int i = 0; i < (int)a[u].size(); i++)
    if (a[u][i] != fu) dfs(a[u][i], u);
}
int dfs1(int v, int u) {
  int c = deep[v] - 1;
  for (int i = 20; i >= 0; i--) {
    if (deep[b[u][i]] >= c) u = b[u][i];
  }
  if (f[v] == u)
    return 1;
  else
    return 0;
}
int cmp(int x, int y) { return deep[x] > deep[y]; }
int main() {
  int n, m, u, v;
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &u, &v);
    a[u].push_back(v);
    a[v].push_back(u);
  }
  dfs(1, 0);
  while (m--) {
    flag = 1;
    scanf("%d", &k);
    for (int i = 1; i <= k; i++) scanf("%d", &kk[i]);
    sort(kk + 1, kk + 1 + k, cmp);
    for (int i = 2; i <= k; i++) {
      if (!dfs1(kk[i], kk[1])) {
        flag = 0;
        break;
      }
    }
    if (flag)
      printf("YES\n");
    else
      printf("NO\n");
  }
}
