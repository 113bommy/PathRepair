#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50005;
const int MAXM = 300005;
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
inline void fail() {
  puts("NO");
  exit(0);
}
int n, m, tot, b[MAXM], cnt, s[MAXM], top;
int dfn[MAXM], low[MAXM], clk, stk[MAXM], instk[MAXM], scc, bel[MAXM];
vector<int> es[MAXN], g[MAXM], ans;
struct Edge {
  int u, v, c, t;
} e[MAXM];
inline bool ccmp(int x, int y) { return e[x].c < e[y].c; }
inline void Link(int x, int y) { g[x].push_back(y); }
inline void Build() {
  for (int i = 1; i <= top; ++i) {
    if (i < top) {
      Link(s[i], tot + i + 1);
      Link(tot + i, tot + i + 1);
      Link(tot + top + i, m + s[i]);
    }
    if (i > 1) {
      Link(s[i], tot + top + i - 1);
      Link(tot + top + i, tot + top + i - 1);
      Link(tot + i, m + s[i]);
    }
  }
  tot += top * 2;
}
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
  if (dfn[u] == low[u]) {
    ++scc;
    int x;
    do {
      x = stk[top--];
      instk[x] = 0;
      bel[x] = scc;
    } while (x != u);
  }
}
bool check(int mid) {
  for (int i = 1; i <= m; ++i) {
    if (e[i].t > mid) {
      Link(i, m + i);
    }
  }
  clk = top = scc = 0;
  for (int i = 1; i <= tot; ++i) {
    dfn[i] = low[i] = 0;
  }
  for (int i = 1; i <= tot; ++i) {
    if (!dfn[i]) {
      Tarjan(i);
    }
  }
  for (int i = 1; i <= m; ++i) {
    if (e[i].t > mid) {
      g[i].pop_back();
    }
  }
  bool ret = 1;
  for (int i = 1; i <= m; ++i) {
    if (bel[i] == bel[m + i]) {
      ret = 0;
      break;
    }
  }
  return ret;
}
void init() {
  read(n);
  read(m);
  tot = m * 2;
  b[++cnt] = 0;
  for (int i = 1; i <= m; ++i) {
    read(e[i].u);
    read(e[i].v);
    read(e[i].c);
    read(e[i].t);
    b[++cnt] = e[i].t;
    es[e[i].u].push_back(i);
    es[e[i].v].push_back(i);
  }
  sort(b + 1, b + cnt + 1);
  cnt = unique(b + 1, b + cnt + 1) - (b + 1);
}
void solve() {
  for (int i = 1; i <= n; ++i) {
    sort(es[i].begin(), es[i].end(), ccmp);
    top = 0;
    for (auto j : es[i]) {
      s[++top] = j;
    }
    Build();
    for (int l = 1, r = 1; l <= top; l = ++r) {
      while (r + 1 < top && e[s[l]].c == e[s[r + 1]].c) ++r;
      if (r - l + 1 > 2) {
        puts("No");
        return;
      }
      if (r == l + 1) {
        Link(m + s[l], s[r]);
        Link(m + s[r], s[l]);
      }
    }
  }
  int L = 1, R = cnt, M = 0;
  while (L <= R) {
    int mid = (L + R) >> 1;
    if (check(b[mid])) {
      M = mid;
      R = mid - 1;
    } else {
      L = mid + 1;
    }
  }
  if (!M) {
    puts("No");
    return;
  }
  puts("Yes");
  check(b[M]);
  for (int i = 1; i <= m; ++i) {
    if (bel[i] < bel[m + i]) {
      ans.push_back(i);
    }
  }
  printf("%d %d\n", b[M], ans.size());
  for (auto i : ans) {
    printf("%d ", i);
  }
}
int main() {
  init();
  solve();
  return 0;
}
