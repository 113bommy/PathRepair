#include <bits/stdc++.h>
using namespace std;
const int N = int(3e5), mod = int(1e9) + 7;
int n, m;
int d[N], dp[N];
vector<pair<int, int> > g[N];
bool used[N];
priority_queue<pair<int, int> > q;
queue<int> qu;
int a[N], b[N], c[N];
vector<int> ans;
pair<int, int> p[N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, x, y, z; i <= m; i++) {
    scanf("%d%d%d", &x, &y, &z);
    g[x].push_back(make_pair(y, i));
    g[y].push_back(make_pair(x, i));
    a[i] = x;
    b[i] = y;
    c[i] = z;
  }
  for (int i = 1; i <= n; i++) {
    d[i] = mod;
    dp[i] = -mod;
  }
  d[1] = 0;
  qu.push(1);
  while (!qu.empty()) {
    int v = qu.front();
    qu.pop();
    for (int i = 0; i < g[v].size(); i++) {
      int to = g[v][i].first;
      if (d[to] == mod) {
        d[to] = d[v] + 1;
        qu.push(to);
      }
    }
  }
  dp[n] = 0;
  q.push(make_pair(0, n));
  while (!q.empty()) {
    int v = q.top().second;
    q.pop();
    if (used[v]) continue;
    used[v] = 1;
    for (int i = 0; i < g[v].size(); i++) {
      int to = g[v][i].first;
      if (dp[to] < c[g[v][i].second] + dp[v] && d[v] == d[to] + 1) {
        dp[to] = c[g[v][i].second] + dp[v];
        p[to] = make_pair(v, g[v][i].second);
        q.push(make_pair(dp[to], to));
      }
    }
  }
  memset(used, 0, sizeof(used));
  int v = 1;
  while (v != n) {
    if (c[p[v].second] == 0) ans.push_back(p[v].second);
    used[p[v].second] = 1;
    v = p[v].first;
  }
  for (int i = 1; i <= m; i++) {
    if (!used[i] && c[i]) {
      ans.push_back(i);
    }
  }
  printf("%d\n", int(ans.size()));
  for (int i = 0; i < ans.size(); i++) {
    int x = ans[i];
    printf("%d %d %d\n", a[x], b[x], 1 - c[x]);
  }
  return 0;
}
