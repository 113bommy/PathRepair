#include <bits/stdc++.h>
std::vector<int> to[100005], topo, ans;
int vis[100005], tempvis[100005], mark = 0, etopo[100005];
struct x {
  int a, b, c, index;
} arr[100005];
bool cmp(x a, x b) { return a.c < b.c; }
void visit(int x) {
  if (mark == 1) return;
  if (vis[x] == 1) return;
  if (tempvis[x] == 1) {
    mark = 1;
    return;
  }
  tempvis[x] = 1;
  for (int i = 0; i < to[x].size(); i++) visit(to[x][i]);
  tempvis[x] = 0;
  vis[x] = 1;
  topo.push_back(x);
}
int main() {
  int n, m, i, i2;
  scanf("%d %d", &n, &m);
  for (i = 1; i <= m; i++) {
    scanf("%d %d %d", &arr[i].a, &arr[i].b, &arr[i].c);
    arr[i].index = i;
  }
  std::sort(arr + 1, arr + 1 + m, cmp);
  int l = -1, r = m, mid;
  for (mid = (l + r) / 2; l + 1 != r; mid = (l + r) / 2) {
    for (i = 1; i <= n; i++) {
      to[i].clear();
      vis[i] = 0;
      tempvis[i] = 0;
    }
    topo.clear();
    mark = 0;
    for (i = mid + 1; i <= m; i++) to[arr[i].a].push_back(arr[i].b);
    for (i = 1; i <= n; i++)
      if (vis[i] == 0) visit(i);
    if (mark == 1)
      l = mid;
    else
      r = mid;
  }
  for (i = 1; i <= n; i++) {
    to[i].clear();
    vis[i] = 0;
    tempvis[i] = 0;
  }
  topo.clear();
  mark = 0;
  for (i = r + 1; i <= m; i++) to[arr[i].a].push_back(arr[i].b);
  for (i = 1; i <= n; i++)
    if (vis[i] == 0) visit(i);
  for (i = 0; i < topo.size(); i++) {
    etopo[topo[i]] = topo.size() - i;
  }
  for (i = 1; i <= r; i++) {
    if (etopo[arr[i].a] > etopo[arr[i].b]) ans.push_back(arr[i].index);
  }
  printf("%d %d\n", arr[r].c, ans.size());
  for (i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
  return 0;
}
