#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
const int mod = 1e9 + 7;
const long long inf = 2e18;
int num[maxn], need[maxn], vis[maxn];
pair<int, int> a[maxn];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", num + i);
  }
  vector<vector<int> > g(n + 5);
  int x, y;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    a[i] = {x, y};
    g[x].push_back(i);
    g[y].push_back(i);
    need[x]++;
    need[y]++;
  }
  vector<int> ans;
  queue<int> q;
  for (int i = 1; i <= n; i++)
    if (num[i] >= need[i]) q.push(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int it : g[u]) {
      if (vis[it]) continue;
      vis[it] = 1;
      ans.push_back(it);
      int v = a[it].first;
      if (v == u) v = a[it].second;
      if (--need[v] == num[v]) q.push(v);
    }
  }
  if ((int)ans.size() != n) {
    printf("DEAD\n");
    return 0;
  }
  printf("ALIVE\n");
  reverse(ans.begin(), ans.end());
  for (int it : ans) {
    printf("%d ", it);
  }
  printf("\n");
}
