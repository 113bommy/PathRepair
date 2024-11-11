#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3000 + 10;
const int K = 100000;
const int base = 1000000000;
const int base_digits = 9;
int cnt, n, m, ans, a[MAXN], bas[MAXN][2], P[MAXN], match[MAXN];
bool vis[MAXN], G[MAXN][MAXN];
vector<int> adj[MAXN];
bool dfs(int v) {
  vis[v] = 1;
  for (int i = 0; i < (int((adj[v]).size())); i++)
    if (match[adj[v][i]] == 0) {
      match[v] = adj[v][i];
      match[adj[v][i]] = v;
      return 1;
    }
  for (int i = 0; i < (int((adj[v]).size())); i++) {
    int u = match[adj[v][i]];
    if (!vis[u] && dfs(u)) {
      match[v] = adj[v][i];
      match[adj[v][i]] = v;
      return 1;
    }
  }
  return 0;
}
void make(int id) {
  bas[id][0] = cnt + 1;
  int a0 = a[id];
  for (int i = 2; i * i <= a0; i++)
    while (a0 % i == 0) {
      P[++cnt] = i;
      a0 /= i;
    }
  if (a0 > 1) P[++cnt] = a0;
  bas[id][1] = cnt;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    G[x][y] = G[y][x] = 1;
  }
  for (int i = 0; i < n; i++) make(i);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++)
      if (G[i][j])
        for (int s0 = bas[i][0]; s0 <= bas[i][1]; s0++)
          for (int s1 = bas[j][0]; s1 <= bas[j][1]; s1++)
            if (P[s0] == P[s1]) {
              adj[s0].push_back(s1);
              adj[s1].push_back(s0);
            }
  for (int i = 1; i <= cnt; i++)
    if (match[i] == 0 && dfs(i)) {
      ans++;
      memset(vis, 0, sizeof vis);
    }
  printf("%d", ans);
  return 0;
}
