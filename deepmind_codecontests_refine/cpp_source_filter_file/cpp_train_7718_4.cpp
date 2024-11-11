#include <bits/stdc++.h>
using namespace std;
int n, m, d[100127], vis[100127], ins[100127];
stack<int> ans;
vector<int> e[100127], T[100127];
void dfs(int x) {
  vis[x] = ins[x] = 1;
  for (auto y : e[x]) {
    if (!ins[y]) {
      ++d[y];
      T[x].push_back(y);
    }
    if (!vis[y]) dfs(y);
  }
  ins[x] = 0;
}
int main() {
  scanf("%d%d", &n, &m);
  int i, x, y, o;
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    e[x].push_back(y);
  }
  for (i = 1; i <= n; i++)
    if (!vis[i]) dfs(i);
  for (i = 1; i <= n; i++)
    if (!d[i]) ans.push(i);
  while (ans.size() > 1) {
    x = ans.top();
    ans.pop();
    y = ans.top();
    ans.pop();
    printf("? %d %d\n", x, y);
    fflush(stdout);
    scanf("%d", &o);
    if (!o) swap(x, y);
    ans.push(x);
    for (auto v : T[x])
      if (!(--d[v])) ans.push(v);
  }
  printf("! %d", ans.top());
  return 0;
}
