#include <bits/stdc++.h>
using namespace std;
bool vis[1010], f[1010], b[1010];
int d[1010], a[1010];
void dfs(int x) {
  if (x == 0) return;
  vis[x] = true;
  if (!vis[a[x]]) dfs(a[x]);
  d[x] = d[a[x]] + 1;
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), b[a[i]] = true;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) dfs(i);
  }
  for (int i = 1; i <= n; i++) {
    if (b[i]) continue;
    int temp = i;
    bool flag = false;
    while (temp) {
      if (temp == k) flag = true;
      temp = a[temp];
    }
    if (flag) b[i] = true;
  }
  f[d[k]] = true;
  for (int j = 1; j <= n; j++) {
    if (b[j]) continue;
    for (int i = n; i >= d[k] + 1; i--) {
      f[i] |= f[i - d[j]];
    }
  }
  for (int i = 1; i <= n; i++)
    if (f[i]) printf("%d ", i);
  return 0;
}
