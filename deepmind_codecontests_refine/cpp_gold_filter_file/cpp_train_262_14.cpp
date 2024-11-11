#include <bits/stdc++.h>
using namespace std;
vector<int> edge[400010];
int n;
int sum[400010];
int cut[400010];
int prevCut[400010];
int fa[400010];
int first[400010];
int second[400010];
void dfs1(int u, int par) {
  fa[u] = par;
  sum[u] = 1;
  cut[u] = 0;
  for (int i = 0; i < edge[u].size(); i++) {
    int v = edge[u][i];
    if (v == par) continue;
    dfs1(v, u);
    sum[u] += sum[v];
    if (sum[v] <= n / 2)
      cut[u] = max(sum[v], cut[u]);
    else
      cut[u] = max(cut[v], cut[u]);
  }
}
void dfs2(int u) {
  if (prevCut[u] >= 0) return;
  if (fa[u] != -1) dfs2(fa[u]);
  if (u == 1) {
    prevCut[u] = 0;
  } else if (n - sum[u] <= n / 2) {
    prevCut[u] = n - sum[u];
  } else if (sum[u] != first[fa[u]] && cut[u] != first[fa[u]]) {
    prevCut[u] = first[fa[u]];
  } else {
    prevCut[u] = second[fa[u]];
  }
  first[u] = second[u] = prevCut[u];
  for (int i = 0; i < edge[u].size(); i++) {
    int v = edge[u][i];
    if (v == fa[u]) continue;
    int can = sum[v] <= n / 2 ? sum[v] : cut[v];
    if (can >= first[u]) {
      second[u] = first[u];
      first[u] = can;
    } else if (can > second[u]) {
      second[u] = can;
    }
  }
}
int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; i++) edge[i].clear();
    memset(sum, 0, sizeof(sum));
    memset(prevCut, -1, sizeof(cut));
    memset(first, 0, sizeof(first));
    memset(second, 0, sizeof(second));
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      edge[u].push_back(v);
      edge[v].push_back(u);
    }
    dfs1(1, -1);
    for (int i = 1; i <= n; i++) {
      dfs2(i);
    }
    for (int u = 1; u <= n; u++) {
      int ok = 1;
      for (int j = 0; j < edge[u].size(); j++) {
        int v = edge[u][j];
        if (v != fa[u]) {
          if (sum[v] - cut[v] > n / 2) {
            ok = 0;
            break;
          }
        } else {
          if (n - sum[u] - prevCut[u] > n / 2) {
            ok = 0;
            break;
          }
        }
      }
      if (u == n)
        printf("%d\n", ok);
      else
        printf("%d ", ok);
    }
  }
  return 0;
}
