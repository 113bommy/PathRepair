#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 22;
int n, m;
int dis[N], s[32];
vector<pair<int, int> > G[N];
vector<int> c;
void dfs(int v, int p = -1) {
  for (int i = 0; i < (G[v].size()); i++) {
    int u = G[v][i].first, z = G[v][i].second;
    if (dis[u] != -1) {
      if (u == p) continue;
      c.push_back(dis[u] ^ dis[v] ^ z);
      continue;
    }
    dis[u] = dis[v] ^ z;
    dfs(u, v);
  }
}
int lbit(int x) {
  if (!x) return -1;
  for (int i = 30; ~i; i--)
    if ((1 << i) & x) return i;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int x, y, z;
  cin >> n >> m;
  for (int i = 0; i < (m); i++)
    cin >> x >> y >> z, x--, y--, G[x].push_back({y, z}),
        G[y].push_back({x, z});
  memset(dis, -1, sizeof(dis)), memset(s, -1, sizeof(s));
  dis[0] = 0;
  dfs(0);
  for (int i = 0; i < (c.size()); i++) {
    x = c[i];
    for (int j = 30; ~j; j--)
      if (((1 << j) & x) && s[j] != -1) x ^= s[j];
    if (x) s[lbit(x)] = x;
  }
  x = dis[n - 1];
  for (int i = 30; ~i; i--)
    if ((1 << i) & x && s[i] != -1) x ^= s[i];
  cout << x;
  return 0;
}
