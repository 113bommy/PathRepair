#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005, INF = 0x3f3f3f3f;
struct Edge {
  int to, next;
} edge[MAXN << 1];
int head[MAXN], sz[MAXN], n, tot;
void addedge(int u, int v) {
  edge[++tot] = (Edge){v, head[u]};
  head[u] = tot;
}
void get_sz(int u, int fa) {
  sz[u] = 1;
  for (int i = head[u]; i; i = edge[i].next) {
    int v = edge[i].to;
    if (v == fa) continue;
    get_sz(v, u);
    sz[u] += sz[v];
  }
}
pair<int, int> get_rt(int u, int fa, int s) {
  pair<int, int> res(INF, INF);
  int mx = s;
  for (int i = head[u]; i; i = edge[i].next) {
    int v = edge[i].to;
    if (v == fa) continue;
    res = min(res, get_rt(v, u, s + sz[u] - sz[v]));
    mx = max(mx, sz[v]);
  }
  return min(res, pair<int, int>(mx, u));
}
int bs, dep[MAXN], cnt;
void dfs(int u, int fa) {
  int p = (dep[u] = ++cnt) - dep[fa];
  printf("%d %d %d\n", fa, u, bs * p);
  for (int i = head[u]; i; i = edge[i].next) {
    int v = edge[i].to;
    if (v != fa) dfs(v, u);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    addedge(u, v), addedge(v, u);
  }
  get_sz(1, 0);
  int r = get_rt(1, 0, 0).second;
  get_sz(r, 0);
  vector<pair<int, int> > vec;
  for (int i = head[r]; i; i = edge[i].next)
    vec.push_back(pair<int, int>(sz[edge[i].to], edge[i].to));
  sort(vec.begin(), vec.end());
  int a = 0, k;
  bs = 1;
  for (k = 0; k < (int)vec.size(); k++) {
    a += vec[k].first;
    if (a > n * 2 / 3) {
      a -= vec[k].first;
      break;
    } else
      dfs(vec[k].second, r);
  }
  cnt = 0, bs = a + 1;
  for (; k < (int)vec.size(); k++) dfs(vec[k].second, r);
  return 0;
}
