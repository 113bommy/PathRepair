#include <bits/stdc++.h>
using namespace std;
const int N = 30;
string s[N], ans[N], q[N];
map<string, int> mp;
int ban[N][N], res, tot;
int n, m, vis[N];
void dfs(int u) {
  if (u == n + 1) {
    if (tot > res) {
      res = tot;
      for (int i = 1; i <= tot; i++) ans[i] = q[i];
    }
    return;
  }
  dfs(u + 1);
  if (!vis[u]) {
    for (int i = 1; i <= n; i++)
      if (ban[u][i]) vis[i]++;
    q[++tot] = s[u];
    dfs(u + 1);
    --tot;
    for (int i = 1; i <= n; i++)
      if (ban[u][i]) vis[i]--;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    mp[s[i]] = i;
  }
  for (int i = 1; i <= m; i++) {
    string now1, now2;
    cin >> now1 >> now2;
    int u = mp[now1], v = mp[now2];
    ban[u][v] = ban[v][u] = 1;
  }
  dfs(1);
  cout << res << '\n';
  sort(ans + 1, ans + res + 1);
  for (int i = 1; i <= res; i++) cout << ans[i] << '\n';
  return 0;
}
