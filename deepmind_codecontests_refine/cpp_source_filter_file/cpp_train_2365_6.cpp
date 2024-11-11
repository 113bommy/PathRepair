#include <bits/stdc++.h>
using namespace std;
const int maxn = 1 << 23;
bool a[maxn];
bool vis[maxn];
int n, m, x;
void dfs(int x) {
  if (vis[x]) return;
  vis[x] = true;
  for (int i = 0; i <= n; i++)
    if (x & (1 << i)) dfs(x ^ (1 << i));
  if (a[x]) dfs((1 << n) - 1 - x);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) scanf("%d", &x), a[x] = true;
  int ans = 0;
  for (int i = 1; i <= (1 << n); i++)
    if (!vis[i] && a[i]) dfs(i), ans++;
  printf("%d\n", ans);
  return 0;
}
