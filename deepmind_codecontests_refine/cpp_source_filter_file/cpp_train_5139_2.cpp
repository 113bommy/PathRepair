#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int head[N], cnt, vis[N], f[N], in[N], kk, lop[N], id, rk, lo[N];
bool huan[N], ok[N];
vector<pair<int, int> > ans[N];
struct edge {
  int next, to;
} e[N];
void add(int u, int v) {
  e[++cnt].next = head[u];
  e[cnt].to = v;
  head[u] = cnt;
}
void dfs(int u) {
  if (vis[u]) {
    int now = u;
    lop[++kk] = now;
    now = f[now];
    while (now != u) {
      lop[++kk] = now;
      now = f[now];
    }
    return;
  }
  vis[u] = id;
  dfs(f[u]);
}
void dfs1(int u) {
  vis[u] = id;
  if (in[u] == 0) ans[rk].push_back(make_pair(lop[1], u));
  for (int i = head[u]; i; i = e[i].next)
    if (!huan[e[i].to]) dfs1(e[i].to);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &f[i]), in[f[i]]++, add(f[i], i);
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    kk = 0;
    id++;
    dfs(i);
    if (kk > 0) rk++;
    for (int j = 1; j <= kk; j++) huan[lop[j]] = true;
    lo[rk] = lop[1];
    for (int j = 1; j <= kk; j++) dfs1(lop[j]);
  }
  if (rk <= 1) {
    int sum = 0;
    for (int i = 1; i <= rk; i++) sum += ans[i].size();
    printf("%d\n", sum);
    for (int i = 1; i <= rk; i++)
      for (auto it : ans[i]) printf("%d %d\n", it.first, it.second);
  } else {
    vector<pair<int, int> > res;
    vector<pair<int, int> > re;
    int sum = 0;
    for (int i = 1; i <= rk; i++) {
      int siz = ans[i].size();
      if (siz == 0) {
        res.push_back(make_pair(lo[i], lo[i]));
        sum++;
      } else {
        sum += siz;
        for (int j = 0; j < siz - 1; j++) re.push_back(ans[i][j]);
        res.push_back(ans[i][siz - 1]);
      }
    }
    printf("%d\n", sum);
    int siz = res.size();
    for (int i = 0; i < siz; i++)
      printf("%d %d\n", res[i].first, res[i + 1].second);
    printf("%d %d\n", res[siz - 1].first, res[0].second);
    for (auto it : re) printf("%d %d\n", it.first, it.second);
  }
  return 0;
}
