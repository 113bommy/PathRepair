#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long a = 0, b = getchar(), c = 1;
  while (!isdigit(b)) c = b == '-' ? -1 : 1, b = getchar();
  while (isdigit(b)) a = a * 10 + b - '0', b = getchar();
  return a * c;
}
long long n, x, y, ans, d[3][200005];
vector<int> g, e[200005];
queue<int> q;
void bfs(long long *x, int b) {
  for (int i = 1; i <= n; i++) x[i] = -1;
  x[b] = 0, q.push(b);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < e[u].size(); i++)
      if (x[e[u][i]] == -1) {
        x[e[u][i]] = x[u] + 1;
        q.push(e[u][i]);
      }
  }
}
int dfs(int u, int f, int t) {
  int x = 0;
  for (int i = 0; i < e[u].size(); i++)
    if (e[u][i] != f) x |= dfs(e[u][i], u, t);
  if (u == y) x = 1;
  if (t == 0 and x == 0) {
    g.push_back(u);
    g.push_back(d[1][u] > d[2][u] ? x : y);
    g.push_back(u);
    ans += max(d[1][u], d[2][u]);
  }
  if (t == 1 and x == 1 and f) {
    g.push_back(u);
    g.push_back(x);
    g.push_back(u);
    ans += d[1][u];
  }
  return x;
}
int main() {
  n = read();
  for (int i = 1; i < n; i++) {
    int u = read(), v = read();
    e[u].push_back(v);
    e[v].push_back(u);
  }
  bfs(d[0], 1);
  for (int i = 1; i <= n; i++)
    if (d[0][i] > d[0][x]) x = i;
  bfs(d[1], x);
  for (int i = 1; i <= n; i++)
    if (d[1][i] > d[1][y]) y = i;
  bfs(d[2], y);
  dfs(x, 0, 0), dfs(x, 0, 1);
  printf("%lld\n", ans);
  for (int i = 0; i < g.size(); i += 3)
    printf("%d %d %d\n", g[i], g[i + 1], g[i + 2]);
  return 0;
}
