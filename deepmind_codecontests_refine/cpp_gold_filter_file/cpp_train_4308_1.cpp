#include <bits/stdc++.h>
const int maxn = 100100;
std::vector<int> adj[maxn];
std::vector<int> ans;
std::map<int, bool> mp[maxn];
bool vis[maxn];
int n, u, v;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < 2 * n; i++) {
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
    mp[u][v] = mp[v][u] = true;
  }
  for (int i = 1; i <= n; i++) {
    if (adj[i].size() != 4) {
      puts("-1");
      return 0;
    }
  }
  int head = 1, last = 1, tmp;
  for (int step = 1; step <= n; step++) {
    bool ok = false;
    vis[head] = true;
    ans.push_back(head);
    for (int i = 0; i < 4; i++) {
      tmp = 0;
      int tail = adj[head][i];
      for (int j = 0; j < 4; j++)
        if (mp[head][adj[tail][j]]) tmp++;
      if (tmp > 1 && !vis[tail] && mp[last][tail]) {
        last = head;
        head = tail;
        ok = true;
        break;
      }
    }
    if (!ok && step != n) {
      puts("-1");
      return 0;
    }
  }
  for (int i = 0; i < n; i++) printf("%d ", ans[i]);
  puts("");
  return 0;
}
