#include <bits/stdc++.h>
const int maxn = 1e6 + 10;
const int inf = 0x3f3f3f3f;
const int K = 18;
const long long INF = 0x3f3f3f3f3f3f3f3f;
using namespace std;
struct edge {
  int next, v, w;
} s[maxn << 1];
struct node {
  int u, v, w, i;
  bool operator<(const node& a) const { return w < a.w; }
};
bool cmp(const node& a, const node& b) { return a.i < b.i; }
int head[maxn], tot = 0;
int n, m, x, y, z, f[maxn], path[maxn], d[maxn], ma[maxn][18], fa[maxn][18];
deque<node> v, tree, q;
int find(int xx) { return f[xx] == -1 ? xx : f[xx] = find(f[xx]); }
void dfs(int now, int pre) {
  d[now] = d[pre] + 1;
  for (int i = 1; i < 18; ++i) {
    fa[now][i] = fa[fa[now][i - 1]][i - 1];
    ma[now][i] = max(ma[now][i - 1], ma[fa[now][i - 1]][i - 1]);
  }
  for (int i = head[now]; ~i; i = s[i].next) {
    int tv = s[i].v;
    if (tv == pre) continue;
    fa[tv][0] = now;
    ma[tv][0] = s[i].w;
    dfs(tv, now);
  }
}
void add(int u, int v, int w) {
  s[tot].v = v;
  s[tot].w = w;
  s[tot].next = head[u];
  head[u] = tot++;
}
int LCA(int x, int y) {
  int ans = -1;
  if (d[x] > d[y]) swap(x, y);
  int dd = d[y] - d[x];
  for (int i = 17; i >= 0; --i)
    if ((1 << i) <= dd) {
      ans = max(ans, ma[y][i]);
      y = fa[y][i];
    }
  if (x == y) return ans;
  for (int i = 17; i >= 0; --i)
    if (fa[x][i] != fa[y][i]) {
      ans = max(ans, max(ma[x][i], ma[y][i]));
      x = fa[x][i];
      y = fa[y][i];
    }
  return max(ans, max(ma[x][0], ma[y][0]));
}
int main() {
  memset(head, -1, sizeof(head));
  memset(f, -1, sizeof(f));
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &x, &y, &z);
    q.push_back(node({x, y, z, i}));
  }
  int cnt = 0;
  sort(q.begin(), q.end());
  while (!q.empty()) {
    node k = q.front();
    q.pop_front();
    int fx = find(k.u), fy = find(k.v);
    if (fx != fy) {
      f[fx] = fy;
      ++cnt;
      tree.push_back(k);
    } else
      v.push_back(k);
    if (cnt == n - 1) break;
  }
  while (!q.empty()) {
    v.push_back(q.front());
    q.pop_front();
  }
  for (int i = 0; i < tree.size(); i++) {
    add(tree[i].u, tree[i].v, tree[i].w);
    add(tree[i].v, tree[i].u, tree[i].w);
  }
  dfs(1, 0);
  sort(v.begin(), v.end(), cmp);
  for (int i = 0; i < v.size(); i++) {
    printf("%d\n", (LCA(v[i].u, v[i].v)));
  }
}
