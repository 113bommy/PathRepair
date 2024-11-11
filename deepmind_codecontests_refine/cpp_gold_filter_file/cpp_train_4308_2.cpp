#include <bits/stdc++.h>
using namespace std;
vector<int> g[100010];
int vis[100010];
int a[200010], b[200010], s[4];
int res[100010];
int n;
int f(int s[4]) {
  memset(vis, 0, sizeof(vis));
  res[0] = s[0];
  res[1] = s[1];
  res[2] = 1;
  res[3] = s[2];
  res[4] = s[3];
  for (int i = 2; i <= 4; i++) vis[res[i]] = 1;
  int l = 4;
  for (int i = 3; i <= n - 1; i++) {
    int v = res[i], u = 1;
    int tt = 0;
    for (int j = 0; j < 4; j++) {
      int flag = 0;
      for (int k = i - 2; k <= i + 1; k++)
        if (g[v][j] == res[k]) flag = 1;
      if (!flag) tt++, u = g[v][j];
      if (tt > 1) return 0;
    }
    if (tt != 1) return 0;
    if (!vis[u])
      res[++l] = u;
    else
      return 0;
  }
  if (res[l] == res[1] && res[l - 1] == res[0]) {
    return 1;
  }
  return 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < 2 * n; i++) scanf("%d%d", &a[i], &b[i]);
  for (int i = 0; i <= n; i++) g[i].clear();
  for (int i = 0; i < 2 * n; i++) {
    int flag = 0;
    for (int j = 0; j < g[a[i]].size(); j++)
      if (g[a[i]][j] == b[i]) flag = 1;
    if (!flag) g[a[i]].push_back(b[i]);
    if (g[a[i]].size() > 4) {
      printf("-1\n");
      return 0;
    }
    flag = 0;
    for (int j = 0; j < g[b[i]].size(); j++)
      if (g[b[i]][j] == a[i]) flag = 1;
    if (!flag) g[b[i]].push_back(a[i]);
    if (g[b[i]].size() > 4) {
      printf("-1\n");
      return 0;
    }
  }
  for (int i = 1; i <= n; i++)
    if (g[i].size() != 4) {
      printf("-1\n");
      return 0;
    }
  for (int i = 0; i < 4; i++) s[i] = g[1][i];
  sort(s, s + 4);
  do {
    if (f(s)) {
      for (int i = 0; i < n; i++) printf("%d ", res[i]);
      printf("\n");
      return 0;
    }
  } while (next_permutation(s, s + 4));
  printf("-1\n");
  return 0;
}
