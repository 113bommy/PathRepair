#include <bits/stdc++.h>
#pragma GCC optimize(3)
#pragma warning(disable : 4996)
template <typename T>
T min(T x, T y) {
  return x < y ? x : y;
}
template <typename T>
T max(T x, T y) {
  return x > y ? x : y;
};
const int MAXN = 405;
const int MAXM = 205 * 205 * 10;
namespace Graph {
int E[MAXN][MAXN];
void addedge(int u, int v) { E[u][v]++; }
int dfn[MAXN], low[MAXN];
int S[MAXN], sz;
int scc[MAXN], cnt;
int dfs_clock;
void clear() {
  memset(dfn, 0, sizeof(dfn));
  memset(low, 0, sizeof(low));
  memset(scc, 0, sizeof(scc));
  sz = cnt = dfs_clock = 0;
}
void dfs(int v) {
  low[v] = dfn[v] = ++dfs_clock;
  S[sz++] = v;
  for (int to = 1; to < MAXN; to++) {
    if (!E[v][to]) continue;
    if (!dfn[to]) {
      dfs(to);
      low[v] = min(low[v], low[to]);
    } else if (!scc[to])
      low[v] = min(low[v], dfn[to]);
  }
  if (low[v] == dfn[v]) {
    cnt++;
    int t = S[--sz];
    while (1) {
      scc[t] = cnt;
      if (t == v) break;
      t = S[--sz];
    }
  }
}
void tarjan() {
  for (int i = 0; i < MAXN; i++)
    if (!dfn[i]) dfs(i);
}
bool judge() {
  tarjan();
  for (int i = 0; i < 250; i++)
    if (scc[i * 2] == scc[i * 2 + 1]) return false;
  return true;
}
}  // namespace Graph
int N, M, L;
int ty[30];
int s[MAXN];
char mn[2];
int ans[MAXN];
bool judge(int cur) {
  Graph::clear();
  for (int i = 1; i <= cur; i++)
    Graph::addedge(i * 2 + !ty[ans[i]], i * 2 + ty[ans[i]]);
  bool t = Graph::judge();
  for (int i = 1; i <= cur; i++)
    Graph::E[i * 2 + !ty[ans[i]]][i * 2 + ty[ans[i]]]--;
  return t;
}
bool solve() {
  for (int i = 1; i <= N; i++) ans[i] = s[i];
  if (judge(N)) return true;
  int last;
  for (last = N - 1; last >= 0; last--) {
    if (s[last + 1] == L - 1) continue;
    ans[last + 1] = s[last + 1] + 1;
    if (judge(last + 1)) break;
    int t = s[last + 1] + 2;
    while (t < L && ty[t] == ty[s[last + 1] + 1]) t++;
    if (t < L) {
      ans[last + 1] = t;
      if (judge(last + 1)) break;
    }
  }
  if (last < 0) return false;
  if (mn[0] > mn[1]) std::swap(mn[0], mn[1]);
  for (int i = last + 2; i <= N; i++)
    for (int j = 0; j < 2; j++) {
      ans[i] = mn[j] - 'a';
      if (judge(i)) break;
    }
  return true;
}
void init() {
  static char str[MAXN];
  int p1, p2;
  char t1[10], t2[10];
  scanf("%s", str);
  L = strlen(str);
  for (int i = 0; i < L; i++) {
    ty[i] = str[i] == 'V';
    if (!mn[str[i] == 'V']) mn[str[i] == 'V'] = 'a' + i;
  }
  scanf("%d %d", &N, &M);
  for (int i = 1; i <= M; i++) {
    scanf("%d %s %d %s", &p1, t1, &p2, t2);
    Graph::addedge(p1 * 2 + (t1[0] == 'V'), p2 * 2 + (t2[0] == 'V'));
    Graph::addedge(p2 * 2 + !(t2[0] == 'V'), p1 * 2 + !(t1[0] == 'V'));
  }
  if (!mn[0])
    for (int i = 1; i <= N; i++) Graph::addedge(i * 2, i * 2 + 1);
  if (!mn[1])
    for (int i = 1; i <= N; i++) Graph::addedge(i * 2 + 1, i * 2);
  scanf("%s", str);
  for (int i = 0; i < N; i++) s[i + 1] = str[i] - 'a';
}
int main() {
  init();
  if (solve())
    for (int i = 1; i <= N; i++) printf("%c", ans[i] + 'a');
  else
    printf("-1");
  return 0;
}
