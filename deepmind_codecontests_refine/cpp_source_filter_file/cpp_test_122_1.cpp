#include <bits/stdc++.h>
using namespace std;
int tac, n, m;
vector<int> v[200010];
vector<pair<int, int> > vt[200010];
int a[200010];
bool vis[200010];
map<pair<int, int>, int> mp;
bool fl;
void dfs(int x, int col) {
  vis[x] = 1, a[x] = col;
  for (int i = 0; i < vt[x].size(); i++) {
    int xi = vt[x][i].first, yi = vt[x][i].second;
    if (vis[xi] && (a[x] ^ a[xi]) != yi)
      fl = 0;
    else if (!vis[xi])
      dfs(xi, col ^ yi);
  }
}
void dfsans(int x, int par) {
  if (x) {
    if (mp.count(make_pair(x, par)))
      printf("%d %d %d\n", x + 1, par + 1, mp[make_pair(x, par)]);
    else
      printf("%d %d %d\n", x + 1, par + 1, a[x]);
  }
  for (int i = 0; i < v[x].size(); i++) {
    int xi = v[x][i];
    if (xi != par) dfsans(xi, x);
  }
}
int main() {
  scanf("%d", &tac);
  while (tac--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) v[i].clear(), vt[i].clear();
    mp.clear();
    fill(a, a + n, 0);
    for (int i = 0; i < n - 1; i++) {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z), x--, y--;
      v[x].push_back(y), v[y].push_back(x);
      if (z == -1) continue;
      mp[make_pair(x, y)] = mp[make_pair(y, x)] = z;
      vt[x].push_back(make_pair(y, __builtin_popcount(z) % 2));
      vt[y].push_back(make_pair(x, __builtin_popcount(z) % 2));
    }
    for (int i = 0; i < m; i++) {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z), x--, y--;
      vt[x].push_back(make_pair(y, z));
      vt[y].push_back(make_pair(x, z));
    }
    fill(vis, vis + n, 0);
    fl = 1;
    for (int i = 0; i < n; i++)
      if (!vis[i]) dfs(i, 0);
    if (!fl) {
      puts("NO");
      continue;
    }
    puts("YES");
    dfsans(0, -1);
  }
  return 0;
}
