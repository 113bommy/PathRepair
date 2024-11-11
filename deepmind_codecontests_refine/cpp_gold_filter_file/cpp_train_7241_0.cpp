#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> g[400005];
int q, _n;
vector<int> ed[400005];
int num[400005], cnt, pos[400005], fa[400005], low[400005];
map<pair<int, int>, int> good;
map<pair<int, int>, pair<int, int> > dhuisdhf;
int vis[400005];
pair<int, int> in[400005];
int fnd(int x) { return fa[x] = (fa[x] == x) ? x : fnd(fa[x]); }
bool merge(int x, int y) {
  x = fnd(x);
  y = fnd(y);
  if (x == y) return 0;
  if (num[x] < num[y]) swap(x, y);
  num[x] += num[y];
  fa[y] = x;
  return 1;
}
void tarjan(int now, int lst = -1) {
  pos[now] = low[now] = ++cnt;
  for (int i = 0; i < (int)g[now].size(); i++) {
    int to = g[now][i];
    if (to == lst) continue;
    if (!pos[to]) {
      tarjan(to, now);
      low[now] = min(low[now], low[to]);
      if (pos[now] >= low[to]) merge(now, to);
    } else
      low[now] = min(low[now], low[to]);
  }
}
void dfs1(int ind, int lst, int pa) {
  vis[ind] = 1;
  for (int i = 0; i < (int)g[ind].size(); i++) {
    int now = g[ind][i];
    if (fnd(now) != pa) continue;
    if (now == lst) continue;
    if (vis[now] == 2) continue;
    good[make_pair(ind, now)] = 1;
    if (!vis[now]) dfs1(now, ind, pa);
  }
  vis[ind] = 2;
}
void dfs2(int ind) {
  vis[ind] = 1;
  for (int i = 0; i < (int)ed[ind].size(); i++) {
    int now = ed[ind][i];
    if (vis[now]) continue;
    good[dhuisdhf[make_pair(now, ind)]] = 1;
    dfs2(now);
  }
}
map<pair<int, int>, int> ct;
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) fa[i] = i, num[i] = 1;
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    in[i] = make_pair(a, b);
    if (ct.find(make_pair(a, b)) != ct.end() ||
        ct.find(make_pair(b, a)) != ct.end())
      continue;
    g[a].push_back(b);
    g[b].push_back(a);
    ct[make_pair(a, b)] = 1;
  }
  tarjan(1, 0);
  int mx = 0;
  for (int i = 1; i <= n; i++)
    if (fa[i] == i) mx = max(mx, num[i]);
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < (int)g[i].size(); j++) {
      int a = fnd(i), b = fnd(g[i][j]);
      if (a != b) {
        ed[a].push_back(b);
        dhuisdhf[make_pair(a, b)] = make_pair(i, g[i][j]);
      }
    }
  for (int i = 1; i <= n; i++)
    if (i == fa[i]) dfs1(i, 0, i);
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; i++)
    if (i == fa[i] && num[i] == mx) {
      dfs2(i);
      break;
    }
  printf("%d\n", mx);
  for (int i = 1; i <= m; i++) {
    if (good.find(make_pair(in[i].first, in[i].second)) != good.end())
      printf("%d %d\n", in[i].first, in[i].second);
    else
      printf("%d %d\n", in[i].second, in[i].first);
  }
  return 0;
}
