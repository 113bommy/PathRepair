#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m;
string name[N];
struct Query {
  int v, p, ans;
} q[N];
vector<int> vec[N], rt;
struct Edge {
  int nxt, to;
} edge[N << 1];
int head[N], edgeNum;
void addEdge(int from, int to) {
  edge[++edgeNum] = (Edge){head[from], to};
  head[from] = edgeNum;
}
int fa[N], son[N], sz[N], dep[N];
void dfs(int x, int f, int depth) {
  fa[x] = f, son[x] = 0, sz[x] = 1, dep[x] = depth;
  for (int i = head[x]; i; i = edge[i].nxt) {
    if (edge[i].to == f) continue;
    dfs(edge[i].to, x, depth + 1);
    sz[x] += sz[edge[i].to];
    if (!son[x] || sz[edge[i].to] > sz[son[x]]) son[x] = edge[i].to;
  }
}
int mark;
map<string, int> cnt[N << 1];
void getData(int x, int val) {
  cnt[dep[x]][name[x]] += val;
  if (cnt[dep[x]][name[x]] == 0) cnt[dep[x]].erase(name[x]);
  for (int i = head[x]; i; i = edge[i].nxt) {
    if (edge[i].to == fa[x]) continue;
    if (edge[i].to == mark) continue;
    getData(edge[i].to, val);
  }
}
void dsu(int x, bool opt) {
  for (int i = head[x]; i; i = edge[i].nxt) {
    if (edge[i].to == fa[x] || edge[i].to == son[x]) continue;
    dsu(edge[i].to, true);
  }
  if (son[x]) dsu(son[x], false), mark = son[x];
  getData(x, 1);
  for (auto k : vec[x]) q[k].ans = cnt[dep[x] + q[k].p].size();
  mark = 0;
  if (opt) getData(x, -1);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    cin >> name[i];
    int p;
    scanf("%d", &p);
    if (p == 0) rt.emplace_back(i);
    addEdge(i, p), addEdge(p, i);
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &q[i].v, &q[i].p);
    vec[q[i].v].emplace_back(i);
  }
  for (auto r : rt) dfs(r, 0, 0);
  for (auto r : rt) dsu(r, true);
  for (int i = 1; i <= m; i++) printf("%d\n", q[i].ans);
  return 0;
}
