#include <bits/stdc++.h>
using namespace std;
bool mark[100005];
struct E {
  int to, nx, d;
} edge[100005 << 1];
int tot, head[100005];
void Addedge(int a, int b, int d) {
  edge[++tot].to = b;
  edge[tot].nx = head[a];
  edge[tot].d = d;
  head[a] = tot;
}
int fa[100005][20], dep[100005];
int Up(int x, int y) {
  for (int i = 0; i < 20; i++)
    if ((1 << i) & y) x = fa[x][i];
  return x;
}
int LCA(int a, int b) {
  if (dep[a] < dep[b]) swap(a, b);
  a = Up(a, dep[a] - dep[b]);
  if (a == b) return a;
  for (int i = 19; i >= 0; i--)
    if (fa[a][i] != fa[b][i]) a = fa[a][i], b = fa[b][i];
  return fa[a][0];
}
struct Mx_bin {
  int num, d;
  void Add(int nxt, int nxt_d, int lca) {
    if (nxt_d < -1e8) return;
    if (nxt_d == d)
      num = lca;
    else if (nxt_d > d) {
      num = nxt;
      d = nxt_d;
    }
  }
  void Init(int x) {
    num = x;
    d = 0;
  }
} Mx[100005];
vector<Mx_bin> Pre[100005], Suf[100005];
int sz_son[100005], Add[100005];
void dfs(int now) {
  Mx[now].Init(now);
  if (!mark[now]) Mx[now].d = -1e9;
  for (int i = 1; i < 20; i++) fa[now][i] = fa[fa[now][i - 1]][i - 1];
  for (int i = head[now]; i; i = edge[i].nx) {
    int nxt = edge[i].to;
    if (fa[now][0] == nxt) continue;
    sz_son[now]++;
    fa[nxt][0] = now;
    dep[nxt] = dep[now] + 1;
    dfs(nxt);
    Mx[now].Add(Mx[nxt].num, Mx[nxt].d + edge[i].d, now);
  }
  Pre[now].push_back((Mx_bin){0, (int)-1e9});
  Suf[now].push_back((Mx_bin){0, (int)-1e9});
  for (int i = head[now], id = 0; i; i = edge[i].nx) {
    int nxt = edge[i].to;
    if (fa[now][0] == nxt) continue;
    id++;
    Pre[now].push_back(Mx[nxt]);
    Pre[now][id].d += edge[i].d;
    Suf[now].push_back(Pre[now][id]);
  }
  Suf[now].push_back((Mx_bin){0, (int)-1e9});
  for (int i = sz_son[now] - 1; i >= 1; i--)
    Suf[now][i].Add(Suf[now][i + 1].num, Suf[now][i + 1].d, now);
  for (int i = 2; i <= sz_son[now]; i++)
    Pre[now][i].Add(Pre[now][i - 1].num, Pre[now][i - 1].d, now);
}
void redfs(int now, Mx_bin res) {
  if (mark[now]) {
    Mx_bin Ans = res;
    Ans.Add(Mx[now].num, Mx[now].d, now);
    int lca = LCA(Ans.num, now);
    Add[Ans.num]++;
    Add[now]++;
    Add[lca]--;
    Add[fa[lca][0]]--;
    res.Add(now, 0, now);
  }
  for (int i = head[now], id = 0; i; i = edge[i].nx) {
    int nxt = edge[i].to;
    if (fa[now][0] == nxt) continue;
    id++;
    Mx_bin nxt_d = Pre[now][id - 1];
    nxt_d.Add(Suf[now][id + 1].num, Suf[now][id + 1].d, now);
    nxt_d.Add(res.num, res.d, now);
    nxt_d.d += edge[i].d;
    redfs(nxt, nxt_d);
  }
}
int ans, cnt = 1;
void dfs_ans(int now) {
  for (int i = head[now]; i; i = edge[i].nx) {
    int nxt = edge[i].to;
    if (nxt == fa[now][0]) continue;
    dfs_ans(nxt);
    Add[now] += Add[nxt];
  }
  if (mark[now]) return;
  if (Add[now] == ans)
    cnt++;
  else if (Add[now] > ans)
    ans = Add[now], cnt = 1;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1, x; i <= m; i++) scanf("%d", &x), mark[x] = true;
  for (int i = 1; i < n; i++) {
    int a, b, d;
    scanf("%d%d%d", &a, &b, &d);
    Addedge(a, b, d);
    Addedge(b, a, d);
  }
  dfs(1);
  redfs(1, (Mx_bin){0, (int)-1e9});
  dfs_ans(1);
  printf("%d %d\n", ans, cnt);
  return 0;
}
