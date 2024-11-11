#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 10;
int n, m, a[N], vis[N];
vector<int> e[N];
void dfs(int x) {
  if (vis[x]) return;
  vis[x] = 1;
  for (int i = 0; i < e[x].size(); i++) dfs(e[x][i]);
  for (int i = 0; i < n; i++)
    if (x & (1 << i)) dfs(x + (1 << i));
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++)
    scanf("%d", &a[i]), e[a[i]].push_back(a[i] ^ ((1 << n) - 1));
  int ans = 0;
  for (int i = 1; i <= m; i++)
    if (!vis[a[i]]) dfs(a[i]), ans++;
  printf("%d", ans);
  return 0;
}
