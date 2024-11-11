#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e6 + 5;
int n, m;
vector<int> p, c;
struct Edge {
  int to, nxt;
} e[MAX_N];
int cnt;
int head[MAX_N], tote;
void add_edge(int x, int y) {
  e[++tote].to = y, e[tote].nxt = head[x];
  head[x] = tote;
}
int dfn[MAX_N], low[MAX_N];
int idx;
int belong[MAX_N], scc;
int Stack[MAX_N], top;
bool in_stack[MAX_N];
void tarjan(int u) {
  dfn[u] = low[u] = ++idx;
  Stack[top++] = u;
  in_stack[u] = true;
  for (int i = head[u]; i; i = e[i].nxt) {
    int to = e[i].to;
    if (!dfn[to]) {
      tarjan(to);
      low[u] = min(low[u], low[to]);
    } else if (in_stack[to])
      low[u] = min(low[u], dfn[to]);
  }
  if (dfn[u] == low[u]) {
    ++scc;
    do {
      belong[Stack[--top]] = scc;
      in_stack[Stack[top]] = false;
    } while (Stack[top] != u);
  }
}
void init(int n) {
  for (register int i = 1; i <= n; i++)
    dfn[i] = low[i] = belong[i] = in_stack[i] = head[i] = 0;
  tote = idx = scc = top = 0;
  p.clear(), c.clear();
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n), scanf("%d", &m);
    init(2 * n);
    for (register int i = 1; i <= m; i++) {
      int u, v;
      scanf("%d", &u), scanf("%d", &v);
      if (u == v)
        add_edge(u, v + n), add_edge(v + n, u);
      else
        add_edge(u, v + n);
    }
    for (register int i = 1; i <= 2 * n; i++)
      if (!dfn[i]) tarjan(i);
    if (scc == 1) {
      puts("No");
      continue;
    }
    puts("Yes");
    for (register int i = 1; i <= n; i++) {
      if (belong[i] == 1)
        p.push_back(i);
      else
        c.push_back(i);
    }
    int lp = p.size(), lc = c.size();
    printf("%d %d\n", lp, lc);
    for (register int i = 0; i <= lp - 1; i++)
      printf("%d%c", p[i], i == lp - 1 ? '\n' : ' ');
    for (register int i = 0; i <= lc - 1; i++)
      printf("%d%c", c[i], i == lc - 1 ? '\n' : ' ');
  }
  return 0;
}
