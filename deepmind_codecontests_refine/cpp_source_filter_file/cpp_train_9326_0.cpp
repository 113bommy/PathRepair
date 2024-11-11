#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n, son[N][2], val[N], rt, ans, du[N];
map<int, int> mp;
void dfs(int now, int mn, int mx) {
  if (now == -1) return;
  if (val[now] > mn && val[now] < mx) mp[val[now]] = true;
  dfs(son[now][0], mn, min(val[now], mx));
  dfs(son[now][1], max(val[now], mn), mx);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &val[i], &son[i][0], &son[i][1]);
    du[son[i][0]]++;
    du[son[i][1]]++;
  }
  for (int i = 1; i <= n; i++)
    if (du[i] == 0) rt = i;
  dfs(rt, 0, 1e9 + 10);
  for (int i = 1; i <= n; i++)
    if (!mp[val[i]]) ans++;
  printf("%d", ans);
  return 0;
}
