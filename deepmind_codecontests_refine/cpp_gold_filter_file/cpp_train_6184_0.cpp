#include <bits/stdc++.h>
using namespace std;
const int M = 100000 + 5;
long long int mod = 1000000000 + 7;
vector<int> adj[M];
int vis[M];
int root = 0;
int childnum[M];
int maxsubtreenum[M];
void getroot(int cur, int par, int tot) {
  childnum[cur] = 1;
  maxsubtreenum[cur] = 0;
  for (int i = 0; i < adj[cur].size(); i++) {
    int nxt = adj[cur][i];
    if (nxt != par && !vis[nxt]) {
      getroot(nxt, cur, tot);
      childnum[cur] += childnum[nxt];
      maxsubtreenum[cur] = max(maxsubtreenum[cur], childnum[nxt]);
    }
  }
  maxsubtreenum[cur] = max(maxsubtreenum[cur], tot - childnum[cur]);
  if (maxsubtreenum[cur] < maxsubtreenum[root]) {
    root = cur;
  }
  return;
}
char ans[M];
void dfs(int cur, int par, int tot, int depth) {
  root = 0;
  maxsubtreenum[0] = M;
  getroot(cur, par, tot);
  ans[root] = 'A' + depth;
  vis[root] = 1;
  int tmproot = root;
  for (int i = 0; i < adj[tmproot].size(); i++) {
    int nxt = adj[tmproot][i];
    if (!vis[nxt]) {
      dfs(nxt, tmproot, childnum[nxt], depth + 1);
    }
  }
}
int main() {
  time_t t_start, t_end;
  t_start = clock();
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vis[0] = 1;
  dfs(1, 0, n, 0);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  t_end = clock();
  return 0;
}
