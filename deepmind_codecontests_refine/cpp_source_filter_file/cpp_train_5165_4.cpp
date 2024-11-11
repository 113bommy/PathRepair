#include <bits/stdc++.h>
using namespace std;
int n, m, l, r;
int lim[300010], nd[300010];
struct edge {
  int to, num;
};
vector<edge> ed[300010];
inline void ade(int l, int r, int val) {
  ed[l].push_back({r, val});
  ed[r].push_back({l, val});
}
bool vis[300010], ins[300010];
int ned[300010], ok, cnt, acnt;
void dfs(int nw) {
  for (int i = 0; i < ed[nw].size(); ++i) {
    int tar = ed[nw][i].to;
    if (vis[tar]) continue;
    vis[tar] = 1;
    dfs(tar);
    if (lim[tar] != -1 && lim[tar] != nd[tar])
      nd[tar] ^= 1, nd[nw] ^= 1, ins[ed[nw][i].num] = 1, ++acnt;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &lim[i]);
  for (int i = 1; i <= m; ++i) scanf("%d%d", &l, &r), ade(l, r, i);
  for (int i = 1; i <= n; ++i) {
    ok = (lim[i] == -1) ? i : ok, cnt |= (lim[i] == 1);
  }
  if (cnt == 1 && !ok) {
    return cout << -1, 0;
  }
  if (!ok) ok = 1;
  vis[ok] = 1, dfs(ok);
  if (lim[ok] != -1 && nd[ok] != lim[ok]) {
    return cout << -1, 0;
  } else {
    printf("%d\n", acnt);
    for (int i = 1; i <= m; ++i)
      if (ins[i]) printf("%d ", i);
  }
  return 0;
}
