#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;
struct node {
  int to, nxt;
} edge[maxn << 1];
int head[maxn], tot;
int n, m;
vector<pair<int, pair<int, int>>> ans;
bool flag[maxn];
void add(int u, int v) {
  edge[++tot].to = v;
  edge[tot].nxt = head[u];
  head[u] = tot;
  edge[++tot].to = u;
  edge[tot].nxt = head[v];
  head[v] = tot;
}
int dep[maxn];
bool vis[maxn];
void dfs(int u, int fa) {
  vector<int> tmp;
  vis[u] = true;
  for (int i = head[u]; ~i; i = edge[i].nxt) {
    int to = edge[i].to;
    if (to == fa) continue;
    if (!vis[to]) {
      dep[to] = dep[u] + 1;
      dfs(to, u);
      if (!flag[to]) {
        tmp.push_back(to);
      }
    } else {
      if (dep[to] > dep[u]) {
        tmp.push_back(to);
      }
    }
  }
  int sz = tmp.size();
  for (int i = 0; i < sz - 1; i += 2) {
    int fi = tmp[i], se = tmp[i + 1];
    ans.push_back(make_pair(fi, make_pair(u, se)));
  }
  if ((fa != -1) && (sz % 2 == 1)) {
    int fi = tmp.back();
    ans.push_back(make_pair(fi, make_pair(u, fa)));
    flag[u] = true;
  }
}
int main() {
  memset(head, -1, sizeof(head));
  scanf("%d", &n);
  scanf("%d", &m);
  while (m--) {
    int u, v;
    scanf("%d", &u);
    scanf("%d", &v);
    add(u, v);
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    dfs(1, -1);
  }
  printf("%d\n", ans.size());
  for (auto to : ans)
    printf("%d %d %d\n", to.first, to.second.first, to.second.second);
  return 0;
}
