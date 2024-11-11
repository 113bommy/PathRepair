#include <bits/stdc++.h>
using namespace std;
const int M = (int)5e4;
int n, k;
int ans;
int cnt;
int head[M + 5];
struct Edge {
  int v, nx;
} Edge[M * 2 + 5];
bool vis[M + 5];
int rt, Max[M + 5], sz[M + 5];
int dis[M + 5];
void init(int n) {
  Max[0] = n, ans = cnt = 0;
  for (int i = 1; i <= n; ++i) {
    vis[i] = 0;
    head[i] = -1;
  }
}
void add(int u, int v) {
  Edge[cnt].v = v;
  Edge[cnt].nx = head[u];
  head[u] = cnt++;
}
void get_rt(int u, int fa) {
  sz[u] = 1, Max[u] = 0;
  for (int i = head[u]; ~i; i = Edge[i].nx) {
    int v = Edge[i].v;
    if (v == fa || vis[v]) continue;
    get_rt(v, u);
    sz[u] += sz[v];
    Max[u] = max(Max[u], sz[v]);
  }
  Max[u] = max(Max[u], n - sz[u]);
  if (Max[u] < Max[rt]) rt = u;
}
void get_dis(int u, int fa, int d) {
  for (int i = head[u]; ~i; i = Edge[i].nx) {
    int v = Edge[i].v;
    if (v == fa || vis[v]) continue;
    dis[++cnt] = d + 1;
    get_dis(v, u, dis[cnt]);
  }
}
int get_ans(int u, int d) {
  dis[cnt = 1] = d, get_dis(u, 0, d), sort(dis + 1, dis + cnt + 1);
  int l = 1, ans = 0;
  while (l < cnt && dis[l] + dis[cnt] < k) ++l;
  while (l < cnt && k - dis[l] >= dis[l]) {
    ans += upper_bound(dis + l + 1, dis + cnt + 1, k - dis[l]) -
           lower_bound(dis + l + 1, dis + cnt + 1, k - dis[l]);
    ++l;
  }
  return ans;
}
void dfs(int u) {
  vis[u] = 1;
  ans += get_ans(u, 0);
  for (int i = head[u]; ~i; i = Edge[i].nx) {
    int v = Edge[i].v;
    if (vis[v]) continue;
    ans -= get_ans(v, 1);
    n = sz[v], rt = 0, get_rt(v, u);
    dfs(rt);
  }
}
int main() {
  scanf("%d %d", &n, &k);
  init(n);
  for (int i = 0, u, v; i < n - 1; ++i) {
    scanf("%d %d", &u, &v);
    add(u, v);
    add(v, u);
  }
  rt = 0, get_rt(1, 0);
  dfs(rt);
  printf("%d\n", ans);
  return 0;
}
