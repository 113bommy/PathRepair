#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
template <typename T>
inline void read(T& x) {
  char c;
  int sign = 1;
  x = 0;
  do {
    c = getchar();
    if (c == '-') sign = -1;
  } while (!isdigit(c));
  do {
    x = x * 10 + c - '0';
    c = getchar();
  } while (isdigit(c));
  x *= sign;
}
const int N = 1e3 + 50;
vector<int> g[N], G[N];
int n, m, u[N * 5], v[N * 5], dis[N];
bool v1[N], vis[N];
void dfs(int x) {
  v1[x] = 1;
  for (auto& i : g[x])
    if (!v1[i]) dfs(i);
}
void Dfs(int x) {
  vis[x] = 1;
  for (auto& i : G[x])
    if (!v1[i]) dfs(i);
}
int main() {
  read(n);
  read(m);
  for (register int i = 1; i <= m; ++i) {
    read(u[i]);
    read(v[i]);
    g[u[i]].push_back(v[i]);
    G[v[i]].push_back(u[i]);
  }
  dfs(1);
  Dfs(n);
  for (register int i = 1; i <= n; ++i) vis[i] = v1[i] & vis[i];
  for (register int j = 1; j <= n + m; ++j)
    for (register int i = 1; i <= m; ++i)
      if (vis[u[i]] && vis[v[i]])
        dis[v[i]] = min(dis[v[i]], dis[u[i]] + 2),
        dis[u[i]] = min(dis[u[i]], dis[v[i]] - 1);
  for (register int x = 1; x <= n; ++x)
    if (vis[x])
      for (auto& i : g[x])
        if (vis[i] && (dis[i] - dis[x] < 1 || dis[i] - dis[x] > 2))
          return puts("No"), 0;
  puts("Yes");
  for (register int i = 1; i <= m; ++i)
    printf("%d\n", max(1, min(2, dis[v[i]] - dis[u[i]])));
  return 0;
}
