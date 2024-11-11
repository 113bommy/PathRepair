#include <bits/stdc++.h>
using std::vector;
vector<int> g[200001];
int n, K, root, sz;
int s[200001], v[200001], mx[200001], ans[200001];
inline int max(int a, int b) { return a > b ? a : b; }
void getroot(int x, int f) {
  s[x] = v[x];
  for (int i = 0; i < g[x].size(); i++) {
    int t = g[x][i];
    if (t == f) continue;
    getroot(t, x);
    s[x] += s[t];
    mx[x] = max(mx[x], s[t]);
  }
  mx[x] = max(mx[x], n - s[x]);
  if (mx[x] < mx[root]) root = x;
}
void dfs(int x, int f) {
  if (v[x] > 0 && f != 0) ans[++sz] = x;
  for (int i = 0; i < g[x].size(); i++) {
    int t = g[x][i];
    if (t == f) continue;
    dfs(t, x);
  }
}
int main() {
  scanf("%d%d", &n, &K);
  for (int i = 1, x, y; i < n; i++) {
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 1, x; i <= 2 * K; i++) {
    scanf("%d", &x);
    v[x]++;
  }
  mx[0] = 0x3f3f3f3f;
  root = 0;
  getroot(1, 0);
  sz = 0;
  dfs(root, 0);
  if (v[root] == 1) ans[++sz] = root;
  printf("1\n%d\n", root);
  for (int i = 1; i <= K; i++) printf("%d %d %d\n", ans[i], ans[K + i], root);
  return 0;
}
