#include <bits/stdc++.h>
using namespace std;
vector<int> g[200004];
int a[200004];
int c[200004];
int h, res, x;
int dfs(int i, int p) {
  c[i] = 1;
  int cnt = 1, mx1 = 0, mx2 = 0;
  for (int j = 0; j < g[i].size(); j++) {
    int k = g[i][j];
    if (k == p) continue;
    int cur = dfs(k, i);
    if (cur != c[k]) {
      if (cur > mx1) {
        mx2 = mx1;
        mx1 = cur;
      } else if (cur > mx2) {
        mx2 = cur;
      }
    } else
      cnt += cur;
    c[i] += c[k];
  }
  if (a[i] < h) return 0;
  res = max(res, cnt + mx1 + mx2);
  return (cnt + mx1);
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int i;
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  int u, v;
  for (i = 1; i < n; i++) {
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  x = 1;
  for (i = 1; i <= n; i++) {
    if (a[i] < a[x]) x = i;
  }
  int l = a[x];
  int r = 1000001;
  int ans;
  while (l <= r) {
    h = (l + r) / 2;
    res = 0;
    dfs(1, 0);
    if (res >= m) {
      ans = h;
      l = h + 1;
    } else
      r = h - 1;
  }
  printf("%d\n", ans);
  return 0;
}
