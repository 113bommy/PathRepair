#include <bits/stdc++.h>
template <class Num>
void read(Num &x) {
  char c;
  int flag = 1;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') flag *= -1;
  x = c - '0';
  while ((c = getchar()) >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c - '0');
  x *= flag;
}
template <class Num>
void write(Num x) {
  if (!x) {
    putchar('0');
    return;
  }
  if (x < 0) putchar('-'), x = -x;
  static char s[20];
  int sl = 0;
  while (x) s[sl++] = x % 10 + '0', x /= 10;
  while (sl) putchar(s[--sl]);
}
const int maxn = 2005, maxm = 1e5 + 20, nya = -1;
struct Edge {
  int v, next;
  Edge(int v = 0, int next = 0) : v(v), next(next) {}
} edge[maxm << 1];
int N, M, head[maxn], el;
int snum, set[maxn];
bool hash[maxn], leaf[maxn];
std::vector<int> G[maxn];
int tnum, root[maxn];
void newedge(int u, int v) { edge[el] = Edge(v, head[u]), head[u] = el++; }
void Tarjan(int a, int pre) {
  static int dt = 0, low[maxn] = {0}, dfn[maxn] = {0}, stack[maxn] = {0},
             top = 0;
  static bool flag[maxn] = {false};
  hash[a] = true;
  low[a] = dfn[a] = ++dt;
  stack[++top] = a, flag[a] = true;
  for (int i = head[a]; i != nya; i = edge[i].next) {
    if ((i ^ 1) == pre) continue;
    int p = edge[i].v;
    if (!hash[p])
      Tarjan(p, i), low[a] = std::min(low[a], low[p]);
    else if (flag[p])
      low[a] = std::min(low[a], dfn[p]);
  }
  if (low[a] == dfn[a]) {
    ++snum;
    while (true) {
      int p = stack[top--];
      flag[p] = false;
      set[p] = snum;
      if (p == a) break;
    }
  }
}
void init() {
  int u, v;
  read(N), read(M);
  for (int i = 1; i <= N; i++) head[i] = nya;
  for (int i = 1; i <= M; i++) {
    read(u), read(v);
    newedge(u, v), newedge(v, u);
  }
}
void rebuild() {
  for (int i = 1; i <= N; i++)
    for (int j = head[i]; j != nya; j = edge[j].next) {
      int v = set[edge[j].v];
      if (set[i] != v) G[set[i]].push_back(v);
    }
}
int dfs(int a) {
  int ret = 0;
  if (G[a].size() != 1) ret = a;
  hash[a] = true;
  for (int i = 0; i < G[a].size(); i++)
    if (!hash[G[a][i]]) ret = std::max(dfs(G[a][i]), ret);
  return ret;
}
std::pair<int, int> path(int a, int fa) {
  std::pair<int, int> ret = std::make_pair(0, a);
  for (int i = 0; i < G[a].size(); i++)
    if (G[a][i] != fa && !leaf[G[a][i]]) ret = std::max(ret, path(G[a][i], a));
  ret.first++;
  return ret;
}
void solve() {
  int ans = 0;
  for (int i = 1; i <= snum; i++) hash[i] = false;
  for (int i = 1; i <= snum; i++)
    if (!hash[i]) root[++tnum] = dfs(i);
  ans = N + tnum - 1;
  for (int i = 1; i <= snum; i++)
    if (G[i].size() <= 1) leaf[i] = true, ans--;
  for (int i = 1; i <= tnum; i++)
    if (root[i]) ans -= path(path(root[i], 0).second, 0).first;
  write(ans);
}
int main() {
  init();
  for (int i = 1; i <= N; i++)
    if (!hash[i]) Tarjan(i, M << 1 | 1);
  rebuild();
  solve();
  return 0;
}
