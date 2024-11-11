#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
int n, m, first[N], cnt, dfn[N], low[N], tot, scc[N], ins[N], sum;
struct node {
  int v, nxt;
} e[N << 2];
inline void add(int u, int v) {
  e[++cnt].v = v;
  e[cnt].nxt = first[u];
  first[u] = cnt;
}
stack<int> s;
inline void tarjan(int u) {
  dfn[u] = low[u] = ++tot;
  s.push(u);
  ins[u] = 1;
  for (int i = first[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (ins[v])
      low[u] = min(low[u], dfn[v]);
  }
  if (dfn[u] == low[u]) {
    int t = s.top();
    sum++;
    while (t != u) {
      scc[t] = sum;
      ins[t] = 0;
      s.pop();
      t = s.top();
    }
    scc[u] = sum;
    s.pop();
    ins[u] = 0;
  }
}
int len[N];
vector<int> a[N];
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; ++i) {
    len[i] = read();
    for (int j = 1; j <= len[i]; ++j) {
      int v = read();
      a[i].push_back(v);
    }
  }
  for (int i = 1; i < n; ++i) {
    int j = 0;
    while (j < a[i].size() && j < a[i + 1].size() && a[i][j] == a[i + 1][j])
      ++j;
    if (j == a[i].size() && j == a[i + 1].size())
      continue;
    else if (j == a[i + 1].size()) {
      puts("NO");
      return 0;
    } else if (j == a[i].size())
      continue;
    else {
      if (a[i][j] < a[i + 1][j])
        add(a[i + 1][j] + m, a[i][j] + m), add(a[i][j], a[i + 1][j]);
      else
        add(a[i][j], a[i][j] + m), add(a[i + 1][j] + m, a[i + 1][j]);
    }
  }
  for (int i = 1; i <= 2 * m; ++i)
    if (!dfn[i]) tarjan(i);
  for (int i = 1; i <= m; ++i) {
    if (scc[i] == scc[i + m]) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  int ans = 0;
  for (int i = 1; i <= m; ++i)
    if (scc[i] > scc[i + m]) ans++;
  printf("%d\n", ans);
  for (int i = 1; i <= m; ++i)
    if (scc[i] > scc[i + m]) printf("%d ", i);
  return 0;
}
