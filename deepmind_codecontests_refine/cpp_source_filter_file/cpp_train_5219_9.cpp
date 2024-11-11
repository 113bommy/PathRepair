#include <bits/stdc++.h>
using namespace std;
long long int n, u, v, m, t, md;
vector<long long int> g[300005];
long long int vis[300005], pw[300005];
int main() {
  scanf("%I64d", &t);
  md = 998244353;
  pw[0] = 1;
  for (long long int i = 1; i <= 300000; i++) pw[i] = (pw[i - 1] * 2) % md;
  while (t--) {
    scanf("%I64d%I64d", &n, &m);
    for (long long int i = 1; i <= n; i++) {
      vis[i] = -1;
      g[i].clear();
    }
    while (m--) {
      scanf("%I64d%I64d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
    long long int ans = 0;
    bool f = false;
    for (long long int i = 1; i <= n; i++) {
      if (vis[i] != -1) continue;
      queue<long long int> q;
      q.push(i);
      vis[i] = 1;
      long long int on = 1, tw = 0;
      while (!q.empty()) {
        u = q.front();
        q.pop();
        for (long long int i = 0; i < g[u].size(); i++) {
          long long int v = g[u][i];
          if (vis[v] == -1) {
            vis[v] = vis[u] + 1;
            if (vis[v] & 1)
              on++;
            else
              tw++;
            q.push(v);
          } else if ((vis[u] % 2) == (vis[v] % 2))
            f = true;
        }
      }
      ans = (ans + (pw[on] + pw[tw])) % md;
    }
    if (f) ans = 0;
    printf("%I64d\n", ans);
  }
}
