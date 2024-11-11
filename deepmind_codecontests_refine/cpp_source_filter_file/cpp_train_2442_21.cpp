#include <bits/stdc++.h>
using namespace std;
int a[6][1001];
int pos[6][1001];
list<int> adj[1001];
stack<int> stk;
bool vis[1001];
int d[1001];
void dfs(int s) {
  vis[s] = 1;
  for (list<int>::iterator it = adj[s].begin(); it != adj[s].end(); ++it)
    if (!vis[*it]) dfs(*it);
  stk.push(s);
}
int main() {
  int i, j, K, n, k;
  cin >> n >> K;
  for (i = 1; i <= K; ++i)
    for (j = 1; j <= n; ++j) {
      cin >> a[i][j];
      pos[i][a[i][j]] = j;
    }
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j) {
      for (k = 1; k <= K; ++k)
        if (pos[k][i] >= pos[k][j]) break;
      if (k == K + 1) adj[i].push_back(j);
    }
  for (i = 1; i <= n; ++i) {
    if (!vis[i]) dfs(i);
    d[i] = 1;
  }
  int ans = -1;
  while (!stk.empty()) {
    for (list<int>::iterator it = adj[stk.top()].begin();
         it != adj[stk.top()].end(); ++it) {
      d[*it] = max(d[stk.top()] + 1, d[*it]);
      ans = max(ans, d[*it]);
    }
    stk.pop();
  }
  cout << ans;
  return 0;
}
