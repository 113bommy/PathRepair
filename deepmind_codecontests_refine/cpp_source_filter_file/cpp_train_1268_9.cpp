#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1600005;
template <typename T>
inline void read(T &AKNOI) {
  T x = 0, flag = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  AKNOI = flag * x;
}
int n, p, M, m, tot, ansf;
int dfn[MAXN], low[MAXN], clk;
int stk[MAXN], top, instk[MAXN];
int scc, bel[MAXN];
vector<int> g[MAXN], ans;
inline void Add(int u, int v) { g[u].push_back(v); }
void Tarjan(int u) {
  dfn[u] = low[u] = ++clk;
  stk[++top] = u;
  instk[u] = 1;
  for (auto v : g[u]) {
    if (!dfn[v]) {
      Tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (instk[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (low[u] == dfn[u]) {
    ++scc;
    int x;
    do {
      x = stk[top--];
      instk[x] = 0;
      bel[x] = scc;
    } while (x != u);
  }
}
void init() {
  read(n);
  read(p);
  read(M);
  read(m);
  tot = p + M;
  for (int i = 1, x, y; i <= n; ++i) {
    read(x);
    read(y);
    Add(x + tot, y);
    Add(y + tot, x);
  }
  for (int i = 1, l, r; i <= p; ++i) {
    read(l);
    read(r);
    Add(i, l + p);
    Add(l + p + tot, i + tot);
    if (++r <= p) {
      Add(i, r + p + tot);
      Add(r + p, i + tot);
    }
  }
  for (int i = 1, x, y; i <= m; ++i) {
    read(x);
    read(y);
    Add(x, y + tot);
    Add(y, x + tot);
  }
  for (int i = 1; i < M; ++i) {
    Add(i + 1 + p, i + p);
    Add(i + p + tot, i + 1 + p + tot);
  }
}
void solve() {
  for (int i = 1; i <= (tot << 1); ++i) {
    if (!dfn[i]) {
      Tarjan(i);
    }
  }
  for (int i = 1; i <= tot; ++i) {
    if (bel[i] == bel[i + tot]) {
      printf("-1\n");
      return;
    }
    if (bel[i] < bel[i + tot]) {
      if (i <= p)
        ans.push_back(i);
      else
        ansf = i - p;
    }
  }
  printf("%d %d\n", ans.size(), ansf);
  for (auto i : ans) {
    printf("%d ", i);
  }
}
int main() {
  init();
  solve();
  return 0;
}
