#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int du[MAXN], w[MAXN];
bool vis[MAXN];
vector<pair<int, int> > E[MAXN];
vector<int> ans;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    E[u].push_back(make_pair(v, i));
    E[v].push_back(make_pair(u, i));
    du[u]++;
    du[v]++;
  }
  queue<int> Q;
  for (int i = 1; i <= n; i++)
    if (du[i] <= w[i]) Q.push(i);
  while (!Q.empty()) {
    int now = Q.front();
    Q.pop();
    for (auto it : E[now]) {
      int v = it.first, id = it.second;
      if (vis[id]) continue;
      vis[id] = true;
      ans.push_back(id);
      du[v]--;
      if (du[v] == w[v]) Q.push(v);
    }
  }
  if (ans.size() != m) return 0 * puts("DEAD");
  reverse(ans.begin(), ans.end());
  puts("ALIVE");
  for (auto v : ans) printf("%d ", v);
  puts("");
  return 0;
}
