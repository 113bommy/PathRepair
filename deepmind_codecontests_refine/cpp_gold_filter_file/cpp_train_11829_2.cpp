#include <bits/stdc++.h>
using namespace std;
struct edge {
  int to, nxt;
} e[400005];
int n, m, cnt = -1, tot;
int que[200005], fir[200005], fa[200005], ans[400005][3];
;
bool vis[400005];
void add(int, int);
void find(int);
int main() {
  scanf("%d%d", &n, &m);
  memset(fir, -1, sizeof fir);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    add(u, v);
    add(v, u);
  }
  for (int i = 1; i <= n; ++i)
    if (!fa[i]) find(i);
  cout << tot << endl;
  for (int i = 1; i <= tot; ++i)
    printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
  return 0;
}
void add(int u, int v) {
  e[++cnt] = (edge){v, fir[u]};
  fir[u] = cnt;
  return;
}
void find(int x) {
  int l = 0, r = 0;
  que[++r] = x;
  fa[x] = -1;
  while (l < r)
    for (int i = fir[que[++l]]; ~i; i = e[i].nxt) {
      int v = e[i].to;
      if (!fa[v]) que[++r] = v, fa[v] = que[l];
    }
  while (r) {
    int u = que[r], f = -1;
    vector<int> G;
    for (int i = fir[u]; ~i; i = e[i].nxt)
      if (!vis[i]) {
        int v = e[i].to;
        if (v == fa[u])
          f = i;
        else
          G.push_back(i);
      }
    if (f != -1) G.push_back(f);
    int sz = G.size();
    for (int i = 0; i < sz - 1; i += 2) {
      vis[G[i]] = vis[G[i] ^ 1] = vis[G[i + 1]] = vis[G[i + 1] ^ 1] = true;
      ans[++tot][0] = e[G[i]].to;
      ans[tot][1] = que[r];
      ans[tot][2] = e[G[i + 1]].to;
    }
    --r;
  }
  return;
}
