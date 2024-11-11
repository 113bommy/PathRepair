#include <bits/stdc++.h>
using namespace std;
template <typename T>
T &Read(T &first) {
  static char c;
  while (!isdigit(c = getchar()))
    ;
  first = c - '0';
  while (isdigit(c = getchar())) (first *= 10) += c - '0';
  return first;
}
const int maxn = 200000, maxm = 200000, max0 = 18;
int st[maxn + 5];
int n, m;
struct edge {
  int id, nxt;
  edge() {}
  edge(const int &_id, const int &_nxt) : id(_id), nxt(_nxt) {}
};
int en;
edge e[(maxm << 1) + 5];
inline void add_edge(const int &first, const int &second) {
  e[en] = edge(second, st[first]), st[first] = en++;
}
int low[maxn + 5], dfn[maxn + 5];
int dn = 0;
int belong[maxn + 5], fa[maxn + 5][max0], dep[maxn + 5];
int stk[maxn + 5], tot = 0;
int cnt = 0;
int N = 0;
void dfs(const int &first, const int &f = -1) {
  low[first] = dfn[first] = dn++;
  stk[tot++] = first;
  for (int i = st[first]; i != -1; i = e[i].nxt) {
    const int &second = e[i].id;
    if (i >> 1 == f) continue;
    if (dfn[second] == -1) {
      dfs(second, i >> 1);
      if (dfn[second] == low[second]) fa[belong[second]][0] = first;
      low[first] = min(low[first], low[second]);
    } else
      low[first] = min(low[first], dfn[second]);
  }
  if (dfn[first] == low[first]) {
    while (1) {
      belong[stk[--tot]] = N;
      if (stk[tot] == first) break;
    }
    ++N;
  }
}
int End[maxn + 5];
vector<int> chd[maxn + 5];
int block[maxn + 5];
int bn = 0;
void dfs0(const int &first) {
  block[first] = bn;
  dfn[first] = dn++;
  for (auto second : chd[first]) dep[second] = dep[first] + 1, dfs0(second);
  End[first] = dn;
}
int lca(int first, int second) {
  if (dep[first] > dep[second]) swap(first, second);
  for (int i = 0; dep[first] != dep[second]; ++i)
    if ((dep[second] - dep[first]) >> i & 1) second = fa[second][i];
  int s = max0 - 1;
  while (first != second) {
    for (; fa[first][s] == fa[second][s] && s; --s)
      ;
    first = fa[first][s];
    second = fa[second][s];
  }
  return first;
}
int c0[maxn + 5], c1[maxn + 5];
void add(int *c, const int &first, const int &second) {
  for (int i = first + 1; i <= n; i += i & -i) c[i] += second;
}
int query(int *c, const int &first) {
  int ret = 0;
  for (int i = first; i > 0; i -= i & -i) ret += c[i];
  return ret;
}
int main() {
  memset(st, -1, sizeof st), en = 0;
  static int qn;
  scanf("%d%d%d", &n, &m, &qn);
  for (int i = (0), _end_ = (m); i < _end_; ++i) {
    static int first, second;
    scanf("%d%d", &first, &second), --first, --second;
    add_edge(first, second);
    add_edge(second, first);
  }
  memset(dfn, -1, sizeof dfn);
  memset(fa, -1, sizeof fa);
  for (int i = (0), _end_ = (n); i < _end_; ++i)
    if (dfn[i] == -1) dfs(i);
  dn = 0;
  for (int i = (0), _end_ = (N); i < _end_; ++i)
    if (fa[i][0] != -1) chd[fa[i][0] = belong[fa[i][0]]].push_back(i);
  for (int i = (1), _end_ = (max0); i < _end_; ++i)
    for (int j = (0), _end_ = (N); j < _end_; ++j)
      if (fa[j][i - 1] == -1)
        fa[j][i] = fa[j][i - 1];
      else
        fa[j][i] = fa[fa[j][i - 1]][i - 1];
  dn = 0;
  bn = 0;
  for (int i = (0), _end_ = (N); i < _end_; ++i)
    if (fa[i][0] == -1) dep[i] = 0, dfs0(i), ++bn;
  for (int i = (0), _end_ = (qn); i < _end_; ++i) {
    static int u, v;
    scanf("%d%d", &u, &v), --u, --v;
    u = belong[u], v = belong[v];
    if (block[u] != block[v]) printf("No\n"), exit(0);
    if (u == v) continue;
    int d = lca(u, v);
    add(c0, dfn[u], 1);
    add(c0, dfn[d], -1);
    add(c1, dfn[v], 1);
    add(c1, dfn[d], -1);
  }
  for (int i = (0), _end_ = (N); i < _end_; ++i)
    if (query(c0, End[i]) - query(c0, dfn[i]) &&
        query(c1, End[i]) - query(c1, dfn[i]))
      printf("No\n"), exit(0);
  printf("Yes\n");
  return 0;
}
