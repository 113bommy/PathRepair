#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
struct node {
  int to;
  long long w;
} t;
vector<node> g[N];
int n, u, v, vis[N];
long long w, ans, all;
void dfs(int x, long long sum) {
  ans = max(ans, sum);
  vis[x] = 1;
  for (int i = 0; i < g[x].size(); i++) {
    int y = g[x][i].to;
    if (vis[y] == 1) continue;
    long long tmp = sum + g[x][i].w;
    dfs(y, tmp);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  all = 0;
  ans = 0;
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i < n; i++) {
    cin >> u >> v >> w;
    t.to = u;
    t.w = w;
    g[v].push_back(t);
    t.to = v;
    g[u].push_back(t);
    all += w;
  }
  dfs(1, 0);
  cout << all * 2 - ans << endl;
  return 0;
}
