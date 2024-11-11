#include <bits/stdc++.h>
using namespace std;
const int MAXL = 3e5;
int n, x, y, u, v, m, sub_size[MAXL + 5];
bool vis[MAXL + 5], chk_sub[MAXL + 5];
vector<int> adj[MAXL + 5];
int DFS(int u) {
  vis[u] = true;
  sub_size[u] = 1;
  if (u == x)
    chk_sub[u] = true;
  else
    chk_sub[u] = false;
  for (int v : adj[u])
    if (!vis[v]) {
      sub_size[u] += DFS(v);
      chk_sub[u] |= chk_sub[v];
    }
  return sub_size[u];
}
int main() {
  scanf("%d %d %d", &n, &x, &y);
  m = n - 1;
  while (m--) {
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  DFS(y);
  long long fin;
  for (int v : adj[y])
    if (chk_sub[v]) {
      fin = sub_size[y] - sub_size[v];
      break;
    }
  printf("%I64d", 1LL * n * (n - 1) - sub_size[x] + 1);
  return 0;
}
